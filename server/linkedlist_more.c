/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** linkedlist_more
*/

#include "include/server.h"

void execute_commanding_commands(teamsData_t *data, void (*cmds[14])
(teamsData_t *d), int fd, char *parsed_cmd)
{
    char *tabs[] = {"/login", "/logout", "/users", "/user", "/send",
    "/messages", "/subscribe", "/subscribed", "/unsubscribe", "/use",
    "/create", "/list", "/info", "/help"};

    for (int i = 0; i < 14; i++) {
        if (strcmp(tabs[i], parsed_cmd) == 0) {
            run_verif_stairs(i, data, tabs, cmds);
        }
    }
}

void handle_server(teamsData_t *data, int fd)
{
    void (*cmds[14])(teamsData_t *d) = {call_login, call_logout, call_users,
    call_user, call_send, call_messages, call_subscribe, call_subscribed,
    call_unsubscribe, call_use, call_create, call_list, call_info, c_hlp};
    char *parsed_cmd = data_parse(data->command);

    run_preliminaries(data, fd);
    execute_commanding_commands(data, cmds, fd, parsed_cmd);
    reset_data(data);
}
