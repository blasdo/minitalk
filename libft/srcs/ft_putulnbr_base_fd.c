/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulnbr_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:46:34 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_putulnbr_base_fd(unsigned long nbr, char *base, int fd)
{
	char	*toprint;
	int		printed;

	toprint = ft_ultoa_base(nbr, base);
	if (!toprint)
		return (0);
	printed = ft_strlen(toprint);
	write(fd, toprint, printed);
	free(toprint);
	return (printed);
}
