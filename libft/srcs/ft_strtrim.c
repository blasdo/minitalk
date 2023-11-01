/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:08:42 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	char			fst_char_index;
	unsigned int	ultimate_char_index;

	if (!s1 || !set)
		return (0);
	i = 0;
	fst_char_index = 0;
	ultimate_char_index = ft_strlen(s1);
	while (s1[i] != 0 && ft_strchr(set, s1[i]))
		i++;
	fst_char_index = i;
	while (ultimate_char_index > i && ft_strchr(set, s1[ultimate_char_index]))
		ultimate_char_index--;
	return (ft_substr(s1, fst_char_index, (ultimate_char_index - (i - 1))));
}
