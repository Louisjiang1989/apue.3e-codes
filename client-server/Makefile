GCC=gcc

all:
	make server client

server: server.o sock_common.o
	gcc -o server server.o sock_common.o

client: client.o sock_common.o
	gcc -o client client.o sock_common.o

sock_common.o: sock_common.c 
	gcc -c sock_common.c -I /home/louis/apue/apue.3e-codes/include

server.o: server.c sock_common.c
	gcc -c server.c -I /home/louis/apue/apue.3e-codes/include/


client.o: client.c sock_common.c
	gcc -c client.c -I /home/louis/apue/apue.3e-codes/include/

clean:
	rm -f *.o client server
