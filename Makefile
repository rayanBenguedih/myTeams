##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC_S =					server/main.c 			 						\
						server/error.c			 						\
						server/start.c			 						\
						server/initialisation.c 						\
						server/linkedlist.c 	 						\
						server/handler_request.c						\
						server/command_execution.c 						\
						server/more_data_handler.c 						\
						server/more_listers.c 							\
						server/push_backs_complements.c 				\
						server/push_backs.c 							\
						server/use.c 									\
						server/lister.c 								\
						server/functions_complementaries.c 				\
						server/extra_callers.c 							\
						server/decider.c 								\
						server/data_creators.c 							\
						server/commands_callers.c						\
						server/create.c									\
						server/save.c									\
						server/subscribed_teams_manager.c 				\
						server/evenmore_lister.c						\
						server/even_more_files.c 						\
						server/more_data_crst.c 						\
						server/linkedlist_more.c 						\
						server/linkedlis_one.c 							\
						server/linkedlist_two.c 						\
						server/additional_linkedlist.c 					\
						server/use_extra.c 								\
						server/extra_extracallers.c 					\

SRC_C =					client/main.c 									\
						client/error.c 									\
						client/strlen_net.c 							\
						client/launch.c 								\
						client/communication.c 							\
						client/quit.c 									\
						client/reconnexion.c 							\
						client/handle_correct_socket.c 					\
						client/commands/command_handing.c 				\
						client/commands/correct_command.c 				\
						client/commands/correct_help.c 					\
						client/commands/correct_create.c 				\
						client/commands/correct_info.c 					\
						client/commands/correct_list.c 					\
						client/commands/correct_login.c 				\
						client/commands/correct_logout.c 				\
						client/commands/correct_messages.c 				\
						client/commands/correct_send.c 					\
						client/commands/correct_subscribe.c 			\
						client/commands/correct_subscribed.c 			\
						client/commands/correct_unsubscribe.c 			\
						client/commands/correct_use.c 					\
						client/commands/correct_user.c 					\
						client/commands/correct_users.c 				\
						client/fct_logger/call_logger.c 				\
						client/fct_logger/channel_created.c 			\
						client/fct_logger/log_in.c 						\
						client/fct_logger/log_out.c 					\
						client/fct_logger/logger.c 						\
						client/fct_logger/private_message.c 			\
						client/fct_logger/thread_reply.c 				\
						client/fct_logger/thread_created.c 				\
						client/fct_logger/print_users.c 				\
						client/fct_logger/team_created.c 				\
						client/fct_logger/print_teams.c 				\
						client/fct_logger/print_channels.c 				\
						client/fct_logger/print_threads.c 				\
						client/fct_logger/print_replies.c 				\
						client/fct_logger/print_user.c 					\
						client/fct_logger/print_team.c 					\
						client/fct_logger/print_channel.c 				\
						client/fct_logger/print_thread.c 				\
						client/fct_logger/print_team_created.c 			\
						client/fct_logger/print_channel_created.c 		\
						client/fct_logger/print_thread_created.c 		\
						client/fct_logger/print_thread_reply_created.c 	\
						client/fct_logger/print_subscribed.c 			\
						client/fct_logger/print_unsubscribed.c 			\
						client/fct_logger/private_msg_print_msg.c 		\

OBJ_SERVER =			$(SRC_S:.c=.o)

OBJ_CLIENT =			$(SRC_C:.c=.o)

LIBS = 					-Llibs/myteams/ -lmyteams

MY_LIB =				-Llibs/my/ -lmy

NM_S =			myteams_server

NM_C =			myteams_cli

CF_SV =			-Iserver/include -luuid -lm

CF_CL =			-Iclient/include -luuid -lm

LB_I = 			-Ilibs/my -Ilibs/myteams

DF = 			-g

all:	$(NM_S) $(NM_C)

$(NM_S):	$(OBJ_SERVER)
			make -sC libs/my/ all
			make -sC libs/my/ clean
			gcc -o $(NM_S) $(OBJ_SERVER) $(CF_SV) ${LB_I} ${LIBS} ${MY_LIB}
			if ! test -d Teams; then mkdir Teams; fi
			if ! test -d Users; then mkdir Users; fi

$(NM_C):	$(OBJ_CLIENT)
			make -sC libs/my/ all
			make -sC libs/my/ clean
			gcc -o $(NM_C) $(SRC_C) $(CF_CL) ${LB_I} ${LIBS} ${MY_LIB}

debug:
			make -sC libs/my/ all
			make -sC libs/my/ clean
			gcc -o $(NM_S) $(SRC_S) $(CF_SV) ${LB_I} ${LIBS} ${MY_LIB} $(DF)
			gcc -o $(NM_C) $(SRC_C) $(CF_CL) ${LB_I} ${LIBS} ${MY_LIB} $(DF)

clean:
			rm -f $(OBJ_SERVER)
			rm -f $(OBJ_CLIENT)

fclean:	clean
			rm -f $(NM_S)
			rm -f $(NM_C)

re:			fclean all
