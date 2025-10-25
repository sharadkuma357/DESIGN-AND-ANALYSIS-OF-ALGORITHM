#include<stdio.h>
#include<string.h>

#define MAX 1000

int max(int a,int b){
    return (a>b)?a:b;
}

int lcsres(char* s1, char* s2, int m, int n, int memo[MAX][MAX]){
    // Base case
    if(m==0||n==0){
        return 0;
    }
    
    // Check memo
    if(memo[m][n]!=-1){
        return memo[m][n];
    }
    
    // Characters match
    if(s1[m-1]==s2[n-1]){
        memo[m][n]=1+lcsres(s1,s2,m-1,n-1,memo);
    }
    // Characters don't match
    else{
        memo[m][n]=max(lcsres(s1,s2,m-1,n,memo),lcsres(s1,s2,m,n-1,memo));
    }
    
    return memo[m][n];
}

int lcs(char* s1, char* s2){
    int m=strlen(s1);
    int n=strlen(s2);
    int memo[MAX][MAX];
    
    // Initialize memo table
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            memo[i][j]=-1;
        }
    }
    return lcsres(s1,s2,m,n,memo);
}

int main(){
    char s1[]="ASDF";
    char s2[]="QAWSDF";
    int result=lcs(s1,s2);
    printf("LCS length: %d\n",result);
    return 0;
}