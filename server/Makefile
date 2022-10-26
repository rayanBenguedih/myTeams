##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC =		server/main.c 			 			\
			server/error.c			 			\
			server/start.c			 			\
			server/initialisation.c 			\
			server/linkedlist.c 	 			\
			server/handler_request.c			\
			server/command_execution.c 		\
			server/more_data_handler.c 		\
			server/more_listers.c 				\
			server/push_backs_complements.c 	\
			server/push_backs.c 				\
			server/use.c 						\
			server/lister.c 					\
			server/functions_complementaries.c \
			server/extra_callers.c 			\
			server/decider.c 					\
			server/data_creators.c 			\
			server/commands_callers.c			\
			server/create.c					\
			server/save.c						\
			server/subscribed_teams_manager.c \
			server/evenmore_lister.c	\
			server/even_more_files.c \
			server/more_data_crst.c \

OBJ =		$(SRC:.c=.o)

LIBS = 		-L../libs/myteams/ -Wl,-rpath=../libs/myteams/ -lmyteams

MY_LIB =	-L../libs/my/ -Wl,-rpath=../libs/my/ -lmy

NAME =		myteams_server

CFLAGS =	-Iinclude -luuid

DEBUGFLAGS = -g

all:	$(NAME)

$(NAME):	$(OBJ)
			make -sC ../libs/my/ all
			make -sC ../libs/my/ clean
			gcc -o $(NAME) $(OBJ) $(CFLAGS) ${LIBS} ${MY_LIB}
			if ! test -d Teams; then mkdir Teams; fi
			if ! test -d Users; then mkdir Users; fi

debug:
			make -sC ../libs/my/ all
			make -sC ../libs/my/ clean
			gcc -o $(NAME) $(SRC) $(CFLAGS) ${LIBS} ${MY_LIB} $(DEBUGFLAGS)

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME)

re:			fclean all
