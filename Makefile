# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 11:29:00 by afiat-ar          #+#    #+#              #
#    Updated: 2021/08/18 08:41:22 by afiat-ar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

all :
	make -C libft
	gcc -Wall -Wextra -Werror -ggdb -fsanitize=address -fno-omit-frame-pointer server.c libft/libft.a -o $(NAME1)
	gcc -Wall -Wextra -Werror -ggdb -fsanitize=address -fno-omit-frame-pointer client.c libft/libft.a -o $(NAME2)

clean :
	make clean -C libft 
	rm -rf client.o server.o

fclean : clean
	make fclean -C libft
	rm -rf $(NAME1) $(NAME2)

re : fclean all
