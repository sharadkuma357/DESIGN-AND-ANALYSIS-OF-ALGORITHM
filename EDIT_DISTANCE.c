#include<stdio.h>
#include<string.h>

int min(int x,int y,int z){
    return (x>y)?((x>z)?x:z):((y>z)?y:z);
}

int editdist(char *s1,char *s2,int m,int n){
    if(m==0)return n;
    if(n==0)return m;
    if(s1[m-1]==s2[n-1]){
        return editdist(s1,s2,m-1,n-1);
    }
    return 1+min(editdist(s1,s2,m-1,n),editdist(s1,s2,m-1,n-1),editdist(s1,s2,m,n-1));
}

int main(){
    char s1[]="abcd";
    char s2[]="bcfe";
    printf("%d\n",editdist(s1,s2,strlen(s1),strlen(s2)));
    return 0;
}