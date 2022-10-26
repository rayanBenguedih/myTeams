/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** correct_info
*/

#include "../include/client.h"

bool len_message(char *input)
{
    int cpt = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '"')
            cpt++;
    }
    if (cpt != 2)
        return true;
    char *message = strdup(input);
    char *tmp = message;

    message = strtok(message, "\"");
    message = strtok(NULL, "\"");
    printf("MESSAGE: %s\n", message);
    if (strlen(message) > 512) {
        printf("Message too long.\n");
        free(tmp);
        return false;
    }
    free(tmp);
    return true;
}

bool correct_create(char *input)
{
    regex_t regex;
    int ret = 0;

    ret = regcomp(&regex,
        "^(/create[ |\t]*)(\"[^\"]{1,255}\"[ |\t]*){1,2}$",
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
    return len_message(input);
}
