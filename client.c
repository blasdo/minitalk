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
	g_signal_verified = 0;
	if (sigint == SIGUSR1)
		g_signal_verified = 1;
}

void	send_byte(int pid, t_byte b)
{
	int	sent_bits;

	sent_bits = 0;
	while (sent_bits < 8)
	{
		if (b >= 128)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(10000);
		if (!g_signal_verified)
		{
			error(2);
			continue ;
		}
		sent_bits++;
		b <<= 1;
	}
}

void	send_msg(int pid, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
		send_byte(pid, msg[i++]);
	send_byte(pid, 0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	sigset_t			usr;

	sigemptyset(&usr);
	sigaddset(&usr, SIGUSR1);
	sigaddset(&usr, SIGUSR2);
	sa.sa_handler = signal_reciver;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
	{
		error(1);
	}
	send_msg(ft_atoi(argv[1]), argv[2]);
	return (0);
}
