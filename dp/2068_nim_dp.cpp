/**
 * 两个参赛队各n个成员,1堆石子总数为s
 * 规定每个成员最多能取Mi个石子,Mi不一定相等
 * 实际相当于两人博弈,但每次最多能取的个数是变化的
 * 非公平博弈,dp求解
 * dp[[i][j]表示第i个人面对j个石头时的胜负情况
 * 1表胜,0表负
 * 面对1个石头显然失败(P态),面对0个石头则胜利(N态)
 * 如果一个状态存在一个步骤到达P态(此时让位于其后的对手面临必败),则它为N态
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[20][8200];
int a[20], n;
int solve(int id, int remain){
    if(dp[id][remain]!=-1) return dp[id][remain];
    if(remain==0) return dp[id][remain]=1;
    dp[id][remain]=0;
    for(int i=1;i<=a[id] && i<=remain ;i++){
        if(!solve( (id+1)%(2*n), remain-i ) )
            return dp[id][remain]=1;
    }
    return dp[id][remain];
}
int main(){
    int s;
    while(scanf("%d",&n),n!=0){
        scanf("%d",&s);
        for(int i=0;i<2*n;i++){
            scanf("%d",a+i);
        }
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(0,s));
    }
    return 0;
}
