#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>create(int V,vector<vector<int>>&edges){
    vector<vector<int>>adj(V);
    for(auto &it:edges){
        int u=it[0];
        int v=it[1];
        adj[v].push_back(u);
    }
    return adj;

}

int main(){
    int V=10;
    vector<vector<int>>edges={{3,4},{2,3},{1,5},{3,9}};
    vector<vector<int>>adj=create(V,edges);
    for(int i=0;i<V;i++){
        cout<<i<<":";
        for(auto j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}