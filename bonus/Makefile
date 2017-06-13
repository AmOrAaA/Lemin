##
## Makefile for Makefile in /home/Nyavenger/CPool_Day10/lib/my
## 
## Made by Jonathan Delestre
## Login   <Nyavenger@epitech.net>
## 
## Started on  Fri Oct 14 09:57:29 2016 Jonathan Delestre
## Last update Sun Apr 30 15:57:51 2017 Florian Testu
##

CFLAGS  +=	-I../include -L../lib/my/ -lmy -L../lib/ -Wextra -Wall -pedantic

LDFLAGS =

SRC	=	map.c	\
		string.c	\
		map/get_next_line.c             \
                map/my_puterr.c                 \
                map/main.c                      \
                map/my_str_to_wordtab.c         \
                map/all_check.c                 \
                map/cmp.c                       \
                map/all_check_end.c             \
                map/take_room.c                 \
                map/my_mod_str_to_wordtab.c     \
                map/coor_check.c		\
		map/all_count.c		\
		map/all_cmp.c		\
		map/print_error_second.c	\
		map/check_end.c		\
		map/print_error.c		\
		choose_direction.c	\
		map/anthill.c		\
		map/ants.c			\
		map/check.c			\
		map/check_path.c		\
		map/lemin.c			\
		map/memory.c		\
		map/my_file.c		\
		map/path.c			\
		map/pathfinding.c		\
		map/print_error_third.c	\
		map/print_error_four.c		\
		room.c				\
		make_path.c			\
		print.c				\
		count_functions.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	lem_in

all:		$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
