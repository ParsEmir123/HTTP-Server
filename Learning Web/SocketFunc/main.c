#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <string.h>



int main(int argc , char *argv[]){

    #pragma region windows starting code
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
    
    #pragma endregion
    
    
    
    
    
    
    
    
    
    
    return 0;
}