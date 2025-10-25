#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

vector<vector<vector<int>>>constructadj(vector<vector<int>>&edges,int V){
    vector<vector<vector<int>>>adj(V);
    for(const auto &edges:edges){
        int u=edges[0];
        int v=edges[1];
        int wt=edges[2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    return adj;
}

vector<int>dijkstra(int V,vector<vector<int>>&edges,int scr){
    vector<vector<vector<int>>>adj=constructadj(edges,V);
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
    vector<int>dist(V,INT_MAX);
    pq.push({0,scr});
    dist[scr]=0;
    while(!pq.empty()){
        int u=pq.top()[1];
        pq.pop();
        for(auto x:adj[u]){
            int v=x[0];
            int weight=x[1];
            if(dist[v]>dist[u]+weight){
                dist[v]=dist[u]+weight;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

int main(){
    int V=5;
    int scr=0;
    vector<vector<int>>edges={{0,1,4},{1,4,6},{2,3,2},{3,4,10}};
    vector<int>result=dijkstra(V,edges,scr);
    for(int dist:result){
        cout<<dist<<" ";
    }
    return 0;
}