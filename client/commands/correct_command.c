/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** correct_command
*/

#include "../include/client.h"

bool sub_correct_command(char *command)
{
    if (strncmp(command, "/subscribed", 11) == 0)
        return correct_subscribed(command);
    if (strncmp(command, "/unsubscribed", 13) == 0)
        return correct_unsubscribe(command);
    if (strncmp(command, "/use", 4) == 0)
        return correct_use(command);
    if (strncmp(command, "/create", 7) == 0)
        return correct_create(command);
    if (strncmp(command, "/list", 5) == 0)
        return correct_list(command);
    if (strncmp(command, "/info", 4) == 0)
        return correct_info(command);
    return false;
}

bool correct_command(char *command)
{
    if (strncmp(command, "/help", 5) == 0)
        return correct_help(command);
    if (strncmp(command, "/login", 6) == 0)
        return correct_login(command);
    if (strncmp(command, "/logout", 7) == 0)
        return correct_logout(command);
    if (strncmp(command, "/users", 6) == 0)
        return correct_users(command);
    if (strncmp(command, "/user", 5) == 0)
        return correct_user(command);
    if (strncmp(command, "/send", 5) == 0)
        return correct_send(command);
    if (strncmp(command, "/messages", 9) == 0)
        return correct_messages(command);
    if (strncmp(command, "/subscribe", 10) == 0)
        return correct_subscribe(command);
    return (sub_correct_command(command));
}
