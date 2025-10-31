#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>create(int V,vector<vector<int>>edges){
    vector<vector<int>>adj(V);
    for(auto &it:edges){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;

}

int main(){
    int V=10;
    vector<vector<int>>edges={{2,3},{4,5},{1,2}};
    vector<vector<int>>adj=create(V,edges);
    for(int i=0;i<V;i++){
        cout<<i<<":";
        for(int j:adj[i]){
            cout<<j<<" ";
        }cout<<endl;
    }
    return 0;
}