/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** more_data_crst
*/

#include "include/server.h"

void *find_by_uuid(teamsData_t *data, char *uuid)
{
    teamsUsers_t *srtmp = data->users;
    teamsChannels_t *chtmp = data->teamsChannel;
    teamsServ_t *svtmp = data->teamsServers;
    teamsThread_t *thct = data->teamsThreads;
    int found = 0;

    if (!uuid)
        return (NULL);
    while (found == 0 && srtmp != NULL) {
        found = (strcmp(srtmp->uuid, uuid) == 0) ? 1 : found;
        srtmp = (found == 0) ? srtmp->next : srtmp;
    }
    while (found == 0 && chtmp != NULL) {
        found = (strcmp(chtmp->uuid, uuid) == 0) ? 2 : found;
        chtmp = (found == 0) ? chtmp->next : chtmp;
    }
    found = extra_save_lines(uuid, thct, svtmp, found);
    if (found == 4)
        return (thct);
    return (check_pts(found, srtmp, chtmp, svtmp));
}

int teams_nums(teamsUsers_t *usr)
{
    int i = 0;
    idata_t *tmp = usr->teamsUuidList;

    while (tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    return (i);
}

void fill_my_str(char *str, idata_t *lst, teamsServ_t *serv,
teamsData_t *data)
{
    strcat(str, lst->uuid);
    strcat(str, ":");
    serv = find_by_uuid(data, lst->uuid);
    strcat(str, serv->name);
    strcat(str, ":");
    strcat(str, serv->description);
    strcat(str, ":");
}

void mega_saver_lining(char *destUuid, teamsData_t *data, char *authUuid,
    char *str)
{
    idata_t *lst;
    teamsUsers_t *users = find_by_uuid(data, authUuid);
    teamsServ_t *serv;

    if (destUuid == NULL) {
        lst = users->teamsUuidList;
        while (lst != NULL) {
            fill_my_str(str, lst, serv, data);
            lst = lst->next;
        }
    } else {
        serv = find_by_uuid(data, destUuid);
        if (serv == NULL || data->users == NULL)
            return;
        display_all_users(destUuid, data);
    }
    dprintf(data->commanderSocket, "%s\n\r", str);
    free(authUuid);
    free(destUuid);
}

void call_subscribed(teamsData_t *data)
{
    char *authUuid = malloc(sizeof(char) * strlen(data->command) + 1);
    char *destUuid = malloc(sizeof(char) * strlen(data->command) + 1);
    char *str = malloc(sizeof(char) * 90 * 150);
    teamsServ_t *serv;

    strcpy(authUuid, data->command);
    authUuid = strtok(authUuid, "\"");
    strcpy(destUuid, data->command);
    destUuid = strtok(destUuid, " ");
    destUuid = strtok(NULL, " ");
    destUuid = strtok(NULL, "\"");
    strcat(str, "OK:PRINT_SUBSCRIBED:");
    mega_saver_lining(destUuid, data, authUuid, str);
}
