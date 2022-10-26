/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** error
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int free_return(char *target, int status)
{
    free(target);
    target = NULL;
    return status;
}

int validate_ip(char *ip)
{
    int dots = 0;
    char *cpy = strdup(ip);
    char *tmp = cpy;

    cpy = strtok(cpy, ".");
    if (cpy == NULL) {
        free(tmp);
        return 0;
    }
    while (cpy) {
        dots++;
        if (is_number(cpy) == false)
            return free_return(tmp, EXIT_FAILURE);
        if (atoi(cpy) > 255 || atoi(cpy) < 0)
            return free_return(tmp, EXIT_FAILURE);
        cpy = strtok(NULL, ".");
    }
    free(tmp);
    return (dots != 4) ? EXIT_FAILURE : EXIT_SUCCESS;
}

int error(int ac, char **av)
{
    if (ac != 3) {
        dprintf(2, "Error: This program need 2 argument.\n");
        return 84;
    }
    if (validate_ip(av[1]) == EXIT_FAILURE) {
        dprintf(2, "Error: The IP address is invalid.\n");
        return 84;
    }
    for (int i = 0; i != strlen(av[2]); i++) {
        if (av[2][i] < '0' || av[2][i] > '9') {
            dprintf(2, "Error: The port number must be an integer.\n");
            return 84;
        }
    }
    return 0;
}
