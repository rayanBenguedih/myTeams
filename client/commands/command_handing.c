/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** command_handing
*/

#include "../include/client.h"

int command_handling(client_t *_client, char *input)
{
    input[0] = input[0] == '\n' ? '\0' : input[0];
    if (strlen(input) == 0) {
        printf("NULL command\n");
        return EXIT_FAILURE;
    }
    if (input[0] != '/') {
        printf("Command begin with a '/'.\n");
        return EXIT_FAILURE;
    }
    if (correct_command(input) == false) {
        printf("Invalid command.\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
