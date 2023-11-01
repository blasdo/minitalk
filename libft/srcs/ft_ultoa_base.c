/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:25:40 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:21 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_ultoa_base(unsigned long lnbr, char *base)
{
	size_t	base_len;
	char	*ret;
	int		index;

	base_len = ft_strlen(base);
	index = ft_unumlen_base(lnbr, base_len);
	ret = malloc(index + 1);
	if (!ret)
		return (0);
	if (lnbr == 0)
		ret[0] = '0';
	ret[index--] = 0;
	while (lnbr)
	{
		ret[index--] = base[lnbr % base_len];
		lnbr /= base_len;
	}
	return (ret);
}
