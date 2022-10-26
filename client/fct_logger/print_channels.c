/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** print_channels
*/

#include "../include/client.h"

int print_channels(char *type)
{
    char *channel_uuid = strdup(strtok(type, ":"));
    char *channel_name = strdup(strtok(NULL, ":"));
    char *channel_description = strdup(strtok(NULL, "\n"));

    client_print_channel(channel_uuid,
                            channel_name,
                            channel_description);
    free(channel_uuid);
    free(channel_name);
    free(channel_description);
    return 0;
}
