/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:54:45 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/08/23 12:11:39 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_data(int pid, char *msg, size_t len)
{
	size_t	i;
	int		byte;

	i = 0;
	while (i < len)
	{
		byte = 0;
		while (byte < 7)
		{	
			if ((msg[i] >> byte) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			byte++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_send_data(pid, argv[2], ft_strlen(argv[2]));
		ft_send_data(pid, "\n", 1);
		return (0);
	}
	else
	{
		ft_putstr_fd("\033[0;31mERROR\n\033[0;32m", 1);
		ft_putstr_fd("Usage: ./client [pid_id] [string]\033[0;37m\n", 1);
		return (1);
	}
}
