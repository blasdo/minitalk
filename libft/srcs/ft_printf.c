/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:44:27 by bvelasco          #+#    #+#             */
/*   Updated: 2023/11/01 15:08:48 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_put_fd_bridge(char type, va_list *va, int fd, int nocp)
{
	if (type == '%')
		ft_putchar_fd('%', fd);
	else if (type == 'c')
		ft_putchar_fd(va_arg(*va, int), fd);
	else if (type == 's')
		nocp = ft_putstr_fd(va_arg(*va, char *), fd);
	else if (type == 'p')
		nocp = ft_putptr_fd(va_arg(*va, void *), fd);
	else if (type == 'd' || type == 'i')
		nocp = ft_putlnbr_base_fd(va_arg(*va, int), DEC, fd);
	else if (type == 'u')
		nocp = ft_putulnbr_base_fd(va_arg(*va, unsigned int), DEC, fd);
	else if (type == 'x')
		nocp = ft_putulnbr_base_fd(va_arg(*va, unsigned int), LOW_HEX, fd);
	else if (type == 'X')
		nocp = ft_putulnbr_base_fd(va_arg(*va, unsigned int), UPP_HEX, fd);
	else
	{
		ft_putchar_fd(type, fd);
		nocp = 1;
	}
	if (type == 'c' || type == '%')
		nocp = 1;
	return (nocp);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		counter;
	va_list	vaargs;

	i = 0;
	counter = 0;
	va_start(vaargs, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			counter += ft_put_fd_bridge(format[++i], &vaargs, 1, 0);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i++], 1);
			counter++;
		}
	}
	va_end(vaargs);
	return (counter);
}

int	ft_fdprintf(int fd, const char *format, ...)
{
	int		i;
	int		counter;
	va_list	vaargs;

	i = 0;
	counter = 0;
	va_start(vaargs, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			counter += ft_put_fd_bridge(format[++i], &vaargs, fd, 0);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i++], fd);
			counter++;
		}
	}
	va_end(vaargs);
	return (counter);
}
