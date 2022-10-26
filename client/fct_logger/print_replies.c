/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** print_replies
*/

#include "../include/client.h"

int print_replies(char *type)
{
    char *thread_uuid = strdup(strtok(type, ":"));
    char *user_uuid = strdup(strtok(NULL, ":"));
    time_t time = atol(strtok(NULL, ":"));
    char *reply_body = strdup(strtok(NULL, "\n"));

    client_thread_print_replies(thread_uuid,
                                user_uuid,
                                time,
                                reply_body);
    free(thread_uuid);
    free(user_uuid);
    free(reply_body);
    return 0;
}
