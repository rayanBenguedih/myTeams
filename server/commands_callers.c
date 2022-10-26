/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** commands_callers
*/

#include "include/server.h"

void show_channels_info(teamsData_t *data)
{
    teamsChannels_t *tmp = (teamsChannels_t*) find_by_uuid(data,
    data->channelUuidUse);
    teamsThread_t *ths = data->teamsThreads;

    if (!tmp)
        return;
    dprintf(data->commanderSocket, "OK:PRINT_CHANNEL:%s:%s:%s\n\r", tmp->uuid,
    tmp->authorName, tmp->messageContent);
}

int already_exist(char *userName, teamsData_t *data)
{
    teamsUsers_t *tmp = data->users;

    while (tmp != NULL) {
        if (strcmp(tmp->name, userName) == 0) {
            tmp->con = 1;
            dprintf(data->commanderSocket, "OK:LOGGED_IN:%s:%s\n\r",
            tmp->uuid, userName);
            server_event_user_logged_in(tmp->uuid);
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

void msg_push_back_two(teamsData_t *data, char *destUuid, char *body,
char *authuuid)
{
    teamsMessage_t *new = malloc(sizeof(teamsMessage_t) * 1);
    teamsMessage_t *msg = data->teamsMessages;

    new->authoruuid = strdup(authuuid);
    new->destUuid = strdup(destUuid);
    new->content = strdup(body);
    new->type = malloc(sizeof(char) * 2);
    new->type[0] = '1';
    new->type[1] = '\0';
    new->data = malloc(sizeof(char) * 21);
    my_long_to_ascii(time(NULL), new->data, 10);
    new->next = NULL;
    if (msg != NULL) {
        while (msg->next != NULL)
            msg = msg->next;
        msg->next = new;
    } else
        data->teamsMessages = new;
}

void magic_thing(teamsData_t *data, char *authUuid, char *messageBody,
char *destUuid)
{
    teamsMessage_t *msg;
    teamsUsers_t *usr = (teamsUsers_t *) find_by_uuid(data, destUuid);

    msg_push_back_two(data, strdup(destUuid), strdup(messageBody),
    strdup(authUuid));
    server_event_private_message_sended(authUuid, destUuid, messageBody);
    msg = data->teamsMessages;
    while (msg->next != NULL)
        msg = msg->next;
    dprintf(usr->fd, "OK:PRIVATE_MESSAGE_RECEIVED:%s:%s\n\r", msg->authoruuid,
    msg->content);
    dprintf(data->commanderSocket, "OK:UNKNOWN\n\r");
}

void call_send(teamsData_t *data)
{
    char *messageBody = malloc(sizeof(char) * strlen(data->command) + 1);
    char *diD = malloc(sizeof(char) * strlen(data->command) + 1);
    char *authUuid = malloc(sizeof(char) * strlen(data->command) + 1);

    strcpy(authUuid, data->command);
    authUuid = strtok(authUuid, "\"");
    strcpy(messageBody, data->command);
    messageBody = strtok(messageBody, " ");
    messageBody = strtok(NULL, " ");
    messageBody = strtok(NULL, " ");
    messageBody = strtok(NULL, "\"");
    strcpy(diD, data->command);
    diD = strtok(diD, " ");
    diD = strtok(NULL, " ");
    diD = strtok(NULL, "\"");
    if (!find_by_uuid(data, diD)) {
        dprintf(data->commanderSocket, "ERROR:ERROR_UNKNOW_USER:%s\n\r", diD);
        return;
    }
    magic_thing(data, authUuid, messageBody, diD);
}
