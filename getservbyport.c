#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
	// Parse commmand line args
	if(argc != 2) {
		printf("ERROR:\tArgumental error\nUSAGE:\t%s <port>\n", argv[0]);
		exit(1);
	}

	// Parse port number in args, convert from char* to int
	int portNumber = atoi(argv[1]);
	if(portNumber < 1 || portNumber > 65535) {
		printf("ERROR:\tInvalid port number: %s\nUSAGE:\t%s <port>\n", argv[1], argv[0]);
		exit(2);
	}

	// Magic
	struct servent *service = getservbyport(htons(portNumber), NULL);
	if (service == NULL) {
		printf("%s:unknown\n", argv[1]);
	} else {
		printf("%s:%s\n", argv[1], service->s_name);
	}

	return 0;
}
