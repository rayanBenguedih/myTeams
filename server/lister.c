/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** lister
*/

#include "include/server.h"

void list_all_teams(teamsData_t *data)
{
    teamsServ_t *tmp = data->teamsServers;
    char *str = malloc(sizeof(char) * 100 * 150);

    strcat(str, "OK:PRINT_TEAMS:");
    while (tmp != NULL) {
        strcat(str, tmp->uuid);
        strcat(str, "\a");
        strcat(str, tmp->name);
        strcat(str, "\a");
        strcat(str, tmp->description);
        strcat(str, ":");
        tmp = tmp->next;
    }
    dprintf(data->commanderSocket, "%s\n\r", str);
    free(str);
}

void write_stuff(char *str, teamsChannels_t *pts)
{
    strcat(str, pts->uuid);
    strcat(str, "\a");
    strcat(str, pts->authorName);
    strcat(str, "\a");
    strcat(str, pts->messageContent);
    strcat(str, ":");
}

void list_all_channels(teamsData_t *data)
{
    teamsServ_t *tmp = (teamsServ_t*) find_by_uuid(data, data->teamsUuidUse);
    idata_t *lst;
    char *str = malloc(sizeof(char) * 100 * 150);
    teamsChannels_t *pts;

    if (!tmp)
        return;
    lst = tmp->channelsUuidList;
    strcat(str, "OK:LIST_CHANNELS:");
    while (lst != NULL) {
        pts = (teamsChannels_t *) find_by_uuid(data, lst->uuid);
        if (pts)
            write_stuff(str, pts);
        lst = lst->next;
    }
    dprintf(data->commanderSocket, "%s\n\r", str);
    free(str);
}

void check_threads_with_uuid(teamsData_t *data, char *uuid, char *str)
{
    teamsThread_t *tmp = data->teamsThreads;

    while (tmp != NULL) {
        if (strcmp(tmp->chansUuid, uuid) == 0) {
            strcat(str, tmp->uuid);
            strcat(str, ":");
        }
        tmp = tmp->next;
    }
}

void list_all_threads(teamsData_t *data)
{
    teamsServ_t *tmp = (teamsServ_t*) find_by_uuid(data, data->teamsUuidUse);
    idata_t *lst;
    teamsChannels_t *stp = data->teamsChannel;
    char *str = malloc(sizeof(char) * 150 * 100);

    if (!tmp)
        return;
    while (stp != NULL) {
        if (strcmp(stp->teamsUuid, data->teamsUuidUse) == 0)
            check_threads_with_uuid(data, stp->uuid, str);
        stp = stp->next;
    }
    dprintf(data->commanderSocket, "OK:PRINT_THREADS:%s\n\r", str);
    free(str);
}
