/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** start
*/

#include "include/server.h"

void loop(int serverfd, struct sockaddr *addr, socklen_t *addrlen,
                                                        teamsData_t *serv)
{
    serv->maxFd = serverfd;
    FD_ZERO(&serv->ensemble);
    FD_SET(serverfd, &serv->ensemble);

    while (true) {
        serv->ready = serv->ensemble;
        select(serv->maxFd + 1, &serv->ready, NULL, NULL, NULL);
        handler_request(serv);
    }
}

void start(int port)
{
    teamsData_t teamDatas;
    init_data(&teamDatas);

    struct sockaddr_in address;
    socklen_t addrLen = sizeof(address);

    teamDatas.socket = my_socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    my_bind(teamDatas.socket, (struct sockaddr *)&address, addrLen);
    my_listen(teamDatas.socket, 1024);
    teamDatas.addr = address;
    teamDatas.addrLen = addrLen;
    printf("Server listening on port %d\n", port);
    loop(teamDatas.socket, (struct sockaddr *)&address, &addrLen, &teamDatas);
}
