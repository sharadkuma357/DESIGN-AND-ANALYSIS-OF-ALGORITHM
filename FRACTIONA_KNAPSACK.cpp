#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(vector<int>&a,vector<int>&b){
    double a1=(1.0*a[0])/a[1];
    double b1=(1.0*b[0])/b[1];
    return a1/b1;
}

double fractional_knapsack(vector<int>val,vector<int>wt,int cap){
    int n=val.size();
    vector<vector<int>>item(n,vector<int>(2));
    for(int i=0;i<n;i++){
        item[i][0]=val[i];
        item[i][1]=wt[i];
    }
    sort(item.begin(),item.end(),compare);
    double res=0.0;
    int current_capacity=cap;
    for(int i=0;i<n;i++){
        if(item[i][1]<=current_capacity){
            res+=item[i][0];
            current_capacity-=item[i][1];
        }else{
            res+=(1.0*item[i][0]/item[i][1])*current_capacity;
            break;
        }
    }
    return res;
}

int main(){
    vector<int>val={60,100,120};
    vector<int>wt={10,20,30};
    int cap=50;
    cout<<fractional_knapsack(val,wt,cap);
    return 0;
}