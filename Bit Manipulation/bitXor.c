#include <stdio.h>

/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */

int bitXor(int a, int b) {

    return ~(~(a & (a & ~b)) & ~(b & (~a & b)));
}

int main(){
    printf("4^5 = %i\n", bitXor(4,5)); 
    printf("65^22 = %i\n", bitXor(65,22));
    printf("87^22 = %i\n", bitXor(87,22)); 
    printf("65^87 = %i\n", bitXor(65,87));
}