/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** log_out
*/

#include "../include/client.h"

int log_out(char *type, client_t *client)
{
    char *user_uuid = strdup(strtok(type, ":"));
    char *user_name = strdup(strtok(NULL, "\n"));

    client_event_logged_out(user_uuid, user_name);
    free(user_uuid);
    free(user_name);
    close(client->socket);
    client->socket = -1;
    return 0;
}
