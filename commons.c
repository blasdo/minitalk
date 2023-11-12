/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:14:17 by bvelasco          #+#    #+#             */
/*   Updated: 2023/11/01 18:14:20 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(int errnum)
{
	if (errnum == 1)
		ft_fdprintf(2, "This program must have two (2) arguments\n");
	else if (errnum == 2)
		ft_fdprintf(2, "Timeout\n");
	else if (errnum == 3)
		ft_fdprintf(2, "Cannot allocate memory\n");
	else if (errnum == 4)
		ft_fdprintf(2, "Too many tries\n");
	else
		ft_fdprintf(2, "Error code not found, the code is %i\n", errnum);
	exit(1);
}
