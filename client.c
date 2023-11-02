/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:14:27 by bvelasco          #+#    #+#             */
/*   Updated: 2023/11/02 17:15:54 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	signal_verified = 0;

void wait150ms(void)
{
	usleep(150000);
}

void	signal_reciver(int sigint)
{
	if (sigint == SIGUSR1)
		signal_verified = 1;
	else if (sigint == SIGUSR2)
	{
		signal_verified = 0;
		wait150ms();
	}
}
void send_byte(int pid, t_byte b)
{
	int tries;
	int sent_bits;

	sent_bits = 0;
	while (sent_bits < 8)
	{
		if (b >= 128)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		signal_verified = 0;
		sleep(5);
		if (!signal_verified)
		{
			error(2);
			continue;
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
	char				*line;
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
