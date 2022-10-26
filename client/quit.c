/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** quit
*/

#include "include/client.h"

int quit(client_t *client, char *str1, char *str2)
{
    send_command(client, "/logout\n");
    close(client->socket);
    printf("Disconnected !");
    if (client->uuid != NULL)
        free(client->uuid);
    if (str1 != NULL)
        free(str1);
    if (str2 != NULL)
        free(str2);
    return 3;
}
