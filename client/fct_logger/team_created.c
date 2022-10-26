/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** team_created
*/

#include "../include/client.h"

int team_created(char *type)
{
    char *team_uuid = strdup(strtok(type, ":"));
    char *team_name = strdup(strtok(NULL, ":"));
    char *team_description = strdup(strtok(NULL, ":"));

    client_event_team_created(team_uuid,
                                team_name,
                                team_description);
    free(team_uuid);
    free(team_name);
    free(team_description);
    return 0;
}
