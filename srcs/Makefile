#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshyiata <oshyiata@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/14 12:53:00 by oshyiata          #+#    #+#              #
#    Updated: 2019/01/25 19:00:35 by ishyian          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			fillit
LIB = 			libft.a

SRC =			main.c \
				fillit.c \
				errproc.c \
				read_valid_get_list.c \
				list_tools.c \
				move_crs.c \
				create_incidence_matrix.c \
				get_lnks.c \
				add_lnks.c \
				danceit.c \
				get_next_incidence.c \
				hide_lnks.c \
				restore_lnks.c \
				outputit.c \
				free.c \

LIB_DIR =		../libft/

INCLUDES = 		../fillit.h

OBJ = 			$(SRC:.c=.o)

CC = 			gcc

CFLAGS = 		-Wall -Wextra -Werror

LIBFT =         $(LIB_DIR)libft.a

all: $(NAME)

$(OBJ):%.o: %.c
				$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

$(NAME): 		$(LIBFT) $(OBJ)  
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lft -L $(LIB_DIR)

$(LIBFT):
				make -C $(LIB_DIR)

clean:
				rm -rf $(OBJ)
				@make clean -C $(LIB_DIR)


fclean:			clean
				rm -rf $(NAME)
				@make fclean -C $(LIB_DIR)

re:				fclean all

# vpath %.c .
.PHONY: 		all clean fclean re