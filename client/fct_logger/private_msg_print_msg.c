/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** private_msg_print_msg
*/

#include "../include/client.h"

char *reverse_str(char *str)
{
    char *new_str = malloc(sizeof(char) * strlen(str) + 1);

    for (int i = strlen(str); i >= 0; i--)
        new_str[i] = str[strlen(str) - i - 1];
    printf("NEW TIMESTAMP: %s\n", new_str);
    free(str);
    return new_str;
}

int private_msg_print_msg(char *type)
{
    char *token = search_token(type, ':', false);
    char *sender_uuid = NULL;
    char *message_body = NULL;
    time_t timestamp;

    do {
        sender_uuid = strdup(strtok(token, "\a"));
        message_body = strdup(strtok(NULL, "\a"));
        timestamp = atol(reverse_str(strdup(strtok(NULL, "\a"))));
        client_private_message_print_messages(sender_uuid,
                                            timestamp,
                                            message_body);
        free(sender_uuid);
        free(message_body);
        free(token);
    } while ((token = search_token(type, ':', true)) != NULL);
    return 0;

}
