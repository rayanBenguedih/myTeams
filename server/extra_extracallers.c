/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** extra_extracallers
*/

#include "include/server.h"

void saving_lines_even_more(teamsUsers_t *users, teamsServ_t *tmp,
teamsData_t *data, idata_t *lst)
{
    char *str = malloc(sizeof(char) * 100 * 20);
    char *con = malloc(sizeof(char) * 2);

    strcat(str, "OK:PRINT_USER:");
    strcat(str, users->uuid);
    strcat(str, ":");
    strcat(str, users->name);
    strcat(str, ":");
    con[0] = users->con + '0';
    con[1] = '\0';
    strcat(str, con);
    strcat(str, ":");
    while (users->teamsUuidList != NULL) {
        tmp = find_by_uuid(data, lst->uuid);
        strcat(str, tmp->uuid);
        strcat(str, "\a");
        tmp = tmp->next;
    }
    dprintf(data->commanderSocket, "%s\n\r", str);
}

void call_user(teamsData_t *data)
{
    char *destUuid = malloc(sizeof(char) * strlen(data->command) + 1);
    teamsUsers_t *users;
    teamsServ_t *tmp;
    idata_t *lst;
    char *uData;

    strcpy(destUuid, data->command);
    destUuid = strtok(destUuid, " ");
    destUuid = strtok(NULL, " ");
    destUuid = strtok(NULL, "\"");
    users = find_by_uuid(data, destUuid);
    if (users == NULL) {
        dprintf(data->commanderSocket, "ERROR:ERROR_UNKNOWN_USER:%s\n\r",
        destUuid);
        return;
    }
    lst = users->teamsUuidList;
    saving_lines_even_more(users, tmp, data, lst);
}

void create_new_channel(teamsData_t *data)
{
    char *messageContent = malloc(sizeof(char) * strlen(data->command) + 1);
    char *authorName = malloc(sizeof(char) * strlen(data->command) + 1);
    char *teamsUuid;
    teamsServ_t *serv;
    char *servUuid = strdup(data->teamsUuidUse);

    serv = find_by_uuid(data, servUuid);
    if (serv == NULL)
        return;
    strcpy(messageContent, data->command);
    messageContent = strtok(messageContent, " ");
    messageContent = strtok(NULL, " ");
    messageContent = strtok(NULL, " ");
    messageContent = strtok(NULL, "\"");
    strcpy(authorName, data->command);
    authorName = strtok(authorName, " ");
    authorName = strtok(NULL, " ");
    authorName = strtok(NULL, "\"");
    channel_push_back(data, messageContent, authorName, servUuid);
}

void thread_push_back(teamsData_t *data, char *cnt, char *nm, char *suuid)
{
    teamsThread_t *tmp = data->teamsThreads;
    teamsThread_t *new = malloc(sizeof(teamsThread_t) * 1);

    new->content = strdup(cnt);
    new->title = strdup(nm);
    new->chansUuid = strdup(data->channelUuidUse);
    new->next = NULL;
    if (tmp == NULL) {
        data->teamsThreads = new;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}
