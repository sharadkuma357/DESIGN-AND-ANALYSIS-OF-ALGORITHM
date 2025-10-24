#include<stdlib.h>
#include<stdio.h>
//for decreaing only
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high;j++){
        if(arr[j]>pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

int quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main(){
    int arr[]={7,6,4,5,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}