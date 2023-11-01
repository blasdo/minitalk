/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:23:56 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;

	if (!s1 || !s2)
		return (0);
	if ((ft_strlen(s1) + ft_strlen(s2)) != 0)
	{
		rtn = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (rtn == 0)
			return (0);
		ft_strlcpy(rtn, s1, -1);
		ft_strlcat(rtn, s2, -1);
	}
	else
	{
		rtn = malloc(1);
		if (rtn == 0)
			return (0);
		rtn[0] = 0;
	}
	return (rtn);
}
