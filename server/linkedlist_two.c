/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** linkedlist_more_aze
*/

#include "include/server.h"

int c_snd(teamsData_t *data)
{
    char *userUuid = malloc(sizeof(char) * strlen(data->command) + 1);
    char *content = malloc(sizeof(char) * strlen(data->command) + 1);

    strcpy(userUuid, data->command);
    userUuid = strtok(userUuid, " ");
    userUuid = strtok(NULL, " ");
    userUuid = strtok(NULL, "\"");
    strcpy(content, data->command);
    content = strtok(content, " ");
    content = strtok(NULL, " ");
    content = strtok(NULL, " ");
    content = strtok(NULL, "\"");
    if (content == NULL || userUuid == NULL ||
    find_by_uuid(data, userUuid) == NULL) {
        dprintf(data->commanderSocket, "ERROR:ERROR_UNKNOWN\n\r");
        return (0);
    }
    return (1);
}

int c_msg(teamsData_t *data)
{
    char *userUuid = malloc(sizeof(char) * strlen(data->command) + 1);

    strcpy(userUuid, data->command);
    userUuid = strtok(userUuid, " ");
    userUuid = strtok(NULL, " ");
    userUuid = strtok(NULL, "\"");
    if (userUuid == NULL || find_by_uuid(data, userUuid) == NULL ||
    strcmp(userUuid, strtok(strdup(data->command), "\"")) == 0) {
        dprintf(data->commanderSocket, "ERROR:ERROR_UNKNOWN\n\r");
        return (0);
    }
    return (1);
}

int c_subs(teamsData_t *data)
{
    char *teamUuid = malloc(sizeof(char) * strlen(data->command) + 1);

    strcpy(teamUuid, data->command);
    teamUuid = strtok(teamUuid, " ");
    teamUuid = strtok(NULL, " ");
    teamUuid = strtok(NULL, "\"");
    if (teamUuid == NULL || find_by_uuid(data, teamUuid) == NULL) {
        dprintf(data->commanderSocket, "ERROR:ERROR_UNKNOWN\n\r");
        return (0);
    }
    return (1);
}

int c_usbd(teamsData_t *data)
{
    char *teamUuid = malloc(sizeof(char) * strlen(data->command) + 1);

    strcpy(teamUuid, data->command);
    teamUuid = strtok(teamUuid, " ");
    teamUuid = strtok(NULL, " ");
    teamUuid = strtok(NULL, "\"");
    if (teamUuid == NULL || find_by_uuid(data, teamUuid) == NULL) {
        dprintf(data->commanderSocket, "ERROR:ERROR_UNKNOWN\n\r");
        return (0);
    }
    return (1);
}

int c_use(teamsData_t *data)
{
    char *teamUuid = malloc(sizeof(char) * strlen(data->command) + 1);

    strcpy(teamUuid, data->command);
    teamUuid = strtok(teamUuid, " ");
    teamUuid = strtok(NULL, " ");
    teamUuid = strtok(NULL, "\"");
    if (teamUuid == NULL || find_by_uuid(data, teamUuid) == NULL) {
        dprintf(data->commanderSocket, "ERROR:ERROR_UNKNOWN\n\r");
        return (0);
    }
    return (1);
}
