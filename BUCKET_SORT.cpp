#include<iostream>
#include<vector>
using namespace std;

void insertion(vector<float>&bi){
    for(int i=1;i<bi.size();i++){
        float key=bi[i];
        int j=i-1;
        while(j>=0 && bi[i]>key){
            bi[j+1]=bi[j];
            j--;
        }
        bi[i]=key;
    }
}

void bucketsort(float arr[],int n){
    vector<float>bi[n];
    for(int i=0;i<n;i++){
        int b=n*arr[i];
        bi[b].push_back(arr[i]);
    }
    for(int i=0;i<n;i++){
        insertion(bi[i]);
    }
    int index=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<bi[i].size();j++){
            arr[index++]=bi[i][j];
        }
    }
}

int main(){
    float arr[]={0.5,0.7,0.3,0.9,0.6};
    int n=sizeof(arr)/sizeof(arr[0]);
    bucketsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}