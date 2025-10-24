#include<stdio.h>
#include<stdlib.h>

int getmax(int arr[],int n){
    int max;
    for(int i=0;i<n;i++){
        max=arr[0];
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}

void count(int arr[],int n,int exp){
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }

    for(int i=1;i<sizeof(count);i++){
        count[i]=count[i]+count[i-1];
    }
    int *output=(int*)malloc(n*sizeof(int));
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void radix_sort(int arr[],int n){
    int m=getmax(arr,n);

    for(int exp=1;exp<m;exp=exp*10){
        count(arr,n,exp);
    }
}

int main(){
    int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    radix_sort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}