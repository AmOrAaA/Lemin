##
## Makefile for Makefile in /home/Nyavenger/CPool_Day10/lib/my
## 
## Made by Jonathan Delestre
## Login   <Nyavenger@epitech.net>
## 
## Started on  Fri Oct 14 09:57:29 2016 Jonathan Delestre
## Last update Thu Apr  6 10:20:10 2017 Jonathan Delestre
##

CFLAGS  +=	-I../../include -Wextra -Wall -pedantic

LDFLAGS =

SRC	=	my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_getnbr.c		\
		my_strcmp.c		\
		my_strncpy.c		\
		my_strncmp.c		\
		my_strcat.c		\
		my_strdup.c		\
		printf/my_put_bases.c	\
		printf/my_putnprint.c	\
		printf/my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
