/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** file used to create the teams, channels, and threads
*/

#include "include/server.h"

char *malloc_path(size_t nb_uuid)
{
    char *path = malloc(sizeof(char) * (UUID_LEN * nb_uuid + 5));

    if (path == NULL) {
        perror("Error while allocating memory for a path");
        exit(84);
    }
    path[UUID_LEN * nb_uuid + 4] = '\0';
    return (path);
}

void create_teams(teamsServ_t *new)
{
    int fdir = mkdir(new->uuid, S_IRWXU);
    int fd = 0;
    char *path = malloc_path(1);

    if (fdir < 0) {
        perror("Teams creation");
        return;
    }
    sprintf(path, "%s/%s", new->uuid, "Conf");
    fd = open(path, O_CREAT);
    if (fd < 0) {
        perror("Teams creation");
        return;
    }
    dprintf(fd, "%s\n%s\n\nChannels uuid:\n", new->name, new->description);
    close(fd);
    free(path);
}

void create_channel(teamsChannels_t *new)
{
    int fd = 0;
    int fdir = 0;
    char *path = malloc_path(2);

    sprintf(path, "%s/%s", new->teamsUuid, new->uuid);
    fdir = mkdir(path, S_IRWXU);
    if (fdir < 0)
        return;
    close(fdir);
    sprintf(path, "%s/%s", path, "Conf");
    fd = open(path, O_CREAT);
    if (fd < 0)
        return;
    dprintf(fd, "Message:\n%s\n\nCreator:\n%s", new->messageContent,
        new->authorName);
    close(fd);
    free(path);
}

void create_thread(teamsData_t *data, teamsThread_t *new, int fd, int fdir)
{
    char *path = malloc_path(3);
    teamsChannels_t *chan = find_by_uuid(data, new->chansUuid);

    sprintf(path, "%s/%s/%s", chan->teamsUuid, new->chansUuid, new->uuid);
    fdir = mkdir(path, S_IRWXU);
    if (fdir < 0) {
        perror("Thread creation");
        return;
    }
    close(fdir);
    sprintf(path, "%s/%s", path, "Conf");
    fd = open(path, O_CREAT);
    if (fd < 0) {
        perror("Thread creation");
        return;
    }
    dprintf(fd, "%s\n%s\n\nCreator UUID:\n%s", new->title, new->content,
        new->authoruuid);
    close(fd);
    free(path);
}

void create_user(teamsUsers_t *new)
{
    int fdir = mkdir("Users", S_IRWXU);
    int fd = 0;
    char *path = malloc_path(2);

    sprintf(path, "Users/%s", new->uuid);
    if (fdir < 0 || mkdir(path, S_IRWXU)) {
        perror("User creation");
        return;
    }
    sprintf(path, "Users/%s/%s", new->uuid, "Conf");
    fd = open(path, O_CREAT);
    if (fd < 0) {
        perror("User creation");
        return;
    }
    dprintf(fd, "%s\n", new->name);
    close(fd);
    free(path);
}
