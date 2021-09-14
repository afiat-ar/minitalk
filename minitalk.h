/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:13:49 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/09/13 16:28:47 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_msg
{
	char	c;
	size_t	size;
}	t_msg;

#endif
