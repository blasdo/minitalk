/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:56:01 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/26 13:03:11 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*findnl(t_bufflist *buff)
{
	int	i;
	int	max;

	i = 0;
	if (buff == 0)
		return (0);
	max = buff->readrtn;
	while (i < max)
	{
		if (buff->buff[i] == '\n')
			return ((buff->buff) + i);
		i++;
	}
	return (0);
}

char	*bufflist_to_str(t_bufflist *bufflist)
{
	int		counters[2];
	int		limit;
	char	*str;

	str = malloc(char_count_buff(bufflist) + 1);
	if (!bufflist || !str)
		return (free(str), NULL);
	counters[0] = 0;
	while (bufflist)
	{
		counters[1] = 0;
		limit = bufflist->readrtn;
		while (counters[1] < limit && bufflist->buff[counters[1]] == '\0')
			counters[1]++;
		while (counters[1] < limit && bufflist->buff[counters[1]] != '\n')
			str[counters[0]++] = bufflist->buff[counters[1]++];
		if (bufflist->buff[counters[1]] == '\n')
		{
			str[counters[0]++] = bufflist->buff[counters[1]++];
			break ;
		}
		bufflist = bufflist->next;
	}
	str[counters[0]] = '\0';
	return (str);
}

void	*ft_bzero(void *b, size_t len)
{
	size_t	i;
	char	*bchar;

	i = 0;
	bchar = (char *) b;
	while (i < len)
		bchar[i++] = 0;
	return (b);
}
