#include <stdio.h>
#include <string.h>

int my_strlen(const char *str) {
    int length = 0; 
    while(str[length]!='\0'){    
        length++; 
    }
    return length; 
}

int main() {
    char str[] = "My name is bhuvnesh";
    printf("%i\n", my_strlen(str)); 
}