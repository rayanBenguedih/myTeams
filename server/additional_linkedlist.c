/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** additional_linkedlist
*/

#include "include/server.h"

int no_uuid_cmd(teamsData_t *data)
{
    char *userUuid = malloc(sizeof(char) * strlen(data->command) + 1);

    strcpy(userUuid, data->command);
    userUuid = strtok(userUuid, "\"");
    if (!userUuid || strlen(userUuid) != 36 || !find_by_uuid(data, userUuid))
        return (1);
    return (0);
}

void run_preliminaries(teamsData_t *data, int fd)
{
    teamsUsers_t *tmp = find_by_uuid(data, strtok(strdup(data->command),
    "\""));

    data->commanderSocket = fd;
    if (tmp != NULL) {
        data->teamsUuidUse = tmp->teamUuidUse;
        data->channelUuidUse = tmp->channelsUuidUse;
        data->threadUuidUse = tmp->threadUuidUse;
    }
}

void c_hlp(teamsData_t *data)
{
    char *str = malloc(sizeof(char) * 262);

    strcpy(str, "OK:HELP:/login \"name\"\n/logout\n/users\n");
    strcat(str, "/user [uuid]\n/send [uuid] [content]\n/subscribe [teamsUui");
    strcat(str, "d]\nsubscribed ?[team_uuid]\n/unsubscribe [teamUuid]\n/use");
    strcat(str, " [uuid]\n/create\n[depends]\n/list (depends on /use)\n");
    strcat(str, "/info (depends on /use)\n\r");
    dprintf(data->commanderSocket, "%s", str);
    free(str);
}

int c_lin (teamsData_t *data)
{
    char *userName = malloc(sizeof(char) * strlen(data->command) + 1);
    teamsUsers_t *usr;

    strcpy(userName, data->command);
    userName = strtok(userName, " ");
    userName = strtok(NULL, " ");
    userName = strtok(NULL, "\"");
    if (userName == NULL)
        return (0);
    return (1);
}

int c_usr(teamsData_t *data)
{
    char *userUuid = malloc(sizeof(char) * strlen(data->command) + 1);
    teamsUsers_t *usr;

    strcpy(userUuid, data->command);
    userUuid = strtok(userUuid, " ");
    userUuid = strtok(NULL, " ");
    userUuid = strtok(NULL, "\"");
    if (userUuid == NULL)
        return (0);
    return (1);
}
