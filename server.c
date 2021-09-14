/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:54:51 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/08/23 12:11:36 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_msg	g_msg;

void	ft_get_pid(void)
{
	pid_t	pid_id;

	pid_id = getpid();
	ft_putstr_fd("\033[0;32mServer PID -> \033[0;35m", 1);
	ft_putnbr_fd(pid_id, 1);
	ft_putstr_fd("\033[0;37m\n", 1);
}

void	ft_get_data(int bit)
{
	g_msg.c += ((bit & 1) << g_msg.size);
	g_msg.size++;
	if (g_msg.size == 7)
	{
		ft_putchar_fd(g_msg.c, 1);
		if (!g_msg.c)
			ft_putchar_fd('\n', 1);
		g_msg.size = 0;
		g_msg.c = 0;
	}
}

int	main(int argc, char *argv[])
{
	argv = NULL;
	if (argc != 1)
	{
		ft_putstr_fd("\033[0;31mERROR\n\033[0;32mUsage: ./server\033[0;37m", 1);
		return (1);
	}
	g_msg.c = 0;
	g_msg.size = 0;
	ft_get_pid();
	while (1)
	{
		signal(SIGUSR2, ft_get_data);
		signal(SIGUSR1, ft_get_data);
		pause();
	}
	return (0);
}
