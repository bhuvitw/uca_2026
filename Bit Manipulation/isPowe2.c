/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
#include <stdio.h>
#include <math.h>

int isPower2(int x) {
    return (x>0) & ((x & x-1)==0); 
}

int main() {
    printf("32 is Power 2?\n%s\n", isPower2(32)==1 ? "yes" : "no"); 
    
}