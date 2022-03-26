#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
void main()
{
	char server_message[256] = "You have reached the server";
	
	//creating socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	//defining server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	//binding socket to specified port and IP address
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

	listen(server_socket, 5);

	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);

	send(client_socket, server_message, sizeof(server_message),0);

	close(server_socket);
}
