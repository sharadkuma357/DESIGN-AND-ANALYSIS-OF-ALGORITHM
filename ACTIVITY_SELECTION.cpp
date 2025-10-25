#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int activityselection(vector<int>&start,vector<int>&finish){
    int ans=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
    for(int i=0;i<start.size();i++){
        p.push(make_pair(finish[i],start[i]));
    }
    int finishtime=-1;
    while(!p.empty()){
        pair<int,int>activity=p.top();
        p.pop();
        if(activity.second>finishtime){
            finishtime=activity.first;
            ans++;
        }
    }
    return ans;
} 

int main(){
    vector<int>start={1,3,0,5,8,5};
    vector<int>finish={2,4,6,7,9,9};
    cout<<activityselection(start,finish);
    return 0;
}