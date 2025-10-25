#include<stdlib.h>
#include<stdio.h>

int compare(const void *a,const void *b){
    return (*(int*)b-*(int*)a);
}

int mincoins(int coins[],int n,int amount){
    qsort(coins,n,sizeof(int),compare);
    int res=0;
    for(int i=0;i<n;i++){
        if(amount>=coins[i]){
            int cnt=(amount/coins[i]);
            res+=cnt;
            amount-=cnt*coins[i];
        }
        if(amount==0){
            break;
        }
    }
    return res;
}

int main(){
    int coins[10]={5,2,10,1};
    int n=sizeof(coins)/sizeof(coins[0]);
    int amount=39;
    printf("%d\t",mincoins(coins,n,amount));
    return 0;
}