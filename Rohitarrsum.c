#include<stdio.h>
int main(){
    int arr[] = {1,2,3,4,5};
    for(int i=0; i<5 ; i++){
        for(int j = i; j<5 ; j++){
            if(arr[i] + arr[j] == 9){
                printf("%d and %d are 2 nos ,",arr[i],arr[j]);
            }
        }
    }
}