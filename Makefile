# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 13:21:22 by hulefevr          #+#    #+#              #
#    Updated: 2024/06/04 17:27:11 by hulefevr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./src/lib/ft_putnbr_long.c \
		./src/lib/str_digit.c \
		./src/lib/ft_strerror.c \
		./src/lib/ft_put_msg.c \
		./src/lib/ft_atoi.c \
		./src/ft_create_philo.c \
		./src/act/ft_eat.c \
		./src/act/ft_sleep.c \
		./src/ft_time.c \
		./src/philo.c \

NAME = philo

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

CC = gcc

RM = rm -f

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re