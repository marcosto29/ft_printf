# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 11:50:12 by matoledo          #+#    #+#              #
#    Updated: 2025/04/24 11:59:01 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS = libft

NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = (SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBS)
	ar -r $(NAME) ($OBJS)

$(LIBS)
	cd $(LIBS) && make
