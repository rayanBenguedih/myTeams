/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** main
*/

#include "include/server.h"

void init_data(teamsData_t *mydata)
{
    mydata->users = NULL;
    mydata->context = -1;
    mydata->teamsServers = NULL;
    mydata->teamsChannel = NULL;
    mydata->teamsUuidUse = NULL;
    mydata->channelUuidUse = NULL;
    mydata->command = NULL;
    mydata->teamsMessages = NULL;
    mydata->threadUuidUse = NULL;
}

void get_usr_data(teamsUsers_t *User, teamsData_t *data)
{
    teamsUsers_t *tmp = data->users;

    User->type = malloc(sizeof(char) * 2);
    User->type[0] = '0';
    User->teamUuidUse = NULL;
    User->channelsUuidUse = NULL;
    User->threadUuidUse = NULL;
    if (tmp == NULL)
        data->users = User;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = User;
    }
    server_event_user_logged_in(User->uuid);
}

int help(void)
{
    printf("USAGE: ./myteams_server port\n\n");
    printf("      port  is the port number on which the server socket");
    printf("listens.\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return help();
    if (error(ac, av) == 84)
        return 84;
    start(atoi(av[1]));
    return 0;
}
