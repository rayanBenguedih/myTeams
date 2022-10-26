/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** evenmore_lister
*/

#include "include/server.h"

void call_list(teamsData_t *data)
{
    if (data->context == -1)
        list_all_teams(data);
    if (data->context == 3)
        list_all_channels(data);
    if (data->context == 2)
        list_all_threads(data);
    if (data->context == 4)
        list_all_coms(data);
}

void show_users_info(teamsData_t *data)
{
    teamsUsers_t *user;
    idata_t *lst;
    char *userUuid = strdup(data->command);

    userUuid = strtok(userUuid, "\"");
    user = (teamsUsers_t *) find_by_uuid(data, userUuid);
    if (!user)
        return;
    dprintf(data->commanderSocket, "OK:PRINT_USER:%s:%s:%d:", user->uuid,
    user->name, user->con);
    lst = user->teamsUuidList;
    while (lst != NULL) {
        dprintf(data->commanderSocket, "%s:", lst->uuid);
        lst = lst->next;
    }
    dprintf(data->commanderSocket, "\n\r");
}

void fill_my_string_with_stuff(char *str, teamsServ_t *tmp)
{
    strcat(str, "OK:PRINT_TEAM:");
    strcat(str, tmp->uuid);
    strcat(str, ":");
    strcat(str, tmp->name);
    strcat(str, ":");
    strcat(str, tmp->description);
    strcat(str, ":");
}

void show_teams_info(teamsData_t *data)
{
    teamsServ_t *tmp = (teamsServ_t*) find_by_uuid(data, data->teamsUuidUse);
    idata_t *lst;
    teamsUsers_t *rs = data->users;
    teamsChannels_t *stp = data->teamsChannel;
    char *str = malloc(sizeof(char) * 150 * 100);

    if (!tmp)
        return;
    fill_my_string_with_stuff(str, tmp);
    lst = tmp->channelsUuidList;
    while (lst != NULL) {
        strcat(str, lst->uuid);
        strcat(str, "\a");
        lst = lst->next;
    }
    dprintf(data->commanderSocket, "%s\n\r", str);
    free(str);
}
