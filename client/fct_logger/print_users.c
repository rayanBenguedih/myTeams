/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** print_user
*/

#include "../include/client.h"

char *search_token(char *str, char break_symbol, bool previous_same_str)
{
    static int i = 0;
    int j = 0;
    char *buffer = NULL;
    int len = strlen(str);

    i = (previous_same_str == true) ? i + 1 : 0;
    j = i;
    if (i >= len)
        return (NULL);
    while (str[i] != break_symbol) {
        if (str[i] == '\r')
            return NULL;
        i++;
    }
    buffer = malloc(sizeof(char) * (i - j + 1));
    buffer[i - j] = '\0';
    for (int cpt = 0; j < i; j++, cpt++)
        buffer[cpt] = str[j];
    return (buffer);
}

int print_users(char *answer, client_t *_client)
{
    char *token = search_token(answer, ':', false);
    char *user_uuid = NULL;
    char *user_name = NULL;
    int status = -1;

    do {
        user_uuid = strdup(strtok(token, "\a"));
        user_name = strdup(strtok(NULL, "\a"));
        status = atoi(strtok(NULL, "\a"));
        client_print_users(user_uuid, user_name, status);
        free(user_uuid);
        free(user_name);
        free(token);
    } while ((token = search_token(answer, ':', true)) != NULL);
}
