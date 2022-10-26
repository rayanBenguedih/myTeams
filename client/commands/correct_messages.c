/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** correct_info
*/

#include "../include/client.h"

bool correct_messages(char *input)
{
    regex_t regex;
    int ret = 0;

    ret = regcomp(&regex,
        "^(/messages[ |\t]*)(\"[^\"]{1,255}\"[ |\t]*)$",
                                    REG_EXTENDED | REG_NEWLINE | REG_NOSUB);
    if (ret) {
        printf("Can't compile regex\n");
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
