/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** correct_info
*/

#include "../include/client.h"

bool correct_help(char *input)
{
    regex_t regex;
    int ret = 0;

    ret = regcomp(&regex,
                "/help[ |\t]*[\n]", 0);
    if (ret) {
        printf("Can't compile\n");
        return false;
    }
    ret = regexec(&regex, input, 0, NULL, 0);
    regfree(&regex);
    if (ret == REG_NOMATCH) {
        printf("Invalid arguments.\n");
        return false;
    }
    return true;
}
