/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:14:04 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*c_dst;
	char	*c_src;

	c_dst = (char *) dst;
	c_src = (char *) src;
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		i = len - 1;
		while (i >= 0)
		{
			c_dst[i] = c_src[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
