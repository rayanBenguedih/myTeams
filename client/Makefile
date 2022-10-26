##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC_CLIENT =		main.c \
					error.c \
					strlen_net.c \
					launch.c \
					communication.c \
					./commands/command_handing.c \
					./commands/correct_command.c \
					./commands/correct_help.c \
					./commands/correct_create.c \
					./commands/correct_info.c \
					./commands/correct_list.c \
					./commands/correct_login.c \
					./commands/correct_logout.c \
					./commands/correct_messages.c \
					./commands/correct_send.c \
					./commands/correct_subscribe.c \
					./commands/correct_subscribed.c \
					./commands/correct_unsubscribe.c \
					./commands/correct_use.c \
					./commands/correct_user.c \
					./commands/correct_users.c \
					./fct_logger/call_logger.c \
					./fct_logger/channel_created.c \
					./fct_logger/log_in.c \
					./fct_logger/log_out.c \
					./fct_logger/logger.c \
					./fct_logger/private_message.c \
					./fct_logger/thread_reply.c \
					./fct_logger/thread_created.c \
					./fct_logger/print_users.c \
					./fct_logger/team_created.c \
					./fct_logger/print_teams.c \
					./fct_logger/print_channels.c \
					./fct_logger/print_threads.c \
					./fct_logger/print_replies.c \
					./fct_logger/print_user.c \
					./fct_logger/print_team.c \
					./fct_logger/print_channel.c \
					./fct_logger/print_thread.c \
					./fct_logger/print_team_created.c \
					./fct_logger/print_channel_created.c \
					./fct_logger/print_thread_created.c \
					./fct_logger/print_thread_reply_created.c \
					./fct_logger/print_subscribed.c \
					./fct_logger/print_unsubscribed.c \
					./fct_logger/private_msg_print_msg.c \

OBJ_CLIENT =		$(SRC_CLIENT:.c=.o)

LIBS = 				-L/libs/myteams/ -Wl,-rpath=/libs/myteams/ -lmyteams

MY_LIB =			-L/libs/my/ -Wl,-rpath=/libs/my/ -lmy

NAME_CLIENT =		myteams_cli

CFLAGS =			-Iinclude

DEBUGFLAGS = 		-g

all:	$(NAME_CLIENT)

$(NAME_CLIENT):	$(OBJ_CLIENT)
			make -sC ../libs/my/ all
			make -sC ../libs/my/ clean
			gcc -o $(NAME) $(SRC) $(CFLAGS) ${LIBS} ${MY_LIB}

debug:
			make -sC ../libs/my/ all
			make -sC ../libs/my/ clean
			gcc -o $(NAME) $(SRC) $(CFLAGS) ${LIBS} ${MY_LIB} $(DEBUGFLAGS)

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME)

re:			fclean all
