/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** handle_correct_socket
*/

#include "include/client.h"

int handler_socket(client_t* client, int fd)
{
    char *_write = malloc(sizeof(char) * BUFFER_SIZE);
    char *_read = malloc(sizeof(char) * BUFFER_SIZE);
    size_t len = BUFFER_SIZE;
    int a = 0;

    if (FD_ISSET(fd, &client->readable) && fd == 0) {
        if ((a = getline(&_write, &len, stdin)) == -1)
            return quit(client, _read, _write);
        if (command_handling(client, _write) == EXIT_FAILURE)
            return EXIT_FAILURE;
        send_command(client, _write);
    } else if (FD_ISSET(fd, &client->readable) && fd == client->socket) {
        _read = read_socket(client, _read);
        loop_call_logger(client, _read);
    } else
        return EXIT_FAILURE;
}

int handle_event_on_client(client_t *client)
{
    for (int i = 0; i != client->socket + 1; i++) {
        if (handler_socket(client, i) == 3)
            return 3;
    }
    return (EXIT_SUCCESS);
}
