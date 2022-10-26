/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** file used to save all the datas
*/

#include "include/server.h"

void subscribe_user(char *userUuid, char *teamsUuid)
{
    char *path = malloc_path(1);
    int fd = -1;

    sprintf(path, "%s/Team", userUuid);
    fd = open(path, O_CREAT | O_APPEND);
    free(path);
    if (fd == -1) {
        perror("Error while subscribing to a team");
        free(path);
        return;
    }
    dprintf(fd, "%s\n", teamsUuid);
    close(fd);
}

bool subscribe(char *userUuid, char *teamsUuid)
{
    char *path = malloc_path(1);
    FILE *stream = NULL;
    bool found = true;
    char **fileConetent = NULL;

    sprintf(path, "%s/User", teamsUuid);
    fileConetent = read_file(path, &stream);
    for (int i = 0; fileConetent != NULL && fileConetent[i] != NULL; i++) {
        if (strcmp(fileConetent[i], userUuid) == 0)
            found = true;
        fprintf(stream, "%s\n", fileConetent[i]);
        free(fileConetent[i]);
    }
    free(path);
    if (fileConetent != NULL)
        free(fileConetent);
    if (found == false)
        fprintf(stream, "%s\n", userUuid);
    fclose(stream);
    return (found);
}

bool unsubscribe_user(char *userUuid, char *teamsUuid)
{
    char *path = malloc_path(1);
    char **fileConetent = NULL;
    FILE *stream = NULL;

    sprintf(path, "%s/Team", teamsUuid);
    fileConetent = read_file(path, &stream);
    for (int i = 0; fileConetent != NULL && fileConetent[i] != NULL; i++) {
        if (strcmp(fileConetent[i], userUuid) != 0)
            fprintf(stream, "%s\n", fileConetent[i]);
        free(fileConetent[i]);
    }
    free(path);
    if (fileConetent != NULL)
        free(fileConetent);
    fclose(stream);
}

bool unsubscribe(char *userUuid, char *teamsUuid)
{
    char *path = malloc_path(1);
    bool found = false;
    char **fileConetent = NULL;
    FILE *stream = NULL;

    sprintf(path, "%s/User", teamsUuid);
    fileConetent = read_file(path, &stream);
    for (int i = 0; fileConetent != NULL && fileConetent[i] != NULL; i++) {
        if (strcmp(fileConetent[i], userUuid) == 0)
            found = true;
        else
            fprintf(stream, "%s\n", fileConetent[i]);
        free(fileConetent[i]);
    }
    free(path);
    if (fileConetent != NULL)
        free(fileConetent);
    fclose(stream);
    return (found);
}
