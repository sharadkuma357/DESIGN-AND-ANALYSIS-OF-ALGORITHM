#include<iostream>
#include<vector>
using namespace std;

vector<int>bellmanford(int V,vector<vector<int>>&edges,int scr){
    vector<int>dist(V,1e8);
    dist[scr]=0;
    for(int i=0;i<V;i++){
        for(vector<int>edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                if(i==V-1){
                    return {-1};
                }
                dist[v]=dist[u]+wt;
            }
        }
    }
    return dist;
}

int main(){
    int V=5;
    vector<vector<int>>edges={
        {1, 3, 2}, 
        {4, 3, -1},
        {2, 4, 1}, 
        {1, 2, 1},
        {0, 1, 5} 
    };

    int src = 0;
    vector<int> ans = bellmanford(V, edges, src);

    for(int dist:ans){
        cout<<dist<<" ";
    }

    return 0;
}