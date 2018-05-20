#include <socket.h>

#define DEFAULT_PORT 6000
const int BUFF_LEN = 1024;

int main(int argc, char **argv)
{
	int sock = louis_socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		printf("client socket create error(%s)\n", strerror(errno));
		return sock;
	}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
    printf("port: %d\n", DEFAULT_PORT);
	addr.sin_port = htons(DEFAULT_PORT);
    printf("sin_port: %d\n", addr.sin_port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(louis_bind(sock, (struct sockaddr*)&addr, sizeof(struct sockaddr)) < 0){
		printf("client bind error(%s)\n", strerror(errno));
		return errno;
	}

	if(louis_listen(sock, 10) < 0){
		printf("server listen error(%s)\n", strerror(errno));
		return errno;
	}

	struct sockaddr_in remote_addr;
	char recv_buf[BUFF_LEN];
	char send_buf[BUFF_LEN];
    socklen_t sock_len = sizeof(struct sockaddr);
	int conn_sock = louis_accept(sock, (struct sockaddr*)&remote_addr, &sock_len);
	if(conn_sock < 0){
		printf("server accept error(%s)\n", strerror(errno));
        close(conn_sock);
		return conn_sock;
	}

    while(1) {
		memset(recv_buf, 0, BUFF_LEN);
		memset(send_buf, 0, BUFF_LEN);
		//start to send/recv data
		ssize_t recv_size = louis_recv(conn_sock, recv_buf, BUFF_LEN, 0);
		if(recv_size < 0){
			printf("server receive error(%d)\n", recv_size);
			continue;
		}

		printf("server resv msg(%s)\n", recv_buf);

		ssize_t send_size = louis_send(conn_sock, recv_buf, BUFF_LEN, 0);
		if(send_size < 0){
			printf("server send error(%d)\n", send_size);
			continue;
		}

	}
	
	return 0;
}
