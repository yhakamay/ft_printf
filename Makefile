# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhakamaya <yhakamaya@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 21:46:47 by yhakamaya         #+#    #+#              #
#    Updated: 2021/01/25 18:27:28 by yhakamaya        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= gcc
SRCS_DIR	= ./srcs
SRCS		= \
			 $(SRCS_DIR)/digit_counters.c \
			 $(SRCS_DIR)/ft_printf.c \
			 $(SRCS_DIR)/init.c \
			 $(SRCS_DIR)/ptf_utils.c \
			 $(SRCS_DIR)/put_utils.c \
			 $(SRCS_DIR)/putters_hex.c \
			 $(SRCS_DIR)/putters_num_two.c \
			 $(SRCS_DIR)/putters_num.c \
			 $(SRCS_DIR)/putters_other.c \
			 $(SRCS_DIR)/putters_pointer.c \
			 $(SRCS_DIR)/putters_str.c \
			 $(SRCS_DIR)/putters_u.c \
			 $(SRCS_DIR)/treat_acc_field.c
OBJS		= $(SRCS:.c=.o)
INCLUDES	= -I./includes
CFLAGS		= -Wall -Wextra -Werror $(INCLUDES)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
