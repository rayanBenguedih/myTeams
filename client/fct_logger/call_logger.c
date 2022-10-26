/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** call_logger
*/

#include "../include/client.h"

int client_error_unknown(void)
{
    printf("Unknown error\n");
    return (84);
}

int error_logger(char *answer)
{
    char *type = strtok(answer, ":");

    printf("TYPE ERROR: %s\n", type);
    if (type == NULL)
        client_error_unknown();
    if (strcmp(answer, "ERROR_UNKNOWN_TEAM") == 0)
        return client_error_unknown_team(strtok(NULL, "\n\r"));
    if (strcmp(answer, "ERROR_UNKNOWN_CHANNEL") == 0)
        return client_error_unknown_channel(strtok(NULL, "\n\r"));
    if (strcmp(answer, "ERROR_UNKNOWN_USER") == 0)
        return client_error_unknown_user(strtok(NULL, "\n\r"));
    if (strcmp(answer, "ERROR_UNKNOWN_THREAD") == 0)
        return client_error_unknown_thread(strtok(NULL, "\n\r"));
    if (strcmp(answer, "ERROR_UNAUTHORIZED") == 0)
        return client_error_unauthorized();
    if (strcmp(answer, "ERROR_ALREADY_EXIST") == 0)
        return client_error_already_exist();
    if (strcmp(answer, "UNKNOWN") == 0)
        return client_error_unknown();
    return 0;
}

void call_logger(client_t *_client, char *_read)
{
    if (strlen(_read) == 0) {
        printf("ERROR: Empty answer\n");
        return;
    }
    char *status = strdup(_read);
    char *tmp = status;

    status = strtok(status, ":");
    printf("Status: %s\n", status);
    if (status == NULL)
        return;
    if (strcmp(status, "OK") != 0)
        error_logger(strtok(NULL, "\n\r"));
    else
        logger(strtok(NULL, "\n\r"), _client);
    free(tmp);
}
