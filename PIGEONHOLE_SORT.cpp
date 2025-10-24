#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void pigeon(int arr[],int n){
    int max=INT_MIN,min=INT_MAX;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
        if(min>arr[i]){
            min=arr[i];
        }
    }

    int range=max-min+1;
    vector<vector<int>>holes(range);
    for(int i=0;i<n;i++){
        holes[arr[i]-min].push_back(arr[i]);
    }
    int index=0;
    for(int i=0;i<range;i++){
        
        for(int j=0;j<holes[i].size();j++){
            arr[index++]=holes[i][j];
        }
    }
}

int main(){
    int arr[]={6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    pigeon(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}