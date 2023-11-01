/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <bvelasco@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:16:35 by bvelasco          #+#    #+#             */
/*   Updated: 2023/09/24 01:37:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_putnbr_fd_without_0(int n, int fd)
{
	char	to_print;

	if (n < 0)
	{
		to_print = ((n % 10) * -1) + '0';
		write(fd, "-", 1);
		ft_putnbr_fd_without_0((n / 10) * -1, fd);
		write(fd, &to_print, 1);
	}
	else if (!n)
		to_print = 0;
	else if (n > 0)
	{
		to_print = (n % 10) + '0';
		ft_putnbr_fd_without_0((n / 10), fd);
		write(fd, &to_print, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else
		ft_putnbr_fd_without_0(n, fd);
}
