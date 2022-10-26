/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** communication
*/

#include "include/client.h"

void send_command(client_t *client, char *input)
{
    int uuid_length = 0;
    if (client->uuid == NULL)
        uuid_length = 2 + 1;
    else {
        uuid_length = strlen(client->uuid) + 2 + 1;
    }
    char *command = malloc(sizeof(char) *
                            (uuid_length + strlen(input) + 1));

    strcpy(command, "\"");
    if (client->uuid != NULL)
        command = strcat(command, client->uuid);
    command = strcat(command, "\" ");
    command = strcat(command, input);
    if (client->socket == -1)
        reconnection(client);
    dprintf(client->socket, "%s", command);
    printf("COMMAND SEND: %s\n", command);
    free(command);
}

char *read_socket(client_t *client, char *buffer)
{
    int len = 0;

    printf("Waiting response from the server...\n\n");
    select(client->socket + 1, &client->readable, NULL, NULL, NULL);
    /*
    faire deux fd_isset un sur stdin et l'autre sur les sockets

    */
    ioctl(client->socket, FIONREAD, &len);
    printf("len: %d\n", len);
    if (len > BUFFER_SIZE) {
        free(buffer);
        buffer = malloc(sizeof(char) * (len + 1));
    }
    read(client->socket, buffer, len);
    buffer[len] = '\0';
    return (buffer);
}

void reset_buffer(char *rd, char *wr)
{
    if (rd != NULL)
        free(rd);
    if (wr != NULL)
        free(wr);
    rd = NULL;
    wr = NULL;
    rd = malloc(sizeof(char) * BUFFER_SIZE);
    wr = malloc(sizeof(char) * BUFFER_SIZE);
}

void loop_call_logger(client_t *_client, char *_read)
{
    char *token = strdup(_read);
    char *tmp = token;

    token = strtok(token, "\r");
    printf("TOKEN: %s\n", token);
    while (token != NULL) {
        call_logger(_client, token);
        token = strtok(NULL, "\r");
        printf("NEW TOKEN: %s\n", token);
    }
    free(tmp);
    printf("-----------------------------------\n");
}

int communication(client_t *_client, int a)
{
        int len = 1024;
    while (true) {
        write(1, ">> ", 3);
        _client->readable = _client->original;
        select(_client->socket + 1, &_client->readable, NULL, NULL, NULL);
        if (handle_event_on_client(_client) == 3)
            break;
    }
    return EXIT_SUCCESS;
}
