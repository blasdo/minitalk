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

int	g_signal_verified = 0;

void	signal_reciver(int sigint)
{
	if (sigint != g_signal_verified)
		g_signal_verified = 0;
}

void	force_server_timeout(void)
{
	g_signal_verified = 35;
	usleep(52000);
	if (g_signal_verified != 35)
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
			g_signal_verified = SIGUSR2;
		}
		else
		{
			kill(pid, SIGUSR1);
			g_signal_verified = SIGUSR2;
		}
		usleep(10000);
		if (!g_signal_verified)
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
		if (!verifier)
		{
			if (tries < 3)
			{
				ft_printf("Failed to verify message try %i", ++tries);
				force_server_timeout();
			}
			else
				error(4);
			i = 0;
		}
	}
	while (send_byte(pid, 0) && ++tries)
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
