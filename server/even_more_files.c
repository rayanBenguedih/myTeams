/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** even_more_files
*/

#include "include/server.h"
#include <math.h>

void fill_to_print(teamsUsers_t *tmp, char *str1, char *buff)
{
    while (tmp != NULL) {
        strcat(str1, tmp->uuid);
        strcat(str1, "\a");
        strcat(str1, tmp->name);
        strcat(str1, "\a");
        buff[0] = tmp->con + '0';
        buff[1] = '\0';
        strcat(str1, buff);
        strcat(str1, ":");
        tmp = tmp->next;
    }
}

int pow_to_two(int x, int base)
{
    double d = log(x - 1) / log(base);
    int i = d;

    return pow(base, d + 1);
}

void call_users(teamsData_t *data)
{
    teamsUsers_t *tmp = data->users;
    int sizeOfMalloc = total_us_sum(data) + 15;
    char *buffer;
    char *to_print;

    buffer = malloc(sizeof(char) * 2);
    to_print = malloc(sizeof(char) * pow_to_two(sizeOfMalloc, 10));
    fill_to_print(tmp, to_print, buffer);
    if (!buffer || !to_print) {
        dprintf(data->commanderSocket, "ERROR:ERROR_UNKNOWN\n\r");
        return;
    }
    dprintf(data->commanderSocket, "OK:PRINT_USERS:%s\n\r", to_print);
    liberate(to_print, buffer);
    tmp = NULL;
}

char *data_parse(char *str)
{
    char *tmp = malloc(sizeof(char) * strlen(str) + 1);
    int startcpy = 0;
    int k = 0;

    strcpy(tmp, str);
    tmp = strtok(tmp, " ");
    tmp = strtok(NULL, " ");
    if (!tmp)
        return (NULL);
    for (int i = 0; tmp[i]; i++) {
        if (tmp[i] == '\n')
            tmp[i] = '\0';
    }
    return (tmp);
}
