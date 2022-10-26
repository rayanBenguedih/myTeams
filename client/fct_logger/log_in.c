/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** log_in
*/

#include "../include/client.h"

int log_in(char *type, client_t *_client)
{
    char *user_uuid = strdup(strtok(type, ":"));
    char *user_name = strdup(strtok(NULL, "\n"));

    printf("Remaining data: %s\n", type);
    _client->uuid = strdup(user_uuid);
    client_event_logged_in(user_uuid, user_name);
    free(user_uuid);
    free(user_name);
    return 0;
}
