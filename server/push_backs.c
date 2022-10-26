/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** push_backs
*/

#include "include/server.h"

void servs_push_back(char *name, teamsData_t *data, char *desc)
{
    teamsServ_t *new = malloc(sizeof(teamsServ_t) * 1);
    uuid_t binuuid;
    teamsServ_t *tmp = data->teamsServers;

    if (!new)
        return;
    uuid_generate_random(binuuid);
    new->description = strdup(desc);
    new->name = malloc(sizeof(char) * strlen(name) +1);
    new->uuid = malloc(UUID_LEN);
    new->type = malloc(sizeof(char) * 2);
    new->type[0] = '3';
    new->type[1] = '\0';
    if (!new->name || !new->uuid)
        return;
    uuid_unparse(binuuid, new->uuid);
    strcpy(new->name, name);
    new->next = NULL;
    new->channelsUuidList = NULL;
    serv_comp(tmp, new, data);
}

void user_push_back(char *name, teamsData_t *data, int fd)
{
    teamsUsers_t *myUser = malloc(sizeof(teamsUsers_t) * 1);
    uuid_t binuuid;

    uuid_generate_random(binuuid);
    if (!myUser) {
        write(2, "Error in malloc\n", 17);
        return;
    }
    myUser->name = strdup(name);
    myUser->uuid = malloc(UUID_LEN);
    if (!myUser->name || !myUser->uuid) {
        write(2, "Error in malloc\n", 17);
        return;
    }
    uuid_unparse(binuuid, myUser->uuid);
    myUser->next = NULL;
    myUser->con = 1;
    myUser->fd = fd;
    myUser->uuid[UUID_LEN - 1] = '\0';
    get_usr_data(myUser, data);
}

void channel_push_back(teamsData_t *myData, char *cN, char *titre, char *pr)
{
    teamsChannels_t *new = malloc(sizeof(teamsChannels_t) * 1);
    uuid_t binuuid;

    uuid_generate_random(binuuid);
    if (!new)
        return;
    new->uuid = malloc(UUID_LEN);
    new->authorName = strdup(titre);
    new->messageContent = malloc(sizeof(char) * strlen(cN));
    new->teamsUuid = malloc(UUID_LEN);
    new->next = NULL;
    if (!new->uuid || !new->messageContent || !new->teamsUuid) {
        write(2, "Error in malloc\n", 17);
        return;
    }
    uuid_unparse(binuuid, new->uuid);
    strcpy(new->messageContent, cN);
    strcpy(new->teamsUuid, pr);
    add_to_teams(myData, new);
}

void uuid_list_push_back(idata_t *list, char *uuid)
{
    idata_t *tmp = list;
    idata_t *new = malloc(sizeof(idata_t) * 1);

    if (!new)
        return;
    new->uuid = malloc(UUID_LEN);
    if (!new->uuid)
        return;
    strcpy(new->uuid, uuid);
    if (tmp == NULL) {
        list = new;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void usr_teams_pb(idata_t *mem, teamsUsers_t *user)
{
    idata_t *tmp = user->teamsUuidList;

    while (tmp != NULL && tmp->next != NULL)
        tmp = tmp->next;
    if (tmp == NULL)
        user->teamsUuidList = mem;
    else
        tmp->next = mem;
}
