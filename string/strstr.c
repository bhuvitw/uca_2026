#include <stdio.h>

int find_substring(const char *haystack, const char *needle) {

    if(needle[0] == '\0') return 0; 

    for (int i = 0; haystack[i] != '\0'; i++){
        int j = 0; 

        while (haystack[i+j] == needle[j]){
            j++; 

            if(needle[j] == '\0') return i; 

            if(haystack[i + j] == '\0')  return -1; 
        }
    }
    return -1;     
}

int main() {
    const char *haystack = "Embedded Systems";
    const char *needle = "bed";
    
    int index = find_substring(haystack, needle);
    printf("%d\n", index);
    
    return 0;

}