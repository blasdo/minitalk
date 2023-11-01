/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:10:06 by bvelasco          #+#    #+#             */
/*   Updated: 2023/10/01 16:50:26 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	issorted_int(int *numbers, size_t len)
{
	size_t	i;
	int		prev;

	i = 0;
	if (!len || !numbers)
		return (0);
	prev = numbers[i++];
	while (i < len)
	{
		if (prev > numbers[i])
			return (0);
		prev = numbers[i++];
	}
	return (1);
}
