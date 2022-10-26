/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** decider
*/

#include "include/server.h"

void create_new_thread(teamsData_t *data)
{
    char *messageContent = malloc(sizeof(char) * strlen(data->command));
    char *authorName = malloc(sizeof(char) * strlen(data->command));
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
    creation_printing(data, strdup(messageContent), strdup(authorName));
}

void ping_everyone(teamsData_t *data, teamsMessage_t *reply)
{
    teamsUsers_t *usr = data->users;

    while (usr) {
        if (usr->con == 1 && user_is_in_team(usr, data->teamsUuidUse) == 1)
            dprintf(usr->fd, "OK:PRINT_THREAD_REPLY_CREATED:%s:%s:%s:%s\n\r",
            data->threadUuidUse, reply->authoruuid, reply->data,
            reply->content);
        usr = usr->next;
    }
}

void create_new_reply(teamsData_t *data)
{
    char *messageContent = malloc(sizeof(char) * strlen(data->command));
    char *authorUuid = malloc(sizeof(char) * strlen(data->command));
    teamsMessage_t *tmp = data->teamsMessages;

    strcpy(messageContent, data->command);
    messageContent = strtok(messageContent, " ");
    messageContent = strtok(NULL, " ");
    messageContent = strtok(NULL, "\"");
    strcpy(authorUuid, data->command);
    authorUuid = strtok(authorUuid, "\"");
    msg_push_back(data, data->threadUuidUse, messageContent, authorUuid);
    while (tmp->next != NULL)
        tmp = tmp->next;
    server_event_reply_created(data->threadUuidUse, get_user_uuid(data),
    messageContent);
    dprintf(data->commanderSocket, "OK:THREAD_REPLY_RECEIVE:%s:%s:%s:%s\n\r",
    data->teamsUuidUse, data->threadUuidUse, authorUuid, messageContent);
    ping_everyone(data, tmp);
}

int already_exists(teamsData_t *data, int fd)
{
    char *name = strdup(data->command);

    if (fd == 1)
        return (0);
    name = strtok(name, " ");
    name = strtok(NULL, " ");
    name = strtok(NULL, "\"");
    if (find_by_name(name) != NULL) {
        dprintf(data->commanderSocket, "ERROR:ERROR_ALREADY_EXIST\n\r");
        return (1);
    }
    return (0);
}

void call_create(teamsData_t *data)
{
    if (data->teamsUuidUse == NULL
    || (data->context == -1 && already_exists(data, 1) == 0)) {
        create_new_teams(data);
    }
    if (data->context == 2 && already_exists(data, 2) == 0) {
        create_new_channel(data);
    }
    if (data->context == 3 && already_exists(data, 3) == 0) {
        create_new_thread(data);
    }
    if (data->context == 4 && already_exists(data, 4) == 0) {
        create_new_reply(data);
    }
}
