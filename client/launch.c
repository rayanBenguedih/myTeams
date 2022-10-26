/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** launch
*/

#include "include/client.h"

void init_client(client_t *client, char *ip, int port)
{
    client->socket = -1;
    client->port = port;
    client->ip = ip;
    client->uuid = NULL;
    client->addr.sin_family = AF_INET;
    client->addr.sin_port = htons(client->port);
    client->addr.sin_addr.s_addr = inet_addr(client->ip);
}

void launch(char *ip, int port)
{
    client_t client;
    init_client(&client, ip, port);
    int ret = 0;

    client.socket = my_socket(AF_INET, SOCK_STREAM, 0);
    FD_ZERO(&client.original);
    FD_SET(client.socket, &client.original);
    FD_SET(0, &client.original);
    if (inet_pton(AF_INET, ip, &client.addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(84);
    }
    my_connect(client.socket, (struct sockaddr *)&client.addr,
                                                    sizeof(client.addr));
    communication(&client, ret);
}
