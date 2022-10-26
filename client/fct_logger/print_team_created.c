/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** print_team_created
*/

#include "../include/client.h"

int print_team_created(char *type)
{
    char *team_uuid = strdup(strtok(type, ":"));
    char *team_name = strdup(strtok(NULL, ":"));
    char *team_description = strdup(strtok(NULL, ":"));

    client_print_team_created(team_uuid,
                            team_name,
                            team_description);
    free(team_uuid);
    free(team_name);
    free(team_description);
    return 0;
}
