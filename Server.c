#include "client-server.h"
//49002 port


int main (int argc,char** argv){

    if(argc == 2) {
        
        char* net = argv[1];
        char* port = argv[1];

        struct sockaddr_in saddr;

    

        printf("Socket get ready!!\n");

        int s = socket(AF_INET,SOCK_DGRAM,0);
        if(s<0){
            perror("wrong socket");
            printf("Bad socket,exit");
            exit(1);
        }
        printf("Socket ok\n");
        
        saddr.sin_family = AF_INET;
        saddr.sin_addr.s_addr = htonl(INADDR_ANY);
        saddr.sin_port = argv[1]; // htons

        printf("%i \n",saddr.sin_port);

        printf("DEBUG: BEFORE bind\n");
        if(bind(s, (struct sockaddr *) &saddr, sizeof(saddr)) < 0){
            perror("Wrong bind");
            printf("Bad bind,exit");
            exit(2);
        }

        printf("Bind ok\n");

        int bytes_read;
        int buf[1024];
        int num=0;


        printf("DEBUG: BEFORE WHILE\n");

        while(num < 10){
            bytes_read = recvfrom(s,buf,1024,0,NULL,NULL);
            buf [bytes_read] ='\0';
            printf("%s ,\n",buf);
            printf("wait...\n");
            num++;
        }

        close(s);
        shutdown(s,2);
        printf("close\n");
        printf("%i",num);

    return 0;
    }else {
        printf("wrong argc\n");
        exit(-1);

    }


}

