/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
#include <stdio.h>


int conditional(int x, int y, int z) {
    int val = !!x;
    int mask = ~val + 1; 
    int result = (mask  & y) | (~mask & z); 
    return result; 
}

int main() {
    int x = 2;
    int y = 4;
    int z = 5;
    printf("for %i ? %i : %i --> %i\n",x,y,z, conditional(x,y,z)); 
}
