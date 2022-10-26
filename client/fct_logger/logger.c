/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** logger
*/

#include "../include/client.h"

int subsub_logger(char *type, client_t *_client)
{
    printf("Dans subsub\n");
    if (strcmp(type, "PRINT_CHANNEL") == 0)
        return print_channel(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_THREAD") == 0)
        return print_thread(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_TEAM_CREATED") == 0)
        return print_team_created(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_CHANNEL_CREATED") == 0)
        return print_channel_created(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_THREAD_CREATED") == 0)
        return print_thread_created(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_THREAD_REPLY_CREATED") == 0)
        return print_thread_reply_created(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_SUBSCRIBED") == 0)
        return print_subscribed(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_UNSUBSCRIBED") == 0)
        return print_unsubscribed(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRIVATE_MSG_PRINT_MSG") == 0)
        return private_msg_print_msg(strtok(NULL, "\n\r"));
    return 0;
}

int sub_logger(char *type, client_t *_client)
{
    printf("Dans sublog\n");
    if (strcmp(type, "CHANNEL_CREATED") == 0)
        return channel_created(strtok(NULL, "\n\r"));
    if (strcmp(type, "THREAD_CREATE") == 0)
        return thread_create(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_USERS") == 0)
        return print_users(strtok(NULL, "\n\r"), _client);
    if (strcmp(type, "PRINT_TEAMS") == 0)
        return print_teams(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_CHANNELS") == 0)
        return print_channels(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_THREADS") == 0)
        return print_threads(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_REPLIES") == 0)
        return print_replies(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_USER") == 0)
        return print_user(strtok(NULL, "\n\r"));
    if (strcmp(type, "PRINT_TEAM") == 0)
        return print_team(strtok(NULL, "\n\r"), _client);
    return subsub_logger(type, _client);
}

int help_m(char *str)
{
    printf("%s\n", str);
    return EXIT_SUCCESS;
}

int logger(char *answer, client_t *_client)
{
    char *type = strtok(answer, ":");

    printf("Type: %s\n\n", type);
    if (type == NULL)
        return EXIT_FAILURE;
    if (strcmp(type, "LOGGED_IN") == 0)
        return log_in(strtok(NULL, "\n\r"), _client);
    if (strcmp(type, "LOGGED_OUT") == 0)
        return log_out(strtok(NULL, "\n\r"), _client);
    if (strcmp(type, "PRIVATE_MESSAGE_RECEIVED") == 0)
        return private_message_receive(strtok(NULL, "\n\r"));
    if (strcmp(type, "THREAD_REPLY_RECEIVE") == 0)
        return thread_reply(strtok(NULL, "\n\r"));
    if (strcmp(type, "TEAM_CREATED") == 0)
        return team_created(strtok(NULL, "\n\r"));
    if (strcmp(type, "UNKNOWN") == 0)
        return (printf("All good\n\n"));
    if (strcmp(type, "HELP") == 0)
        return (help_m(strtok(NULL, "\0")));
    return sub_logger(type, _client);
}
