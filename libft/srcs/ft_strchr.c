/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:50:40 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_c;

	c_c = (char) c;
	i = 0;
	if (c_c == 0)
		return ((char *) s + ft_strlen(s));
	while (s[i] != 0)
	{
		if (s[i] == c_c)
		{
			return ((char *) s + i);
		}
		i++;
	}
	return (0);
}
