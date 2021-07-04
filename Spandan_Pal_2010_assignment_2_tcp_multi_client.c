/*			
TCP Multi Client Program
Spandan Pal | 1811100002010 
Computer Networking Lab Assignment 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>
#define PORT 4455
extern int errno;
int main()
{
	int id;
	struct sockaddr_in ser;

	//OPEN A SOCKET
	id = socket(AF_INET, SOCK_STREAM, 0);
	puts(strerror(errno));

	memset(&ser, '\0', sizeof(ser));

	//ASSIGNING IP AND PORT
	ser.sin_family = AF_INET;
	ser.sin_port = htons(PORT);
	ser.sin_addr.s_addr = inet_addr("127.0.0.1");

	//SENDING CONNECTION REQUEST
	connect(id, (struct sockaddr *)&ser, sizeof(ser));
	puts(strerror(errno));

	//WRITING DATA TO THE SOCKET
	char a[10];
	strcpy(a, "hello");
	printf("\nTo Server: %s\t", a);
	write(id, (void *)a, strlen(a) + 1);

	//CLOSING THE SOCKET
	close(id);
}
