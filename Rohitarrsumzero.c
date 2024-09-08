#include<stdio.h>
int main(){
    int arr[] = {0,1,-1,-2,2,0};
    for(int i=0; i<6 ; i++){
        for(int j = i+1; j<6 ; j++){
            for(int k = j+1; k<6 ; k++){
                if(arr[i] + arr[j] == 0){//2'sn sum
                printf("%d and %d are 2 nos \n",arr[i],arr[j]);}
                if(arr[i] + arr[j] + arr[k] == 0){ //3's sum
                    printf("%d %d and %d are 3 nos\n",arr[i],arr[j],arr[k]);
                }
            }
        }
    }
}