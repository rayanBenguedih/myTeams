/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** functions_complementaries
*/

#include "include/server.h"

char *get_user_uuid(teamsData_t *data)
{
    char *str = strdup(data->command);

    if (str == NULL)
        return (NULL);
    str = strtok(str, "\"");
    return (str);
}

void serv_comp(teamsServ_t *tmp, teamsServ_t *new, teamsData_t *data)
{
    if (tmp == NULL) {
        data->teamsServers = new;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
    server_event_team_created(new->uuid, new->name, get_user_uuid(data));
}

void handle_uuids(teamsData_t *myData, teamsChannels_t *chn, teamsServ_t *pts)
{
    idata_t *src;
    idata_t *new = malloc(sizeof(idata_t) * 1);

    if (!new)
        return;
    new->uuid = malloc(UUID_LEN);
    if (!new->uuid)
        return;
    new->next = NULL;
    if (pts->channelsUuidList == NULL) {
        strcpy(new->uuid, chn->uuid);
        pts->channelsUuidList = new;
    } else {
        src = pts->channelsUuidList;
        while (src->next != NULL)
            src = src->next;
        src->next = new;
    }
}

void *check_pts(int found, teamsUsers_t *srtmp, teamsChannels_t *chtmp,
teamsServ_t *svtmp)
{
    if (found == 1)
        return (srtmp);
    if (found == 2)
        return (chtmp);
    if (found == 3)
        return (svtmp);
    return (NULL);
}

int extra_save_lines(char *uuid, teamsThread_t *thct,
teamsServ_t *svtmp, int found)
{
    while (found == 0 && svtmp != NULL) {
        found = (strcmp(svtmp->uuid, uuid) == 0) ? 3 : found;
        svtmp = (found == 0) ? svtmp->next : svtmp;
    }
    while (found == 0 && thct != NULL) {
        found = (strcmp(thct->uuid, uuid) == 0) ? 4 : found;
        thct = (found == 0) ? thct->next : thct;
    }
    return (found);
}
