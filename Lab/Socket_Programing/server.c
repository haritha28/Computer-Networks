#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main (int argc, char *argv[]){

  int server_fd, server_socket, client_socket, value_read;
  struct sockaddr_in address;
  //int opt = 1;
  //int addrlen = sizeof(address);
  char buffer[1024] = {0};
  int n ;

  //establishing a socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
    printf("Connection error\n", );
    return -1;
  }
  //clearing the server
  bzero((char * )&serv_addr, sizeof(serv_addr));

  //giving the server details
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_family = INADDR_ANY;
  serv_addr.sin_port = htons(PORT) ; converts to host network byte order

  //binding i,e forcefully attaching the socket to port
  if(bind (server_fd, (struct sockaddr *)&address), sizeof(address) < 0){
    printf("Binding failure\n", );
  }

  //lsitening
  lsiten(socket_fd, 2);
  client_len = sizeof(cli_addr);

  //creating a new socket address for my client
  client_socket = accept(socket_fd, (struct sockaddr *&address), &client_len);

  if(client_socket < 0) {
    printf("Acceptance error\n", );
    return -1;
  }

  //Read the message from the client_socket*
  n = read(client_socket, buffer, 1024);

  if (n < 0) {
    printf("Error in reading from the socket\n", );
  } else {
    printf("The message is%s\n",buffer );
  }

  //Send some message to the client
  n = write(client_socket,"I got your message", 18);

  if (n < 0) {
      printf("Error in sending from the socket\n", );
  }

return 0;
}
