/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** linkedlist
*/

#include "include/server.h"

int is_a_teams(teamsServ_t *nm, teamsServ_t *servs)
{
    teamsServ_t *tmp = servs;

    if (nm == NULL)
        return (0);
    while (tmp != NULL) {
        if (strcmp(nm->uuid, tmp->uuid) == 0)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int is_a_channel(teamsChannels_t *nm, teamsChannels_t *servs)
{
    teamsChannels_t *tmp = servs;

    while (tmp != NULL) {
        if (strcmp(nm->uuid, tmp->uuid) == 0)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

int is_a_thread(teamsThread_t *nm, teamsThread_t *servs)
{
    teamsThread_t *tmp = servs;

    while (tmp != NULL) {
        if (strcmp(nm->uuid, tmp->uuid) == 0)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}

void check_pts_data(teamsData_t *data, teamsUsers_t *pts, char *contextServ)
{
    data->context = -1;
    if (pts == NULL) {
        error_handler(data);
        return;
    }
    if (is_a_teams((teamsServ_t *) pts, data->teamsServers) == 1) {
        data->context = 2;
        data->teamsUuidUse = contextServ;
    }
    if (is_a_channel((teamsChannels_t *) pts, data->teamsChannel) == 1) {
        data->context = 3;
        data->channelUuidUse = contextServ;
    }
    if (is_a_thread((teamsThread_t *) pts, data->teamsThreads) == 1) {
        data->context = 4;
        data->threadUuidUse = contextServ;
    }
    dprintf(data->commanderSocket, "OK:UNKNOWN\n\r");
}

void handle_rest(teamsThread_t* pts, teamsData_t *data, teamsMessage_t *new)
{
    teamsThread_t *st = pts;
    teamsMessage_t *tmp = data->teamsMessages;

    if (st != NULL && st->type[0] == '4' && st->uuid == new->destUuid) {
        uuid_list_push_back(st->comsUuidList, new->uuid);
    }
    if (!tmp || data->teamsMessages == NULL)
        data->teamsMessages = new;
    else {
        while (tmp != NULL && tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}
