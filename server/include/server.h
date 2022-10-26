/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** teams
*/

#ifndef SERVER_H_
    #define SERVER_H_
    #define UUID_LEN 37
    #define _OPEN_SYS_ITOA_EXT
    #define BUFFER_SIZE 1024

    #include "../../libs/myteams/logging_server.h"
    #include "../../libs/my/teams.h"

    #include <sys/time.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/socket.h>
    #include <sys/select.h>

    #include <netinet/in.h>
    #include <arpa/inet.h>

    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdbool.h>
    #include <uuid/uuid.h>
    #include <fcntl.h>

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

typedef struct teamsMessage_s teamsMessage_t;
typedef struct teamsServ_s teamsServ_t;
typedef struct teamsUser_s teamsUsers_t;
typedef struct teamsChannels_s teamsChannels_t;
typedef struct uuid_data_s idata_t;
typedef struct teamsThread_s teamsThread_t;

// Tout les UUIDs avec leur type, permets de trouver n'importe quel
// élément de n'importe quelle liste chaînée en fonction du type et de l'UUID
typedef struct uuid_data_s {
    char *uuid;
    idata_t *next;
} idata_t;

// Tout les utilisateurs
typedef struct teamsUser_s {
    char *name;
    char *type;
    int con;
    char *uuid;
    int fd;
    char *teamUuidUse;
    char *channelsUuidUse;
    char *threadUuidUse;
    idata_t *teamsUuidList;
    teamsUsers_t *next;
} teamsUsers_t;

// Tout le messages créers
typedef struct teamsMessage_s {
    char *authoruuid;
    char *authorName;
    char *type;
    char *uuid;
    char *destUuid;
    char *content;
    char *data;
    teamsMessage_t *next;
} teamsMessage_t;

// Tout les Threads créers
typedef struct teamsChannels_s {
    char *uuid;
    char *type;
    char *messageContent;
    char *authorName;
    char *teamsUuid;
    teamsChannels_t *next;
} teamsChannels_t;

typedef struct teamsThread_s {
    char *uuid;
    char *authoruuid;
    char *type;
    char *title;
    char *content;
    char *timing;
    char *chansUuid;
    idata_t *comsUuidList;
    teamsThread_t *next;
} teamsThread_t;

// Tout les teams créers
typedef struct teamsServ_s {
    char *name;
    char *uuid;
    char *type;
    char *description;
    idata_t *channelsUuidList;
    teamsServ_t *next;
} teamsServ_t;

// Tout les data nécessaire
typedef struct teamsData_s {
    int socket;
    int port;
    fd_set ensemble;
    fd_set ready;
    struct sockaddr_in addr;
    socklen_t addrLen;
    int maxFd;
    int context;
    int commanderSocket;
    char *command;
    char *teamsUuidUse;
    char *channelUuidUse;
    char *threadUuidUse;
    char *response;
    teamsUsers_t *users;
    teamsMessage_t *teamsMessages;
    teamsChannels_t *teamsChannel;
    teamsServ_t *teamsServers;
    teamsThread_t *teamsThreads;
} teamsData_t;

/////////////////////////////////////////////////////////////////////////////

int error(int ac, char **av);
void init_connections(teamsData_t *serv, int port);
void start(int port);
void handler_request(teamsData_t *serv);
void command_execution(teamsData_t *serv, int clientFd);
void servs_push_back(char *name, teamsData_t *data, char *desc);
void user_push_back(char *name, teamsData_t *data, int fd);
void channel_push_back(teamsData_t *myData, char *cN, char *titre, char *pr);
void uuid_list_push_back(idata_t *list, char *uuid);
void usr_teams_pb(idata_t *mem, teamsUsers_t *user);
void handle_rest(teamsThread_t* pts, teamsData_t *data, teamsMessage_t *new);
void msg_push_back(teamsData_t *data, char *destuid, char *ctn,
char *authuid);
void add_to_teams(teamsData_t *myData, teamsChannels_t *chn);
void init_data(teamsData_t *mydata);
void get_usr_data(teamsUsers_t *User, teamsData_t *data);
char *get_user_uuid(teamsData_t *data);
void serv_comp(teamsServ_t *tmp, teamsServ_t *new, teamsData_t *data);
void handle_uuids(teamsData_t *myData, teamsChannels_t *chn,
teamsServ_t *pts);
void *check_pts(int found, teamsUsers_t *srtmp, teamsChannels_t *chtmp,
teamsServ_t *svtmp);
int extra_save_lines(char *uuid, teamsThread_t *thct,
teamsServ_t *svtmp, int found);
void call_send(teamsData_t *data);
void call_logout(teamsData_t *data);
void call_login(teamsData_t *data);
void fill_data(teamsData_t *data, char *contextServ, char *contextChan,
char *contextThread);
void check_pts_data(teamsData_t *data, teamsUsers_t *pts, char *str);
void call_use(teamsData_t *data);
void call_user(teamsData_t *data);
void call_subscribe(teamsData_t *data);
void uuid_list_remove(idata_t *list, char *uuidRem);
void call_unsubscribe(teamsData_t *data);
void display_all_users(char *uuid, teamsData_t *data);
void *find_by_uuid(teamsData_t *data, char *uuid);
int teams_nums(teamsUsers_t *usr);
void call_subscribed(teamsData_t *data);
void call_messages(teamsData_t *data);
void create_new_teams(teamsData_t *data);
void create_new_channel(teamsData_t *data);
void thread_push_back(teamsData_t *data, char *cnt, char *nm, char *suuid);
void create_new_thread(teamsData_t *data);
void create_new_reply(teamsData_t *data);
void call_create(teamsData_t *data);
void list_all_teams(teamsData_t *data);
void list_all_channels(teamsData_t *data);
void check_threads_with_uuid(teamsData_t *data, char *uuid, char *str);
void list_all_threads(teamsData_t *data);
void list_all_coms(teamsData_t *data);
void show_channels_info(teamsData_t *data);
void show_teams_info(teamsData_t *data);
void find_teams_users(teamsUsers_t *pts, teamsData_t *data, teamsServ_t *tmp);
void show_users_info(teamsData_t *data);
void call_list(teamsData_t *data);
void show_threads_info(teamsData_t *data);
void call_info(teamsData_t *data);
int users_nums(teamsData_t *data);
void call_users(teamsData_t *data);
char *data_parse(char *str);
int already_exists(teamsData_t *data, int fd);
int already_exist(char *userName, teamsData_t *data);
void handle_server(teamsData_t *data, int fd);
void ping_everyone(teamsData_t *data, teamsMessage_t *reply);
char *my_long_to_ascii(long num, char *buffer, int base);
char *find_by_name(char *name);
char *malloc_path(size_t nb_uuid);
char **read_file(char *path, FILE **stream);
void error_handler(teamsData_t *data);
int user_is_in_team(teamsUsers_t *usr, char *id);
void creation_printing(teamsData_t *data, char *body, char *title);
int total_us_sum(teamsData_t *data);
void liberate(char *a, char *b);
void c_hlp(teamsData_t *data);
int c_lin (teamsData_t *data);
int c_usr(teamsData_t *data);
int c_use(teamsData_t *data);
int c_usbd(teamsData_t *data);
int c_subs(teamsData_t *data);
int c_msg(teamsData_t *data);
int c_snd(teamsData_t *data);
void run_preliminaries(teamsData_t *data, int fd);
void run_verif_stairs(int i, teamsData_t *data, char *tabs[], void (*cmds[14])
(teamsData_t *d));
void reset_data(teamsData_t *data);
int no_uuid_cmd(teamsData_t *data);
int good_commands(char *tab[], int i, teamsData_t *data);
int is_a_teams(teamsServ_t *nm, teamsServ_t *servs);
char *get_fourth_arg(teamsData_t *data);
#endif /* SERVER_H_ */
