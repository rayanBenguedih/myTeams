/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** more_listers
*/

#include "include/server.h"

void fill_thread_mommy(teamsData_t *data, char *body, char *title,
teamsThread_t *dta)
{
    uuid_t binuuid;
    teamsThread_t *dt = data->teamsThreads;

    dta->title = strdup(title);
    dta->content = strdup(body);
    dta->type = malloc(sizeof(char) * 2);
    dta->type[0] = '4';
    dta->timing = malloc(sizeof(char) * 20);
    dta->uuid = malloc(sizeof(char) * UUID_LEN);
    dta->chansUuid = strdup(data->channelUuidUse);
    dta->authoruuid = strdup(strtok(strdup(data->command), "\""));
    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, dta->uuid);
    dta->next = NULL;
    if (dt != NULL) {
        while (dt->next != NULL)
            dt = dt->next;
        dt->next = dta;
    } else
        data->teamsThreads = dta;
}

void creation_printing(teamsData_t *data, char *body, char *title)
{
    char *authUuid = strdup(data->command);
    teamsUsers_t *usr = data->users;
    teamsThread_t *dta = malloc(sizeof(teamsThread_t) * 1);

    fill_thread_mommy(data, body, title, dta);
    my_long_to_ascii(time(NULL), dta->timing, 10);
    dprintf(data->commanderSocket, "OK:THREAD_CREATE:%s:%s:%s:%s:%s\n\r",
    dta->uuid, dta->authoruuid, dta->timing, dta->title, dta->content);
    while (usr) {
        if (usr->con == 1 && user_is_in_team(usr, data->teamsUuidUse) == 1)
            dprintf(usr->fd, "OK:PRINT_THREAD_CREATED:%s:%s:%s:%s:%s\n\r",
            dta->uuid, dta->authoruuid, dta->timing, dta->title,
            dta->content);
        usr = usr->next;
    }
    server_event_thread_created(dta->chansUuid, dta->uuid,
    dta->authoruuid, dta->title, dta->content);
    free(body);
    free(title);
}

void dont_nest_things(idata_t *lst, teamsData_t *data, teamsUsers_t *tmp,
char *uuid)
{
    if (strcmp(lst->uuid, uuid) == 0) {
        dprintf(data->commanderSocket, "%s\a%s\a%d:", tmp->uuid,
        tmp->name, tmp->con);
    }
}

void display_all_users(char *uuid, teamsData_t *data)
{
    teamsUsers_t *tmp = data->users;
    idata_t *lst = tmp->teamsUuidList;

    if (lst == NULL)
        return;
    while (tmp != NULL) {
        while (lst != NULL) {
            dont_nest_things(lst, data, tmp, uuid);
            lst = lst->next;
        }
        dprintf(data->commanderSocket, ":");
        tmp = tmp->next;
    }
}
