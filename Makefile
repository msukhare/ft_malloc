# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msukhare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 15:51:13 by msukhare          #+#    #+#              #
#    Updated: 2019/12/03 17:22:41 by msukhare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/

SRC_NAME = malloc.c

OBJ_PATH = objs/

CPPFLAGS = -I include/ -I libft/include/

NAME = libft_malloc.so

CC = gcc

MK = make -C

SRCLFT = libft/

LFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

DYNAMIC = -shared

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(LFT) $(NAME)

$(LFT):
	$(MK) $(SRCLFT)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(DYNAMIC) -o $(NAME) $(CPPFLAGS) -fPIC $(OBJ) $(LFT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C $(SRCLFT)
	@rm -vf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C $(SRCLFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
