#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>jobsequencing(vector<int>deadline,vector<int>profit){
    int n=deadline.size();
    vector<int>ans={0,0};
    vector<pair<int,int>>job;
    for(int i=0;i<n;i++){
        job.push_back({deadline[i],profit[i]});
    }
    sort(job.begin(),job.end());
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<job.size();i++){
        if(job[i].first<pq.size()){
            pq.push(job[i].second);
        }else if(!pq.empty() && pq.top()<job[i].second){
            pq.pop();
            pq.push(job[i].second);
        }
    }
    while(!pq.empty()){
        ans[1]+=pq.top();
        pq.pop();
        ans[0]++;
    }
}

int main(){
    vector<int>deadline={1,2,1,1,2};
    vector<int>profit={100,30,60,40,80};
    vector<int>ans=jobsequencing(deadline,profit);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}