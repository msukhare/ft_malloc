# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msukhare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 15:51:13 by msukhare          #+#    #+#              #
#    Updated: 2020/02/19 07:13:09 by msukhare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/

SRC_NAME = malloc.c\
	   chunks_management.c\
	   heaps_allocation.c\
	   free.c\
	   realloc.c\
	   show_alloc_mem.c\

OBJ_PATH = objs/

CPPFLAGS = -I include/ -I libft/include/

LIB_NAME = ft_malloc
NAME = lib$(LIB_NAME).so

CC = gcc

MK = make -C

SRCLFT = libft/

LFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

DYNAMIC = -shared

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

FULL_NAME = lib$(LIB_NAME)_$(HOSTTYPE).so

all: $(LFT) $(NAME)

$(NAME): $(FULL_NAME)
	ln -fs $< $@

$(FULL_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(DYNAMIC) -o $(FULL_NAME) $(OBJ) $(LFT)

$(LFT):
	$(MK) $(SRCLFT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -fPIC -o $@ -c $<

clean:
	make clean -C $(SRCLFT)
	@rm -vf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C $(SRCLFT)
	rm -f $(NAME) $(FULL_NAME)

re: fclean all

.PHONY: all, clean, fclean, re
