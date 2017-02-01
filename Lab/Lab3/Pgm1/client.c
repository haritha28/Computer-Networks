#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
int main () {

	int first_socket;

	char message[100];

	//Create a Socket: mention the domain, type and protocol

	first_socket = socket(int AF_INET6, int SOCK_STREAM , int 0);

	if (first_socket < 0) {
		perror("Error in opening the Socket");
	}

	//Connect the socket to server address 
	if (connect (first_socket,(struct sockaddr)*&server_addr, sizeof(server_addr)) < 0) {
		perror("Error in connecting!");
		exit(1);
	} 

	

}