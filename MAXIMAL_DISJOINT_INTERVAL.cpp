#include<bits/stdc++.h>
using namespace std;

bool comp(const vector<int>&a,const vector<int>&b){
    return (a[1]<b[1]);
}

vector<vector<int>>getdis(vector<vector<int>>&arr){
    sort(arr.begin(),arr.end(),comp);
    int end=-1;
    vector<vector<int>>ans;
    for(int i=0;i<arr.size();i++){
        if(arr[i][0]>end){
            ans.push_back(arr[i]);
            end=arr[i][1];
        }
    }
    return ans;
}

int main(){
    vector<vector<int>>arr={{1,4},{2,3},{4,6},{8,9}};
    vector<vector<int>>ans=getdis(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}