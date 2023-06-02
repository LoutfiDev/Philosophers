# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 11:36:32 by yloutfi           #+#    #+#              #
#    Updated: 2023/06/02 15:34:15 by yloutfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3
CC = cc

SRCS = philo.c ft_split.c parsing_functions.c libft_functions.c init.c	\
	helpers.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -g $(CFLAGS) $(OBJS) -o $(NAME) 

clean :
	-rm -f $(OBJS)
		
fclean : clean
	-rm -f $(NAME)

re : fclean	all

.PHONY: all clean fclean re