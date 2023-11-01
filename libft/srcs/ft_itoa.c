/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:57:58 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	num_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	else if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	nl;
	char	*rtn;

	nl = num_len(n);
	i = nl;
	rtn = malloc(nl + 1);
	if (!rtn)
		return (0);
	if (n < 0)
		rtn[0] = '-';
	if (!n)
		rtn[0] = '0';
	while (n)
	{
		if (n > 0)
			rtn[--i] = (n % 10) + '0';
		else
			rtn[--i] = ((n % 10) * -1) + '0';
		n /= 10;
	}
	rtn[nl] = 0;
	return (rtn);
}
