/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
#include <stdio.h>

int bang(int x) {
  int neg_x =  ~x + 1;
  int combined_sign = (x | neg_x) >> 31;

  return combined_sign + 1; 
}

int main() {
    for(int i = 0; i<13; i++){

        int x = i; 
        printf("!%i = %i \n", x, bang(x)); 
    }
}
