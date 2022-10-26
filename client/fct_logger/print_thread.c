/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** print_thread
*/

#include "../include/client.h"

int print_thread(char *type)
{
    char *thread_uuid = strdup(strtok(type, ":"));
    char *user_uuid = strdup(strtok(NULL, ":"));
    time_t thread_timestamp = atoi(strtok(NULL, ":"));
    char *thread_title = strdup(strtok(NULL, ":"));
    char *thread_body = strdup(strtok(NULL, "\n"));

    client_print_thread(thread_uuid,
                        user_uuid,
                        thread_timestamp,
                        thread_title,
                        thread_body);
    free(thread_uuid);
    free(user_uuid);
    free(thread_title);
    free(thread_body);
    return 0;
}
