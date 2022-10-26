/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-simon.auduberteau
** File description:
** teams
*/

#ifndef TEAMS_H_
    #define TEAMS_H_
    #include <sys/socket.h>
    #include <sys/select.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>

int my_bind(int serverfd, const struct sockaddr *addr, socklen_t addrlen);
int my_listen(int serverfd, int n);
int my_socket(int domain, int type, int protocol);
int my_accept(int serverfd, struct sockaddr *addr, socklen_t *addrlen);
int my_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

#endif /* !TEAMS_H_ */
