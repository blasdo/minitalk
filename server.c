/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:14:03 by bvelasco          #+#    #+#             */
/*   Updated: 2023/11/03 00:43:43 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_list	*g_list = 0;

void	init_message(siginfo_t *info)
{
	t_mi	*message_info;

	message_info = malloc(sizeof(t_mi));
	if (!message_info)
		error(3);
	message_info->client_pid = info->si_pid;
	message_info->bytes = 0;
	if (g_list)
		ft_lstclear(&g_list, free);
	g_list = ft_lstnew(message_info);
	if (!g_list)
		error(3);
}

void	printmsg(void)
{
	char	*msg;
	int		bytes;
	t_list	*tmp;
	t_list	*last;
	int		i;

	i = 0;
	last = g_list->next;
	bytes = ((t_mi *)g_list->content)->bytes;
	msg = malloc(bytes);
	if (!msg)
		error(3);
	while (i < bytes)
	{
		msg[i++] = *((char *) last->content);
		tmp = last->next;
		last = tmp;
	}
	write(1, msg, bytes - 1);
	write(1, "\n", 1);
	free(msg);
	ft_lstclear(&g_list, free);
}

void	add_byte(t_byte byte)
{
	t_byte	*byte_ptr;
	t_list	*new;

	byte_ptr = malloc(1);
	if (byte_ptr)
	{
		*byte_ptr = byte;
		new = ft_lstnew(byte_ptr);
		if (new)
		{
			ft_lstadd_back(&g_list, new);
			((t_mi *) g_list->content)->bytes += 1;
			if (!byte)
				printmsg();
			return ;
		}
		free(byte_ptr);
	}
	ft_lstclear(&g_list, free);
	error(3);
}

void	recive_byte(int signum, siginfo_t *info, void *previous_act)
{
	static int		bw = 0;
	static t_byte	current = 0;

	if (!g_list)
		init_message(info);
	if (info->si_pid != ((t_mi *)(g_list->content))->client_pid)
	{
		kill(info->si_pid, SIGUSR2);
		return ;
	}
	((t_mi *)g_list->content)->timeout = 0;
	if (signum == SIGUSR2)
		current += 1;
	if (++bw >= 8)
	{
		bw = 0;
		add_byte(current);
		current = 0;
	}
	current <<= 1;
	usleep(500);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			usr;
	char				*input_line;
	void				*tmp;

	ft_printf("%i\n", getpid());
	sigemptyset(&usr);
	sigaddset(&usr, SIGUSR1);
	sigaddset(&usr, SIGUSR2);
	sa.sa_sigaction = recive_byte;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = usr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		if (g_list)
			((t_mi *) g_list->content)->timeout = 1;
		usleep(500000);
		if (g_list && ((t_mi *) g_list->content)->timeout == 1)
			ft_lstclear(&g_list, free);
	}
	return (0);
}
