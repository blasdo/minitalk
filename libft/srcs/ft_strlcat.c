/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:06:00 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_original_size;

	if (!dstsize && !dst)
		return (0);
	i = ft_strlen(dst);
	dst_original_size = i;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src) + dstsize);
	while (i < dstsize -1 && src[j] != 0)
		dst[i++] = src[j++];
	dst[i] = 0;
	if (dstsize <= ft_strlen(dst))
	{
		return (ft_strlen(src) + dstsize);
	}
	return (dst_original_size + ft_strlen(src));
}
