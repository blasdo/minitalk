/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:20:54 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_numlen_base(long long lnbr, long long base_len)
{
	int	i;

	i = 0;
	if (lnbr < 0)
		i = 1;
	if (lnbr == 0)
		return (1);
	while (lnbr)
	{
		lnbr /= base_len;
		i++;
	}
	return (i);
}
