/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** print_user
*/

#include "../include/client.h"

int print_user(char *type)
{
    char *user_uuid = strdup(strtok(type, ":"));
    char *user_name = strdup(strtok(NULL, ":"));
    int user_status = atol(strtok(NULL, "\n"));

    client_print_user(user_uuid,
                        user_name,
                        user_status);
    free(user_uuid);
    free(user_name);
    return 0;
}
