#include <stdio.h>
#include <string.h>

void ReverseString(char* string);

int main(int argc , char *argv[]){

    
    char text[] = "HEllo World!!?A";
    
    ReverseString(text);
    
    printf("Reversed: %s",text);
    
    
    
    return 0;
}

void ReverseString(char* str){
    char* start = str;
    char* end = str+ strlen(str)-1;

    while (start<end)
    {
        char temp = *end;
        *end = *start;
        *start = temp;
        start++;
        end--;
    }
    
    
}

