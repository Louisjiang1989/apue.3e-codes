#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>

int louis_socket(int domain, int type, int procotol);
int louis_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int louis_listen(int sockfd, int backlog);
int louis_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

int louis_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

ssize_t louis_send(int sockfd, const void *buf, size_t len, int flags);

ssize_t louis_sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen);

ssize_t louis_sendmsg(int sockfd, const struct msghdr *msg, int flags);

ssize_t louis_recv(int sockfd, void *buf, size_t len, int flags);

ssize_t louis_recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);






ssize_t louis_recvmsg(int sockfd, struct msghdr *msg, int flags);


