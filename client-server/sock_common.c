#include <socket.h>


int louis_socket(int domain, int type, int protocol)
{
    return socket(domain, type, protocol);
}

int louis_bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    return bind(sockfd, addr, addrlen);
}

int louis_listen(int sockfd, int backlog)
{
    return listen(sockfd, backlog);
}

ssize_t louis_send(int sockfd, const void *buf, size_t len, int flags)
{
    return send(sockfd, buf, len, flags);
}

ssize_t louis_sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest_addr, socklen_t addrlen)
{
    return sendto(sockfd, buf, len, flags, dest_addr, addrlen);
}

ssize_t louis_sendmsg(int sockfd, const struct msghdr *msg, int flags)
{
    return sendmsg(sockfd, msg, flags);
}

ssize_t louis_recv(int sockfd, void *buf, size_t len, int flags)
{
	return recv(sockfd, buf, len, flags);
}

ssize_t louis_recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen)
{
	return recvfrom(sockfd, buf, len, flags,  src_addr, addrlen);
}

ssize_t louis_recvmsg(int sockfd, struct msghdr *msg, int flags)
{
	return recvmsg(sockfd, msg, flags);
}

int louis_connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
	return connect(sockfd, addr, addrlen);
}

int louis_accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
    return accept(sockfd, addr, addrlen);
}
