#include<stdio.h>
int main(){
    int no;
    printf("enter an number:");
    scanf("%d",&no);
    int div = no/2;
    int mo = div * 2;
    if(no == mo){
        printf("even no");
    }
    else{printf("odd no");}
    return 0;
}