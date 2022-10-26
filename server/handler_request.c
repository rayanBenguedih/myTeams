/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** handler_request
*/

#include "include/server.h"

void accept_client(teamsData_t *serv)
{
    int client = my_accept(serv->socket,
                            (struct sockaddr *)&serv->addr,
                            &serv->addrLen);
    FD_SET(client, &serv->ensemble);
    if (client + 1 > serv->maxFd)
        serv->maxFd = client + 1;
}

void sub_handle(int fd, teamsData_t *serv)
{
    if (fd == serv->socket)
        accept_client(serv);
    else {
        command_execution(serv, fd);
    }
}

void handler_request(teamsData_t *serv)
{
    for (int i = 0; i != serv->maxFd + 1; i++) {
        if (FD_ISSET(i, &serv->ready)) {
            sub_handle(i, serv);
        }
    }
}
