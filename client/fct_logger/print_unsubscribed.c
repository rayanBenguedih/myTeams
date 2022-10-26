/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** print_unsubscribed
*/

#include "../include/client.h"

int print_unsubscribed(char *type)
{
    char *user_uuid = strdup(strtok(type, ":"));
    char *team_uuid = strdup(strtok(NULL, "\n"));

    client_print_unsubscribed(user_uuid,
                                team_uuid);
    free(user_uuid);
    free(team_uuid);
    return 0;
}
