/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:20:02 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putptr_fd(void *ptr, int fd)
{
	int				rtn;
	unsigned long	lng;

	rtn = 0;
	lng = (unsigned long) ptr;
	rtn += ft_putstr_fd("0x", fd);
	rtn += ft_putulnbr_base_fd(lng, LOW_HEX, fd);
	return (rtn);
}
