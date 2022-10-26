/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** error
*/

#include "include/server.h"

int error(int ac, char **av)
{
    if (ac != 2) {
        dprintf(2, "Error: This program need 1 argument.\n");
        return 84;
    }
    for (int i = 0; i != strlen(av[1]); i++) {
        if (av[1][i] < '0' || av[1][i] > '9') {
            dprintf(2, "Error: The port number must be an integer.\n");
            return 84;
        }
    }
    return 0;
}

char *find_by_name(char *name)
{
    return (NULL);
}

void list_all_coms(teamsData_t *data)
{
    teamsThread_t *tmp = (teamsThread_t *) find_by_uuid(data,
    data->threadUuidUse);
    idata_t *lst;
    teamsMessage_t *msg;
    char *str = malloc(sizeof(char) * 150 * 100);

    if (!tmp)
        return;
    lst = tmp->comsUuidList;
    while (lst != NULL) {
        msg = find_by_uuid(data, lst->uuid);
        if (msg) {
            strcat(str, msg->uuid);
            strcat(str, "\a");
            strcat(str, msg->authorName);
            strcat(str, ":");
        }
        lst = lst->next;
    }
    dprintf(data->commanderSocket, "%s\n\r", str);
}
