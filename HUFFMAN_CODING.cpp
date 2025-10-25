#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left,*right;
    Node(int x){
        data=x;
        left=nullptr;
        right=nullptr;
    }
};

class Compare{
public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};

void preorder(Node* root,vector<string>&ans,string curr){
    if(root==nullptr)return;
    if(root->left==nullptr && root->right==nullptr){
        ans.push_back(curr);
        return;
    }
    preorder(root->left,ans,curr+'0');
    preorder(root->right,ans,curr+'1');

}

vector<string>huffman(string s,vector<int>freq){
    int n=s.length();
    priority_queue<Node*,vector<Node*>,Compare>pq;
    for(int i=0;i<n;i++){
        Node* temp=new Node(freq[i]);
        pq.push(temp);
    }
    while(pq.size()>=2){
        Node* l=pq.top();
        pq.pop();
        Node* r=pq.top();
        pq.pop();
        Node* newnode=new Node(l->data+r->data);
        newnode->left=l;
        newnode->right=r;
        pq.push(newnode);
    }
    Node* root=pq.top();
    vector<string>ans;
    preorder(root,ans,"");
    return ans;
}

int main(){
    string s="abcdef";
    vector<int>freq={5,9,12,13,16,45};
    vector<string>ans=huffman(s,freq);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}