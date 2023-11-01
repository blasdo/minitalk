/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:50:35 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:32:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_bzero(void *b, size_t len)
{
	size_t	i;
	char	*bchar;

	i = 0;
	bchar = (char *) b;
	while (i < len)
		bchar[i++] = 0;
	return (b);
}
