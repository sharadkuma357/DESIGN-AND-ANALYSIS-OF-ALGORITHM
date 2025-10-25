#include<stdio.h>
#include<stdlib.h>

int comparator(const int p1[],const int p2[]){
    
    return p1[2]-p2[2];
}

int findparent(int parent[],int component){
    if(parent[component]==component){
        return component;
    }
    return parent[component]=findparent(parent,parent[component]);
}

int makeset(int parent[],int rank[],int n){
    int i;
    for(i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

void unionset(int u,int v,int parent[],int rank[],int n){
    u=findparent(parent,u);
    v=findparent(parent,v);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }else if(rank[u]>rank[v]){
        parent[v]=u;
    }else{
        parent[v]=u;
        rank[u]++;
    }
}

int krushkal(int n,int edges[n][3]){
    qsort(edges,n,sizeof(edges[0]),comparator);
    int parent[n];
    int rank[n];
    makeset(parent,rank,n);
    int mincost=0;
    for(int i=0;i<n;i++){
        int v1=findparent(parent,edges[i][0]);
        int v2=findparent(parent,edges[i][1]);
        int wt=edges[i][2];
        if(v1!=v2){
            unionset(v1,v2,parent,rank,n);
            mincost+=wt;
        }
    }
    return mincost;
}

int main(){
    int edges[5][3]={{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    printf("%d",krushkal(5,edges));
    return 0;
}