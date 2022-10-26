/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** reconnection
*/

#include "include/client.h"

void reconnection(client_t *client)
{
    printf("Reconnection to the server...\n");
    client->socket = my_socket(AF_INET, SOCK_STREAM, 0);
    FD_ZERO(&client->original);
    FD_SET(client->socket, &client->original);
    FD_SET(1, &client->original);
    if (inet_pton(AF_INET, client->ip, &client->addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(84);
    }
    my_connect(client->socket, (struct sockaddr *)&client->addr,
                                                    sizeof(client->addr));
    printf("Reconnection done.\n");
}
