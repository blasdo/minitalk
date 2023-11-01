/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:29:45 by bvelasco          #+#    #+#             */
/*   Updated: 2023/10/02 17:18:42 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	bubblesort_int(int *numbers, size_t len)
{
	size_t	i;
	size_t	max;
	int		*prev;
	int		aux;

	if (!numbers || !len || issorted_int(numbers, len))
		return ;
	max = len;
	while (max > 1)
	{
		i = 1;
		prev = numbers;
		while (i < max)
		{
			if (*prev > numbers[i])
			{
				aux = numbers[i];
				numbers[i] = *prev;
				*prev = aux;
			}
			prev = numbers + i++;;
		}
		max--;
	}
}
