# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yloutfi <yloutfi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 11:36:32 by yloutfi           #+#    #+#              #
#    Updated: 2023/05/16 16:10:25 by yloutfi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo_bonus
CFLAGS = -Wall -Wextra -Werror 
CC = cc

SRCS = philo_bonus.c

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