##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile lib
##

SRC =		function_socket.c \

OBJ	=		$(SRC:.c=.o)

NAME =		libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:	$(OBJ)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
