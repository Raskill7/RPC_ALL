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
	/*
	static char* server;
	memset(&server,0,sizeof(server));
	int error=getnameinfo((struct sockaddr*)addr, sizeof(struct sockaddr_storage),server, 16, NULL, 0, NI_NUMERICHOST );
	if(error!=0)
	{
		perror(gai_strerror(error));
		exit(1);
	}
	*/
	char* serveur = inet_ntoa(addr->sin_addr);
	printf(" coucou %s \n", serveur);
	printf("Reponse reçue  : %d\n", *out);
	return 0;
}

void
exo1_1()
{

	int  *result_1;
	param  print_somme_1_arg;

	char sentence[1000];
	printf("lecture a\n");
    fgets(sentence, sizeof(sentence), stdin);
    int a = atoi(sentence);
	printf("lecture b\n");
    fgets(sentence, sizeof(sentence), stdin);
    int b = atoi(sentence);

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
