/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:34:06 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*rtn;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	rtn = malloc(len + 1);
	if (!rtn)
		return (0);
	while (i < len)
	{
		rtn[i] = (*f)((unsigned int) i, s[i]);
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
