/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvelasco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:12:38 by bvelasco          #+#    #+#             */
/*   Updated: 2023/11/01 18:14:12 by bvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO3_H
# define PROTO3_H
# include <libft.h>
# include <signal.h>
typedef unsigned char	t_byte;
typedef struct s_messageinfo
{
	int		client_pid;
	int		bytes;
	t_byte	timeout;
}				t_mi;
void	error(int errnum);

#endif
