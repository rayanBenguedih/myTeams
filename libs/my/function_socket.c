/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myftp-simon.auduberteau
** File description:
** functionmy_socket
*/

#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>

/**
** @brief Permit to bind a socket and check if it's possible.
** @param serverfd The socket of the newly created server.
** @param addr The sockaddr structure of the server.
** @param addrlen The size of the sockaddr structure.
** @return 0 if the bind function succeed,
** otherwise the function exit the program.
*/
int my_bind(int serverfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int my_bind = -1;
    my_bind = bind(serverfd, addr, addrlen);

    if (my_bind == -1) {
        perror("bind");
        exit(84);
    }
    return 0;
}

/**
** @brief Prepare to accept connections on socket FD.
** N connection requests will be queued before further requests are refused.
** @param serverfd The socket to listen to.
** @param n The maximum length to queue.
** @return 0 if the function succeed, otherwise the function exit the program.
*/
int my_listen(int serverfd, int n)
{
    int my_listen = -1;
    my_listen = listen(serverfd, n);

    if (my_listen == -1) {
        perror("listen");
        exit(84);
    }
    return 0;
}

/**
** @brief Create a new socket.
** @param domain The domain of the socket.
** @param type The type of the socket.
** @param protocol The protocol of the socket.
** @return The new socket if it succed, otherwise the
** function exit the program.
*/
int my_socket(int domain, int type, int protocol)
{
    int serverfd = -1;

    serverfd = socket(domain, type, protocol);
    if (serverfd == -1) {
        perror("socket");
        exit(84);
    }
    return serverfd;
}

/**
** @brief Await a connection on socket FD. When a connection arrives,
** open a new socket to communicate with it, set *ADDR
** (which is *ADDR_LEN bytes long) to the address of the connecting peer and
** *ADDR_LEN to the address's actual length, and return the new socket's
** descriptor, or -1 for errors.
** @param serverfd The socket of the newly created server.
** @param addr The sockaddr structure of the server.
** @param addrlen The size of the sockaddr structure.
** @return 0 if the function succed to connect with the client, otherwise the
** function exit the program.
*/
int my_accept(int serverfd, struct sockaddr *addr, socklen_t *addrlen)
{
    int newfd = -1;

    newfd = accept(serverfd, addr, addrlen);
    if (newfd == -1)
        exit(84);
    return newfd;
}

/**
** @brief Open a connection on socket FD to peer at ADDR (which LEN bytes lon
**g)
** @param sockfd The socket of the newly created client's socket.
** @param addr The sockaddr structure of the client.
** @param addrlen The size of the addr structure.
** @return 0 if the connect function succeed, otherwise the function
** exit the program.
*/
int my_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int my_connect = -1;

    my_connect = connect(sockfd, addr, addrlen);
    if (my_connect == -1) {
        perror("connect");
        exit(84);
    }
    return 0;
}
