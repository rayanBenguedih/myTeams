/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** use_extra
*/

#include "include/server.h"

char *get_second_arg(teamsData_t *data)
{
    char *str = strdup(data->command);

    if (str == NULL)
        return (NULL);
    str = strtok(str, " ");
    str = strtok(NULL, " ");
    str = strtok(NULL, "\"");
    return (str);
}

char *get_third_arg(teamsData_t *data)
{
    char *str = strdup(data->command);

    if (str == NULL)
        return (NULL);
    str = strtok(str, " ");
    str = strtok(NULL, " ");
    str = strtok(NULL, " ");
    str = strtok(NULL, "\"");
    return (str);
}

char *get_fourth_arg(teamsData_t *data)
{
    char *str = strdup(data->command);

    if (str == NULL)
        return (NULL);
    str = strtok(str, "\"");
    return (str);
}
