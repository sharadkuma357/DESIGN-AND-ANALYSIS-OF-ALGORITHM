#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int mincost(vector<int>&arr){
    int totalcost=0;
    while(arr.size()>1){
        sort(arr.begin(),arr.end());
        int first=arr[0];
        int sec=arr[1];
        arr.erase(arr.begin());
        arr.erase(arr.begin());
        int cost=first+sec;
        totalcost+=cost;
        arr.push_back(cost);
    }
    return totalcost;
}

int minCost(vector<int>&arr){
    priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
    int res=0;
    while(pq.size()>1){
        int first=pq.top();
        pq.pop();
        int sec=pq.top();
        pq.pop();
        res+=first+sec;
        pq.push(first+sec);
    }
    return res;
}

int main(){
    vector<int>ropes={4,3,2,6};
    vector<int>rope={4,3,2,6};
    cout<<mincost(ropes)<<endl;
    cout<<minCost(rope)<<endl;
    return 0;
}