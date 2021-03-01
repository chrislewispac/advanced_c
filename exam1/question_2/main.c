// Draw the stack trace for the following recursive function:

#include <stdio.h>

float recursive1(float k, int xval);

float recursive1(float k, int xval) {
    
    if (k < 0) { printf("Error: k must be non-negative"); return 0; }
    else if (k == 0) return(1);
    else if (k == 1) return (xval);
    else return (( (2*k)-1 ) * xval * recursive1(k-1, xval) - (k-1)*recursive1(k-2, xval))/k;
};
 
int main(void) {
   printf("%f \n", recursive1(2, 3));
   return 0;
};