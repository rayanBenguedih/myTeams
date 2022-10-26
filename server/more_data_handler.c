/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** more_data_handler
*/

#include "include/server.h"

void show_threads_info(teamsData_t *data)
{
    teamsThread_t *tmp = (teamsThread_t*) find_by_uuid(data,
    data->threadUuidUse);

    if (!tmp)
        return;
    dprintf(data->commanderSocket, "OK:PRINT_THREAD:%s:%s:%s:%s:%s\n\r",
    tmp->uuid, tmp->authoruuid, tmp->timing, tmp->title, tmp->content);
}

void call_info(teamsData_t *data)
{
    char *commandUuid = malloc(sizeof(char) * strlen(data->command));
    teamsUsers_t *user;

    strcpy(commandUuid, data->command);
    commandUuid = strtok(commandUuid, " ");
    commandUuid = strtok(NULL, " ");
    commandUuid = strtok(NULL, "\"");
    user = (teamsUsers_t *) find_by_uuid(data, commandUuid);
    if (user == NULL)
        user = (teamsUsers_t *) find_by_uuid(data,
        strtok(strdup(data->command), "\""));
    if (user->type[0] == '0')
        show_users_info(data);
    if (user->type[0] == '3')
        show_teams_info(data);
    if (user->type[0] == '2')
        show_channels_info(data);
    if (user->type[0] == '4')
        show_threads_info(data);
}

int users_nums(teamsData_t *data)
{
    int size = 0;
    teamsUsers_t *tmp = data->users;

    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    return (size + 1);
}

void my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

int total_us_sum(teamsData_t *data)
{
    int size = 1;
    teamsUsers_t *tmp = data->users;

    while (tmp != NULL) {
        size += strlen(tmp->name) + strlen(tmp->uuid) + 2 + 5;
        tmp = tmp->next;
    }
    return (size);
}
