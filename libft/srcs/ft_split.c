/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:44:33 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	**clean_split(char **to_clean)
{
	int	i;

	i = 0;
	while (to_clean[i])
	{
		free (to_clean[i++]);
	}
	free (to_clean);
	return (0);
}

static size_t	count_words(char const *s, char c)
{
	int	i;
	int	in_word;
	int	now;

	now = 0;
	i = 0;
	in_word = 0;
	while (s[i] != 0)
	{
		if (!in_word && s[i] != c)
		{
			in_word = 1;
			now++;
		}
		else if (in_word && s[i] == c)
			in_word = 0;
		i++;
	}
	return (now);
}

static size_t	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		now;
	int		low;
	char	**rtn;

	if (!s)
		return (0);
	i = 0;
	now = count_words(s, c);
	rtn = ft_calloc((now + 1), sizeof(char *));
	if (rtn == 0)
		return (0);
	while (i < now)
	{
		while (*s == c)
			s++;
		low = word_len(s, c);
		rtn[i] = ft_substr(s, 0, low);
		if (rtn[i++] == 0)
			return (clean_split(rtn));
		while (*(s + low) == c)
			low++;
		s += low;
	}
	return (rtn);
}
