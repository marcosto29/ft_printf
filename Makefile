# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matoledo <matoledo@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 11:50:12 by matoledo          #+#    #+#              #
#    Updated: 2025/04/29 13:15:55 by matoledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = 

NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
EXE = main

SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

exe: $(EXE)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(EXE): $(OBJS) $(NAME)
	$(CC) -o $(EXE) $(OBJS) -L. -l:$(NAME) -L$(LIBFT_DIR) -l:$(LIBFT_NAME)

clean:
	rm -rf $(OBJS)

#$(MAKE) is used to execute the command make, to acces a directory with -C
#and the directroy to acces where the make command is gonna execute
#$(MAKE) can be combined with other commands like clean
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(EXE)

re: fclean all