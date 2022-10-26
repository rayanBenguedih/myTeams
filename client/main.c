/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** main
*/

#include "include/client.h"

int help(void)
{
    printf("USAGE: ./myteams_cli ip port\n\n");
    printf("      ip    is the server ip address on which the ");
    printf("server socket listens\n");
    printf("      port  is the port number on which the server socket ");
    printf("listens.\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return help();
    if (error(ac, av) == 84)
        return 84;
    launch(av[1], atoi(av[2]));
    return 0;
}
