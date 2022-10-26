/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** command_execution
*/

#include "include/server.h"

void command_execution(teamsData_t *serv, int clientFd)
{
    if (serv->command == NULL)
        serv->command = malloc(sizeof(char) * 1024);
    int rd = read(clientFd, serv->command, 1024);
    if (rd == 0)
        return;
    serv->command[rd] = '\0';
    handle_server(serv, clientFd);
}

void call_login(teamsData_t *data)
{
    char *userName = malloc(sizeof(char) * strlen(data->command) + 1);
    char *str;
    teamsUsers_t *usr;

    strcpy(userName, data->command);
    userName = strtok(userName, " ");
    userName = strtok(NULL, " ");
    userName = strtok(NULL, "\"");
    str = malloc(sizeof(char) * strlen(userName) + 1);
    strcpy(str, userName);
    str[strlen(userName)] = '\0';
    if (already_exist(str, data) == 0) {
        user_push_back(str, data, data->commanderSocket);
        usr = data->users;
        while (usr->next != NULL)
            usr = usr->next;
        dprintf(data->commanderSocket, "OK:LOGGED_IN:%s:%s\n\r", usr->uuid,
        userName);
    }
}

void call_logout(teamsData_t *data)
{
    char *userUuid = malloc(sizeof(char) * strlen(data->command) + 1);
    teamsUsers_t *usr;

    strcpy(userUuid, data->command);
    userUuid = strtok(userUuid, "\"");
    usr = (teamsUsers_t *) find_by_uuid(data, userUuid);
    if (!usr) {
        dprintf(data->commanderSocket, "ERROR:ERROR_UNKNOW_USER:%s\n\r",
        userUuid);
        return;
    }
    usr->con = 0;
    dprintf(data->commanderSocket, "OK:LOGGED_OUT:%s:%s\n\r", usr->uuid,
    usr->name);
    server_event_user_logged_out(userUuid);
    shutdown(usr->fd, SHUT_RDWR);
    close(usr->fd);
    FD_CLR((usr->fd), &(data->ensemble));
    usr->fd = -1;
}

char *save_livining(int i, int tmp, char *buffer, int j)
{
    while (i >= 0) {
        tmp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = tmp;
        i--;
        j++;
    }
}

char *my_long_to_ascii(long num, char *buffer, int base)
{
    int i = 0;
    int j = 0;
    int tmp = 0;

    if (num == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return (buffer);
    }
    while (num != 0) {
        tmp = num % base;
        if (tmp < 10)
            buffer[i++] = tmp + '0';
        else
            buffer[i++] = tmp + 'a' - 10;
        num = num / base;
    }
    buffer[i--] = '\0';
    return (save_livining(i, tmp, buffer, j));
}
