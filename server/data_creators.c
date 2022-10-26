/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** data_creators
*/

#include "include/server.h"

void liberate(char *a, char *b)
{
    free(a);
    free(b);
}

int bigass_compare_magic(char *authUuid, teamsMessage_t *tmp, char *destUuid)
{
    if ((strcmp(tmp->authoruuid, destUuid) == 0 || strcmp(tmp->authoruuid,
        authUuid) == 0) && (strcmp(tmp->destUuid, destUuid) == 0 ||
        strcmp(tmp->destUuid, authUuid) == 0))
            return (0);
    return (1);
}

void call_messages(teamsData_t *data)
{
    char *authUuid = malloc(sizeof(char) * strlen(data->command) + 1);
    char *destUuid = malloc(sizeof(char) * strlen(data->command) + 1);
    teamsMessage_t *tmp = data->teamsMessages;
    char *str = malloc(sizeof(char) * 150 * 100);

    strcpy(authUuid, data->command);
    authUuid = strtok(authUuid, "\"");
    strcpy(destUuid, data->command);
    destUuid = strtok(destUuid, " ");
    destUuid = strtok(NULL, " ");
    destUuid = strtok(NULL, "\"");
    while (tmp != NULL) {
        if (bigass_compare_magic(authUuid, tmp, destUuid) == 0)
            sprintf(str, "%s%s\a%s\a%s\a:", str, tmp->authoruuid, tmp->content,
            tmp->data);
        tmp = tmp->next;
    }
    printf("%s\n", str);
    dprintf(data->commanderSocket, "OK:PRIVATE_MSG_PRINT_MSG:%s\n\r", str);
}

void show_server_dlc(teamsData_t *data, char *name, char *desc)
{
    teamsServ_t *srv = data->teamsServers;
    teamsUsers_t *usr = data->users;

    while (srv->next != NULL)
        srv = srv->next;
    while (usr != NULL) {
        if (usr->fd == 1)
            dprintf(usr->fd, "OK:PRINT_TEAM_CREATED:%s:%s:%s\n\r", srv->uuid,
            name, desc);
        usr = usr->next;
    }
    dprintf(data->commanderSocket, "OK:TEAM_CREATED:%s:%s:%s\n\r",
    srv->uuid, name, desc);
}

void create_new_teams(teamsData_t *data)
{
    char *name = malloc(sizeof(char) * strlen(data->command) + 1);
    char *desc = malloc(sizeof(char) * strlen(data->command) + 1);

    strcpy(name, data->command);
    name = strtok(name, " ");
    name = strtok(NULL, " ");
    name = strtok(NULL, "\"");
    strcpy(desc, data->command);
    desc = strtok(desc, " ");
    desc = strtok(NULL, " ");
    desc = strtok(NULL, " ");
    desc = strtok(NULL, "\"");
    servs_push_back(name, data, desc);
    show_server_dlc(data, name, desc);
}
