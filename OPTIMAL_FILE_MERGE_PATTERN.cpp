#include<bits/stdc++.h>
using namespace std;

int mincomputation(int size,int files[]){
    priority_queue<int,vector<int>,greater<int>>pq;// A PQ IS MADE.
    for(int i=0;i<size;i++){
        pq.push(files[i]);// FILES ELE IS PUSHED INTO PQ
    }
    int cnt=0;// VARIBLE KEEP TRACK 
    while(pq.size()>1){//FIRST ELE IS ADDED TO SECOND PUSHED IN TEMP THEN CNT INCREMENTED IN TEMP THEN TEMP IS PUSHED INTO PQ
        int fst=pq.top();
        pq.pop();
        int snd=pq.top();
        pq.pop();
        int temp=fst+snd;
        cnt+=temp;
        pq.push(temp);
    }
    return cnt;
}

int main(){
    int n=6;
    int files[]={2,3,4,5,6,7};
    cout<<"minimum computation="<<mincomputation(n,files);
    return 0;
}