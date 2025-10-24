#include<stdio.h>
#include<stdlib.h>
// defective code for 0
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void cyclesort(int arr[],int n){
    for(int i=0;i<n;i++){
        int correct=arr[i]-1;
        if(arr[correct]!=arr[i]){
            swap(&arr[correct],&arr[i]);
        }else{
            i++;
        }
    }
}

int main(){
    int arr[]={5,4,3,2,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    cyclesort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}