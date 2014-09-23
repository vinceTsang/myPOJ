#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int dp[12881];
int max(int i,int j){
    return i>j?i:j;
}
int main(){
    memset(dp,0,sizeof(dp));
    int n,m,i,j;
    int w[3403],d[3403];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d%d",&w[i],&d[i]);
    }
    int bound=0;
    for(i=0;i<n;i++){
        for(int k=i+1;k<n;k++)  bound+=w[k];
        bound=max(m-bound,w[i]);
        for(j=m;j>=bound;j--){
            dp[j]=max( dp[j], dp[ j-w[i] ] + d[i] );
        }
    }
    printf("%d\n",dp[m]);
}
