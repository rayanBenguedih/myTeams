/*
** EPITECH PROJECT, 2022
** server
** File description:
** initialisation
*/

#include "include/server.h"

void init_connections(teamsData_t *serv, int port)
{
    struct sockaddr_in address;

    serv->socket = my_socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    serv->addr = address;
    serv->addrLen = sizeof(serv->addr);
    my_bind(serv->socket, (struct sockaddr *)&serv->addr, serv->addrLen);
    my_listen(serv->socket, 1024);
}
