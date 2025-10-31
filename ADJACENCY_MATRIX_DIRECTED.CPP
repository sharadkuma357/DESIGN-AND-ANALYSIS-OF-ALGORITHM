#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>create(int V,vector<vector<int>>&edges){
    vector<vector<int>>mat(V,vector<int>(V,0));
    for(auto &it:edges){
        int u=it[0];
        int v=it[1];
        mat[u][v]=1;
    }
    return mat;
}

int main(){
    int V=9;
    vector<vector<int>>edges={{1,2},{4,5},{6,7}};
    vector<vector<int>>mat=create(V,edges);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}