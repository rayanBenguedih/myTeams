/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** file used to save all the datas
*/

#include "include/server.h"

char **read_file(char *path, FILE **stream)
{
    char **fileLines = malloc(sizeof(char *) * 1);
    size_t len;
    int i = 0;
    *stream = fopen(path, "a+");

    if (*stream == NULL) {
        perror("Reading a file");
        return (NULL);
    }
    while (getline(&(fileLines[i]), &len, *stream) != -1) {
        i++;
        fileLines = realloc(fileLines, sizeof(char *) * (i + 1));
        if (fileLines == NULL) {
            perror("Reading a file");
            break;
        }
        fileLines[i] = NULL;
    }
    truncate(path, 0);
    return (fileLines);
}

void save_private_message_sender(teamsMessage_t *message)
{
    int fd = -1;
    char *path = malloc_path(2);

    sprintf(path, "Users/%s/%s", message->authoruuid, message->destUuid);
    fd = open(path, O_CREAT | O_APPEND);
    if (fd == -1) {
        perror("Saving private message");
        free(path);
        return;
    }
    dprintf(fd, "%s\n%s\n%s\n%s\r\n", message->destUuid,
        message->authoruuid, message->data, message->content);
    close(fd);
    free(path);
}

void save_private_message(teamsMessage_t *message)
{
    int fd = -1;
    char *path = malloc_path(2);

    sprintf(path, "Users/%s/%s", message->destUuid, message->authoruuid);
    fd = open(path, O_CREAT | O_APPEND);
    if (fd == -1) {
        perror("Saving private message");
        free(path);
        return;
    }
    dprintf(fd, "%s\n%s\n%s\n%s\r\n", message->destUuid,
        message->authoruuid, message->data, message->content);
    close(fd);
    free(path);
    save_private_message_sender(message);
}
