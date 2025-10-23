#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("enter size");
    scanf("%d",&n);
    int* arr=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
        if(arr[i]>arr[j]){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }

    return 0;
}