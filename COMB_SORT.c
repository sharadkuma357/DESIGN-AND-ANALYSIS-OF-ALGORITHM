#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void  swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int getgap(int gap){
    if(gap<=1){
        return 1;
    }
    gap=gap/1.3;
    return gap;
}

void combsort(int arr[],int n){
    int gap=n;
    bool swaped=true;
    while(gap!=1 || swaped==true){
        gap=getgap(gap);
        swaped=false;
        for(int i=0;i<n-gap;i++){
            if(arr[i]>arr[i+gap]){
                swap(&arr[i],&arr[i+gap]);
                swaped=true;
            }
        }
    }
}

int main(){
    int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    combsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}