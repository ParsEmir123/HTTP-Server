// Windows için bunları ekle
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <string.h>



int main(int argc , char *argv[]){

    // --- Windows'a Özel Başlatma Kodu ---
    WSADATA wsaData;
    int iResult;

    // Winsock'u Başlat
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        fprintf(stderr, "WSAStartup failed: %d\n", iResult);
        return 1;
    }
    // --- Başlatma Kodu Bitti ---




    //SETTING UP THE VARIABLES
    struct addrinfo hints;
    struct addrinfo *res;
    
    memset(&hints,0,sizeof hints);
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family =   AF_UNSPEC;
    
    
    
    //USING THE FUNC
    
    int status = getaddrinfo(argv[1],NULL,&hints,&res);
    if(status != 0){
        printf("Error!!");
        return status;
        
    }


    printf("IP ADRESSES FOR %s \n\n",argv[1]);
    struct addrinfo *pAdrinf;
    for(pAdrinf = res;pAdrinf!=NULL; pAdrinf = pAdrinf->ai_next){

        void *addr;
        char ipstr[INET6_ADDRSTRLEN];
        char *ipver;
        struct sockaddr_in *ipv4;
        struct  sockaddr_in6* ipv6;
        if(pAdrinf->ai_family == AF_INET){
            ipv4 = (struct sockaddr_in *)pAdrinf->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
            
        }else{
            ipv6 = (struct sockaddr_in6 *)pAdrinf->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }
        
        inet_ntop(pAdrinf->ai_family,addr,ipstr,sizeof ipstr);
        printf("%s,%s",ipver,ipstr);
    }



    return 0;
}
