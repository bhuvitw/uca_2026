#include<stdio.h>
#include<stdlib.h>

int findNum(int num[], int len){
    int bits[32] = {0}; 

    for(int i = 0; i<len; i++){
        int n = num[i]; 
        for(int j = 0; j<32;j++){
            bits[j] += (n >> j) & 1; 
        }
    }

    int res = 0; 
    for(int i = 0; i<32; i++){
        if(bits[i]%3!=0){
            res|= 1 << i;
        }
    }

    return res; 

}

int main(){
    int num[] = {1, 2, 3, 4, 1, 2, 4, 1, 2, 3, 4, 3, 5, 5, 5, 5};
    int len = sizeof(num)/sizeof(int); 
    int ans = findNum(num, len); 

    printf("Number Repeating 4 times: %d\n", ans); 
}