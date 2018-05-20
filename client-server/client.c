#include <socket.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 6000
const int BUFF_SIZE = 1024;

int main(int argc, char **argv)
{
    if(argc != 2){
        printf("invalid arguments\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    int err = inet_pton(AF_INET, argv[1], &server_addr.sin_addr.s_addr);
    if(err < 0){
        printf("inet_pton ip %s error %s\n", argv[1], strerror(errno));
        return err;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEFAULT_PORT);

    int conn_sock = louis_socket(AF_INET, SOCK_STREAM, 0);
    int conn_result = louis_connect(conn_sock, (struct sockaddr*)&server_addr, sizeof(struct sockaddr));
    if(conn_result < 0){
        printf("connect to %s error(%s)\n", argv[1], strerror(errno));
        return conn_result;
    }
   
    char input[BUFF_SIZE];
    while(1) {
        memset(input, 0, BUFF_SIZE);
        printf("before: %s\n", input);
        scanf("%1024[^\n]", input);
        printf("input: %s\n", input);
        
        setbuf(stdin, NULL);

        ssize_t send_size = louis_send(conn_sock, input, BUFF_SIZE, 0);
        if(send_size < 0){
            printf("send error %d\n", send_size);
            return -1;
        }

        char output[BUFF_SIZE];
        memset(output, 0, BUFF_SIZE);

        ssize_t recv_size = louis_recv(conn_sock, output, BUFF_SIZE, 0);
        if(recv_size < 0){
            printf("recv from %s error %d\n", argv[1], recv_size);
            return -1;
        }

        printf("recv from %s msg: %s\n", argv[1], output);
    }

    return 0;
}


