/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:14:27 by bvelasco          #+#    #+#             */
/*   Updated: 2023/11/03 00:37:30 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_signal_verifier = 1;

void	signal_reciver(int sigint)
{
	if (sigint == g_signal_verifier)
		g_signal_verifier = 0;
}

void	force_server_timeout(void)
{
	g_signal_verifier = 35;
	usleep(100000);
	if (g_signal_verifier != 35)
		force_server_timeout();
}

int	send_byte(int pid, t_byte b)
{
	int	sent_bits;

	sent_bits = 0;
	while (sent_bits < 8)
	{
		if (b >= 128)
		{
			kill(pid, SIGUSR2);
			g_signal_verifier = SIGUSR2;
		}
		else
		{
			kill(pid, SIGUSR1);
			g_signal_verifier = SIGUSR1;
		}
		usleep(50000);
		if (g_signal_verifier)
			return (1);
		sent_bits++;
		b <<= 1;
	}
	return (0);
}

void	send_msg(int pid, char *msg)
{
	static int	tries = 0;
	int			i;
	int			verifier;

	i = 0;
	while (msg[i])
	{
		verifier = send_byte(pid, msg[i++]);
		if (verifier == 1)
		{
			if (tries < 5)
			{
				ft_printf("Failed to send message try %i\n", ++tries);
				force_server_timeout();
			}
			else
				error(2);
			i = 0;
		}
	}
	if (send_byte(pid, 0) == 1 && ++tries)
	{
		force_server_timeout();
		send_msg(pid, msg);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	sigset_t			usr;

	sigemptyset(&usr);
	sigaddset(&usr, SIGUSR1);
	sigaddset(&usr, SIGUSR2);
	sa.sa_handler = signal_reciver;
	sa.sa_mask = usr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
	{
		error(1);
	}
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (0);
}
