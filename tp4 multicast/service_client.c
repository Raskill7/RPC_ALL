/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "service.h"
#include <rpc/rpc.h>
#include <memory.h> 
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int eachresult(int *out, struct sockaddr_in *addr)
{
	char* serveur = inet_ntoa(addr->sin_addr);
	printf("%s : %d\n",serveur, *out);
	return 0;
}

void
exo1_1()
{

	int  *result_1;
	param  print_somme_1_arg;

	char buffer[1020];
	printf("lecture a\n");
    fgets(buffer, sizeof(buffer), stdin);
    int a = atoi(buffer);
	printf("lecture b\n");
    fgets(buffer, sizeof(buffer), stdin);
    int b = atoi(buffer);

    if(a>b)
    {
    	int c=a;
    	a=b;
    	b=c;
    }
    print_somme_1_arg.borne_inf=a;
    print_somme_1_arg.borne_sup=b;

    printf("appel au client \n");
	result_1 = print_somme_1(&print_somme_1_arg, eachresult);
	if (result_1 == (int *) NULL) {
		perror ("call failed");
	}
}


int
main (int argc, char *argv[])
{
	exo1_1 ();
exit (0);
}
