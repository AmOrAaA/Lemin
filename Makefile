##
## Makefile for Makefile in /home/Nyavenger/CPool_Day10/lib/my
## 
## Made by Jonathan Delestre
## Login   <Nyavenger@epitech.net>
## 
## Started on  Fri Oct 14 09:57:29 2016 Jonathan Delestre
## Last update Sun Apr 30 02:45:16 2017 Florian Testu
##

CFLAGS  +=	-I./include -L./lib/my/ -lmy -L./lib/ -Wextra -Wall -pedantic

LDFLAGS =

SRC	=	src/get_next_line.c		\
		src/my_puterr.c			\
		src/main.c			\
		src/my_str_to_wordtab.c		\
		src/all_check.c			\
		src/cmp.c			\
		src/all_check_end.c		\
		src/take_room.c			\
		src/my_mod_str_to_wordtab.c	\
		src/coor_check.c		\
		src/all_count.c			\
		src/all_cmp.c			\
		src/lemin.c			\
		src/memory.c			\
		src/anthill.c			\
		src/path.c			\
		src/pathfinding.c		\
		src/ants.c			\
		src/print_error.c		\
		src/print_error_second.c	\
		src/check_end.c			\
		src/my_file.c			\
		src/check.c			\
		src/print_error_third.c		\
		src/print_error_four.c		\
		src/check_path.c

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
