/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** linkedlist_more_azea
*/

#include "include/server.h"

int c_crt(teamsData_t *data)
{
    char *tmUid = malloc(sizeof(char) * strlen(data->command) + 1);
    char *teamsContent = malloc(sizeof(char) * strlen(data->command) + 1);

    strcpy(tmUid, data->command);
    tmUid = strtok(tmUid, " ");
    tmUid = strtok(NULL, " ");
    tmUid = strtok(NULL, "\"");
    strcpy(teamsContent, data->command);
    teamsContent = strtok(teamsContent, " ");
    teamsContent = strtok(NULL, " ");
    teamsContent = strtok(NULL, " ");
    teamsContent = strtok(NULL, "\"");
    if (tmUid == NULL || (teamsContent == NULL && data->threadUuidUse ==
    NULL)) {
        dprintf(data->commanderSocket, "ERROR:ERROR_UNKNOWN\n\r");
        return (0);
    }
    return (1);
}

int c_lan(teamsData_t *data)
{
    return (1);
}

int good_commands(char *tab[], int i, teamsData_t *data)
{
    char *cmaz[] = {"/login", "/user", "/send", "/messages", "/subscribe",
    "/unsubscribe", "/use", "/create", "/list"};
    int (*cmd_checkers[9]) (teamsData_t *d) = {c_lin, c_usr, c_snd,
    c_msg, c_subs, c_usbd, c_use, c_crt, c_lan};

    for (int j = 0; j < 9; j++) {
        if (strcmp(tab[i], cmaz[j]) == 0) {
            printf("%s %s %d %d\n", cmaz[j], tab[i], cmd_checkers[j]
            (data), j);
            return (cmd_checkers[j](data));
        }
    }
    return (1);
}

void reset_data(teamsData_t *data)
{
    data->teamsUuidUse = NULL;
    data->channelUuidUse = NULL;
    data->threadUuidUse = NULL;
}

void run_verif_stairs(int i, teamsData_t *data, char *tabs[], void (*cmds[14])
(teamsData_t *d))
{
    int fd = data->commanderSocket;

    if ((i != 13 && i != 0) && no_uuid_cmd(data) == 1) {
        dprintf(fd, "ERROR:ERROR_UNAUTHORIZED\n\r");
        return;
    }
    if (good_commands(tabs, i, data) == 1)
        cmds[i](data);
}
