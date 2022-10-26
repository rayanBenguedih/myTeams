/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** thread_reply
*/

#include "../include/client.h"

int thread_reply(char *type)
{
    char *team_uuid = strdup(strtok(type, ":"));
    char *thread_uuid = strdup(strtok(NULL, ":"));
    char *user_uuid = strdup(strtok(NULL, ":"));
    char *reply_body = strdup(strtok(NULL, "\n"));

    client_event_thread_reply_received(team_uuid,
                                        thread_uuid,
                                        user_uuid,
                                        reply_body);
    free(team_uuid);
    free(thread_uuid);
    free(user_uuid);
    free(reply_body);
    return 0;
}
