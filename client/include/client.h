/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #define BUFFER_SIZE 1024

    #include "../../libs/myteams/logging_client.h"
    #include "../../libs/my/teams.h"

    #include <sys/types.h>
    #include <sys/queue.h>

    #include <sys/socket.h>
    #include <sys/select.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <uuid/uuid.h>
    #include <sys/ioctl.h>

    #include <sys/sendfile.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <netdb.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <regex.h>

//////////////////////////////////////////////////////////////////////////////

typedef struct client_s client_t;

struct client_s {
    int socket;
    int port;
    char *ip;
    struct sockaddr_in addr;

    fd_set original;
    fd_set readable;

    char *user_name;
    char *uuid;
};

//////////////////////////////////////////////////////////////////////////////

int error(int ac, char **av);
void launch(char *ip, int port);
int communication(client_t *_client, int a);
void reconnection(client_t *client);
char *search_token(char *str, char break_symbol, bool previous_same_str);
void loop_call_logger(client_t *_client, char *_read);
void reset_buffer(char *rd, char *wr);
char *read_socket(client_t *client, char *buffer);
void send_command(client_t *client, char *input);
int handle_event_on_client(client_t *client);

void call_logger(client_t *_client, char *_read);

int command_handling(client_t *_client, char *input);
bool correct_command(char *command);

bool correct_help(char *input);
bool correct_create(char *input);
bool correct_info(char *input);
bool correct_list(char *input);
bool correct_login(char *input);
bool correct_logout(char *input);
bool correct_messages(char *input);
bool correct_send(char *input);
bool correct_subscribe(char *input);
bool correct_subscribed(char *input);
bool correct_unsubscribe(char *input);
bool correct_use(char *input);
bool correct_user(char *input);
bool correct_users(char *input);

int logger(char *answer, client_t *_client);

int log_in(char *type, client_t *_client);
int log_out(char *type, client_t *_client);
int private_message_receive(char *type);
int thread_reply(char *type);
int team_created(char *type);
int channel_created(char *str);
int thread_create(char *str);
int print_users(char *type, client_t *_client);
int print_teams(char *type);
int print_channels(char *type);
int print_threads(char *type);
int print_replies(char *type);
int print_user(char *type);
int print_team(char *answer, client_t *_client);
int print_channel(char *type);
int print_thread(char *type);
int print_team_created(char *type);
int print_channel_created(char *type);
int print_thread_created(char *type);
int print_thread_reply_created(char *type);
int print_subscribed(char *type);
int print_unsubscribed(char *type);
int private_msg_print_msg(char *type);

int strlen_net(char *str);
void send_command(client_t *client, char *input);
int quit(client_t *client, char *str1, char *str2);

#endif /* !CLIENT_H_ */
