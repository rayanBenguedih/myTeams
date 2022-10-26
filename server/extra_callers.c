/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** extra_callers
*/

#include "include/server.h"

void call_subscribe(teamsData_t *data)
{
    char *destUuid = malloc(sizeof(char) * strlen(data->command) + 1);
    char *authUuid = malloc(sizeof(char) * strlen(data->command) + 1);
    teamsUsers_t *users;
    teamsServ_t *tmp;

    strcpy(authUuid, data->command);
    authUuid = strtok(authUuid, "\"");
    strcpy(destUuid, data->command);
    destUuid = strtok(destUuid, " ");
    destUuid = strtok(NULL, " ");
    destUuid = strtok(NULL, "\"");
    users = find_by_uuid(data, authUuid);
    if (users == NULL)
        return;
    tmp = find_by_uuid(data, destUuid);
    dprintf(data->commanderSocket, "OK:UNKNOWN\n\r");
    uuid_list_push_back(users->teamsUuidList, tmp->uuid);
    server_event_user_subscribed(destUuid, authUuid);
}

void if_else_unnested(idata_t *tmp, idata_t *prev, idata_t *list)
{
    if (prev == NULL) {
        list = list->next;
    } else {
        prev->next = tmp->next;
    }
}

void uuid_list_remove(idata_t *list, char *uuidRem)
{
    idata_t *tmp = list;
    idata_t *prev = NULL;

    while (tmp->next != NULL) {
        if (strcmp(tmp->uuid, uuidRem) == 0) {
            if_else_unnested(tmp, prev, list);
            free(tmp->uuid);
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return;
}

void call_unsubscribe(teamsData_t *data)
{
    char *authUuid = malloc(sizeof(char) * strlen(data->command) + 1);
    char *destUuid = malloc(sizeof(char) * strlen(data->command) + 1);
    teamsUsers_t *users;

    strcpy(authUuid, data->command);
    authUuid = strtok(authUuid, "\"");
    strcpy(destUuid, data->command);
    destUuid = strtok(destUuid, " ");
    destUuid = strtok(NULL, " ");
    destUuid = strtok(NULL, "\"");
    users = find_by_uuid(data, authUuid);
    if (users == NULL)
        return;
    dprintf(data->commanderSocket, "OK:UNKNOWN\n\r");
    uuid_list_remove(users->teamsUuidList, destUuid);
    server_event_user_unsubscribed(destUuid, authUuid);
    free(authUuid);
    free(destUuid);
}
