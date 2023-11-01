/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:11:08 by bvelasco          #+#    #+#             */
/*   Updated: 2023/10/01 16:38:00 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isspace(int c)
{
	unsigned char	c_c;

	c_c = (unsigned char) c;
	if (c_c == ' ' || c_c == '\t' || c_c == '\n' || c_c == '\v' || \
	c_c == '\f' || c_c == '\r')
		return (1);
	return (0);
}
