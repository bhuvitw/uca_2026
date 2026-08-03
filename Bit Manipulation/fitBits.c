#include <stdio.h>

/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */

// int fitsBits(int x, int n) {
//   return 0;
// }

int main() {
   printf("%i\n", -~(0&~-1));  
}