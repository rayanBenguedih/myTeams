/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** use
*/

#include "include/server.h"

char *get_first_arg(teamsData_t *data)
{
    char *str = strdup(data->command);

    if (str == NULL)
        return (NULL);
    str = strtok(str, " ");
    str = strtok(NULL, " ");
    str = strtok(NULL, "\"");
    return (str);
}

void fill_data(teamsData_t *data, char *contextServ, char *contextChan,
char *contextThread)
{
    strcpy(contextServ, data->command);
    contextServ = strtok(contextServ, " ");
    contextServ = strtok(NULL, " ");
    contextServ = strtok(NULL, "\"");
    strcpy(contextChan, data->command);
    contextChan = strtok(contextChan, " ");
    contextChan = strtok(NULL, " ");
    contextChan = strtok(NULL, " ");
    contextChan = strtok(NULL, "\"");
    strcpy(contextThread, data->command);
    contextThread = strtok(contextThread, " ");
    contextThread = strtok(NULL, " ");
    contextThread = strtok(NULL, " ");
    contextThread = strtok(NULL, " ");
    contextThread = strtok(NULL, "\"");
}

void error_handler(teamsData_t *data)
{
    if (data->teamsUuidUse && !find_by_uuid(data, data->teamsUuidUse)) {
        dprintf(data->commanderSocket, "ERROR:UNKNOWN_TEAM:%s\n\r",
        data->teamsUuidUse);
        return;
    }
    if (data->channelUuidUse && !find_by_uuid(data, data->channelUuidUse)) {
        dprintf(data->commanderSocket, "ERROR:UNKNOWN_CHANNEL:%s\n\r",
        data->channelUuidUse);
        return;
    }
    if (data->threadUuidUse && !find_by_uuid(data, data->threadUuidUse)) {
        dprintf(data->commanderSocket, "ERROR:UNKNOWN_THREAD:%s\n\r",
        data->threadUuidUse);
        return;
    }
}

void call_use(teamsData_t *data)
{
    char *contextServ = get_first_arg(data);
    char *userUuid = get_fourth_arg(data);
    teamsUsers_t *usr;
    teamsUsers_t *pts;

    usr = (teamsUsers_t *) find_by_uuid(data, userUuid);
    pts = (teamsUsers_t*) find_by_uuid(data, contextServ);
    check_pts_data(data, pts, contextServ);
    if (usr) {
        if (data->context == 2)
            usr->teamUuidUse = get_first_arg(data);
        if (data->context == 3)
            usr->channelsUuidUse = get_first_arg(data);
        if (data->context == 4)
            usr->threadUuidUse = get_first_arg(data);
    }
}
