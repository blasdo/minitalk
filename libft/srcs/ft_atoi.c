/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:46:20 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:30:33 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;

	sign = 0;
	res = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if (sign == 0)
			res = (res * 10) + (*(nptr++) - '0');
		else
			res = (res * 10) - (*(nptr++) - '0');
	}
	return (res);
}
