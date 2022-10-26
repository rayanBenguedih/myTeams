/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** push_backs_complements
*/

#include "include/server.h"

void allocate_for_new(teamsMessage_t *new, char *ctn)
{
    new->type = malloc(sizeof(char) * 2);
    new->type[0] = '1';
    new->authoruuid = malloc(UUID_LEN);
    new->destUuid = malloc(UUID_LEN);
    new->content = malloc(sizeof(strlen(ctn)));
}

void msg_push_back(teamsData_t *data, char *destuid, char *ctn, char *authuid)
{
    teamsMessage_t *new = malloc(sizeof(teamsMessage_t) * 1);
    teamsUsers_t *usr = (teamsUsers_t *) find_by_uuid(data, destuid);
    teamsThread_t* pts = (teamsThread_t*) find_by_uuid(data, destuid);

    printf("%s %s %s\n", destuid, ctn, authuid);
    if (!new || usr == NULL) {
        write(2, "Error in malloc\n", 17);
        return;
    }
    allocate_for_new(new, ctn);
    if (!new->authoruuid || !new->destUuid || !new->content)
        return;
    strcpy(new->authoruuid, usr->uuid);
    strcpy(new->destUuid, destuid);
    strcpy(new->content, ctn);
    printf("%s %s %s\n", new->authoruuid, new->destUuid, new->content);
    new->data = malloc(sizeof(char) * 21);
    new->next = NULL;
    my_long_to_ascii(time(NULL), new->data, 10);
    handle_rest(pts, data, new);
}

int user_is_in_team(teamsUsers_t *usr, char *id)
{
    idata_t *list = usr->teamsUuidList;

    while (list) {
        if (strcmp(list->uuid, id) == 0)
            return (1);
        list = list->next;
    }
    return (0);
}

void send_data_to_client(teamsData_t *mydata, teamsChannels_t *chn)
{
    teamsUsers_t *usr = mydata->users;

    while (usr != NULL) {
        if (usr->fd != mydata->commanderSocket &&
        user_is_in_team(usr, chn->teamsUuid) == 1)
            dprintf(usr->fd, "OK:PRINT_CHANNEL_CREATED:%s:%s:%s:\n\r",
            chn->uuid, chn->authorName, chn->messageContent);
        usr = usr->next;
    }
    dprintf(mydata->commanderSocket, "OK:CHANNEL_CREATED:%s:%s:%s\n\r",
    chn->uuid, chn->authorName, chn->messageContent);
}

void add_to_teams(teamsData_t *myData, teamsChannels_t *chn)
{
    teamsChannels_t *tmp = myData->teamsChannel;
    teamsServ_t *pts = myData->teamsServers;

    chn->type = malloc(sizeof(char) * 2);
    chn->type[0] = '2';
    while (strcmp(pts->uuid, chn->teamsUuid) != 0 && pts->next != NULL)
        pts = pts->next;
    if (pts == NULL && pts->uuid != chn->teamsUuid)
        return;
    handle_uuids(myData, chn, pts);
    if (tmp == NULL)
        myData->teamsChannel = chn;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = chn;
    }
    send_data_to_client(myData, chn);
    server_event_channel_created(pts->uuid, chn->uuid, chn->messageContent);
}
