#include<stdlib.h>
#include<stdio.h>

int main(){
    int arr[]={7,6,5,4,3,2,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int gap=n/2;gap>0;gap/=2){
        int i;
        for(i=gap;i<n;i++){
            int temp=arr[i];
            int j=i;
            for( j=i;j>=gap && arr[j-gap]<temp;j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }
    for(int j=0;j<n;j++){
        printf("%d ",arr[j]);
    }
    return 0;
}