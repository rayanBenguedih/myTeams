/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** strlen_net
*/

int strlen_net(char *str)
{
    int i = 0;

    while (1) {
        if (i > 2 && str[i] != '\r' && str[i - 1] != '\n')
            break;
        i++;
    }
    return i;
}
