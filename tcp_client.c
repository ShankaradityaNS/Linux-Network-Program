#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
void main()
{
	//creating socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM,0);
	
	//specifying address for socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9001);//specifying port to connect to
	server_address.sin_addr.s_addr = INADDR_ANY;//connecting to IP Address
	// INADDR_ANY normally connects to 0.0.0.0
	
	int connection_status = connect(network_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	//checking for errors 
	if(connection_status == -1)
	{
		printf("There was an error while connecting to the remote socket\n");
	}

	//revieving data from server
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0);
	
	//Displaying data sent by server
	printf("The data sent by server: %s\n", server_response);

	//closing socket
	close(network_socket);
}

