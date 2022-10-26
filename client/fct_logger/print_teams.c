/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** print_teams
*/

#include "../include/client.h"

int print_teams(char *type)
{
    char *token = search_token(type, ':', false);
    char *team_uuid = NULL;
    char *team_name = NULL;
    char *team_description = NULL;

    do {
        team_uuid = strdup(strtok(token, "\a"));
        team_name = strdup(strtok(NULL, "\a"));
        team_description = strdup(strtok(NULL, "\a"));
        client_print_teams(team_uuid, team_name, team_description);
        free(team_uuid);
        free(team_name);
        free(team_description);
        free(token);
    } while ((token = search_token(type, ':', true)) != NULL);
    return 0;
}
