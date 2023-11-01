/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:01:22 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/26 12:57:27 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_bufflist	*newbuff(t_bufflist *last, int fd)
{
	t_bufflist	*tortn;

	tortn = malloc(sizeof(t_bufflist));
	if (!tortn)
		return (0);
	tortn->readrtn = read(fd, tortn->buff, BUFFER_SIZE);
	if (tortn->readrtn < 0)
	{
		free(tortn);
		return (0);
	}
	tortn->next = 0;
	if (last)
		last->next = tortn;
	return (tortn);
}

void	*freebuff(t_bufflist **bufflist)
{
	t_bufflist	*temp;

	while (*bufflist)
	{
		temp = (*bufflist)->next;
		free(*bufflist);
		*bufflist = temp;
	}
	*bufflist = 0;
	return (0);
}

size_t	char_count_buff(t_bufflist	*first)
{
	size_t	counter;
	size_t	j;
	size_t	max;
	char	*current_buff;

	j = 0;
	counter = 0;
	if (!first)
		return (0);
	while (first->next)
	{
		counter += first->readrtn;
		first = first->next;
	}
	max = first->readrtn;
	current_buff = first->buff;
	while (j < max && current_buff[j] != '\n')
		j++;
	if (current_buff[j] == '\n')
		j++;
	counter += j;
	return (counter);
}

void	clearbuff(t_bufflist **list)
{
	char		*first_nl;
	t_bufflist	*temp;

	first_nl = 0;
	while (*list && !first_nl)
	{
		first_nl = findnl(*list);
		if (!first_nl)
		{
			temp = (*list)->next;
			free (*list);
			*list = temp;
		}
	}
	if (first_nl)
	{
		if (first_nl == (*list)->buff + (*list)->readrtn - 1)
		{
			free(*list);
			*list = 0;
		}
		else
			ft_bzero((*list)->buff, first_nl + 1 - (*list)->buff);
	}
}

char	*get_next_line(int fd)
{
	static t_bufflist	*bufflist = NULL;
	t_bufflist			*last;
	char				*line;

	if (!bufflist)
		bufflist = newbuff(0, fd);
	if (bufflist && bufflist->readrtn == 0)
	{
		free(bufflist);
		bufflist = 0;
		return (0);
	}
	last = bufflist;
	while (last != 0 && (!findnl(last) && last->readrtn == BUFFER_SIZE))
		last = newbuff(last, fd);
	if (!last)
		return (freebuff(&bufflist));
	line = bufflist_to_str(bufflist);
	clearbuff(&bufflist);
	return (line);
}
