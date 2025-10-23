#include<stdlib.h>
#include<limits.h>
#include<stdio.h>

void merge(int arr[],int left,int mid1,int mid2,int right){
    int size1=mid1-left+1;
    int size2=mid2-mid1;
    int size3=right-mid2;
    int *leftarr=(int*)malloc(size1*sizeof(int));
    int *midarr=(int*)malloc(size2*sizeof(int));
    int *rightarr=(int*)malloc(size3*sizeof(int));

    for(int i=0;i<size1;i++){
        leftarr[i]=arr[left+i];
    }
    for(int i=0;i<size2;i++){
        midarr[i]=arr[mid1+i+1];
    }
    for(int i=0;i<size3;i++){
        rightarr[i]=arr[mid2+i+1];
    }

    int i=0;
    int j=0;
    int k=0;
    int index=left;
    while(i<size1||j<size2||k<size3){
        int min=INT_MAX;
        int minidx=-1;
        if(i<size1 &&leftarr[i]<min){
            minidx=0;
            min=leftarr[i];
        }
        if(j<size2 && midarr[j]<min){
            minidx=1;
            min=midarr[j];
        }
        if(k<size3 && rightarr[k]<min){
            minidx=2;
            min=rightarr[k];
        }
        if(minidx==0){
            arr[index++]=leftarr[i++];
        }
        if(minidx==1){
            arr[index++]=midarr[j++];
        }
        if(minidx==2){
            arr[index++]=rightarr[k++];
        }
    }
    free(leftarr);
    free(midarr);
    free(rightarr);

}

void threemergesort(int arr[],int left,int right){
    if(left>=right){
        return;
    }
    int mid1=left+(right-left)/3;
    int mid2=left+2*(right-left)/3;
    threemergesort(arr,left,mid1);
    threemergesort(arr,mid1+1,mid2);
    threemergesort(arr,mid2+1,right);
    merge(arr,left,mid1,mid2,right);
}

int main(){
    int arr[]={5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    threemergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}