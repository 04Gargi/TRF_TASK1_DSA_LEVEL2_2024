#include<stdio.h>

int main () {
    float num;
    printf("Enter number: ");
    scanf("%f",&num);
    // even and odd without %
    /*
        12/2 = 6
        12.0/2 = 6.0
        11/2 = 5
        11.0/2 = 5.5
    */
    float half = num / 2;
    printf("%f\n",half);
    if (half == (int)half) {
        printf("this is even");
    } else {
        printf("this is odd");
    }
    return 0;
}