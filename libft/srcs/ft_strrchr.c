/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:00:36 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;
	char	c_c;

	c_c = (char) c;
	result = 0;
	i = 0;
	if (c_c == 0)
		return ((char *) s + ft_strlen(s));
	while (s[i] != 0)
	{
		if (s[i] == c_c)
		{
			result = (char *) s + i;
		}
		i++;
	}
	return (result);
}
