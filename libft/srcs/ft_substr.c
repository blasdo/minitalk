/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:09:05 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*rtn;

	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
	{
		rtn = malloc(1);
		if (rtn == 0)
			return (0);
		rtn[0] = 0;
		return (rtn);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	rtn = malloc(len + 1);
	if (rtn == 0)
		return (0);
	ft_strlcpy(rtn, s + start, len + 1);
	return (rtn);
}
