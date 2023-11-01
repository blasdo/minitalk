/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:26:32 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:16 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_unumlen_base(unsigned long lnbr, unsigned long base_len)
{
	size_t	i;

	i = 0;
	if (lnbr == 0)
		return (1);
	while (lnbr)
	{
		lnbr /= base_len;
		i++;
	}
	return (i);
}
