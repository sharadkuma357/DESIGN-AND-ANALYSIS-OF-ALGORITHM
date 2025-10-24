#include<stdio.h>
#include<stdlib.h>
int main(){
    int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        int key=arr[i];
        for(int j=i-1;j>=0;j--){
            if(key<arr[j]){
                int temp=arr[j];
                arr[j]=key;
                key=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}