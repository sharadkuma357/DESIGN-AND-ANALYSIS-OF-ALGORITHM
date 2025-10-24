#include<stdio.h>
#include<stdlib.h>
//defective code for 0 value
void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}
void cyclesort(int arr[],int n){
    int i;
    while(i<n){
        int correct=arr[i]-1;
        if(arr[i]!=arr[correct]){
            swap(arr[i],arr[correct]);
        }else{
            i++;
        }
    }
}
int main(){
    int arr[]={6,5,4,3,2,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    cyclesort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}