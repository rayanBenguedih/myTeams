/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** print_subscribed
*/

#include "../include/client.h"

int print_subscribed(char *type)
{
    char *user_uuid = strdup(strtok(type, ":"));
    char *team_uuid = strdup(strtok(NULL, "\n"));

    client_print_subscribed(user_uuid,
                            team_uuid);
    free(user_uuid);
    free(team_uuid);
    return 0;
}
