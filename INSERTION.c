#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[]={3,7,6,4,1,2,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j+1]<arr[j]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}