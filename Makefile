##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	gcc -Iinclude/

CFLAGS +=	-Wall

RM	=	rm -f

NAME	=	ai

SRC	=	./src/putstr.c		\
		./src//stkstr.c		\
		./src//isfloat.c	\
		./src//str_to_wordtab.c \
		./src//get_next_line.c	\
		./src/scan.c		\
		./src/move.c		\
		./src/main.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) src/*#
	$(RM) src/*~
	$(RM) src/include/*~
	$(RM) src/include/*#
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
