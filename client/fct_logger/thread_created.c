/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** logger_thread_created
*/

#include "../include/client.h"

int thread_create(char *type)
{
    char *thread_uuid = strdup(strtok(NULL, ":"));
    char *user_uuid = strdup(strtok(NULL, ":"));
    time_t time = atol(strtok(NULL, ":"));
    char *thread_title = strdup(strtok(NULL, ":"));
    char *thread_body = strdup(strtok(NULL, "\n"));

    client_event_thread_created(thread_uuid,
                                user_uuid,
                                time,
                                thread_title,
                                thread_body);
    free(thread_uuid);
    free(user_uuid);
    free(thread_title);
    free(thread_body);
    return (0);
}
