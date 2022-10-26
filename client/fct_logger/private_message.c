/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** private_message
*/

#include "../include/client.h"

int private_message_receive(char *type)
{
    char *user_uuid = strdup(strtok(type, ":"));
    char *body = strdup(strtok(NULL, "\n"));

    client_event_private_message_received(user_uuid, body);
    free(user_uuid);
    free(body);
    return 0;
}
