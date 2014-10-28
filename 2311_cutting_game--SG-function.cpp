/**
 * SG函数
 * 当面对两个块G1,G2时,SG(G1,G2)=SG(G1)^SG(G2)
 * 终止状态为1*1,其SG值为0
 * 易知2*2,2*3,3*3的SG值也为0,因为无论怎么切都能导致1*n
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int sg[202][202];
int dfs(int w, int h){
    if(sg[w][h]!=-1) return sg[w][h];
    bool vis[202]={false};
    for(int i=2; i<=w/2; i++)
        vis[ dfs(i,h) ^ dfs(w-i,h) ] = true;
    for(int i=2; i<=h/2; i++)
        vis[ dfs(w,i) ^ dfs(w,h-i)] =true;
    for(int i=0; ;i++)
        if(!vis[i])
            return sg[w][h]=i; //从0起未出现过的第一个即是mex
}
int main(){
    int n,m;
    memset(sg,-1,sizeof(sg));
    while(scanf("%d%d",&n,&m)!=EOF){
        if(dfs(n,m))
            printf("WIN\n");
        else
            printf("LOSE\n");
    }
    return 0;
}
