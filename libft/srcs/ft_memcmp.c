/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:47:13 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*c_s1;
	char	*c_s2;

	c_s1 = (char *) s1;
	c_s2 = (char *) s2;
	i = 0;
	while (i < n)
	{
		if (c_s1[i] != c_s2[i])
		{
			return ((unsigned char) c_s1[i] - (unsigned char) c_s2[i]);
		}
		i++;
	}
	return (0);
}
