/**
 * 考虑三个格子001(其中1表示放入了X)
 * 当选手面临这一局面时,表示自己在输的局面
 * 无论怎么放都会进入N局面(对手赢),即放与不放无法扭转局势,sg=0
 * 所以对于连续n个空格子,在位置i放格子后
 * i的左右各两个格子对于两选手而言都没有放的必要了,他们存在与否不影响局势
 * 故将他们包括i在内5个格子删去
 * 此时相当与将游戏划分成了在i-3和n-i-2这两串连续空格子上进行决策
 * 则此时sg分解为两个子游戏的nim和
 * 对于边界条件,子游戏格子数非正数时即无法继续在其上操作,sg为0
 */
#include <iostream>
#include <cstdio>
#include <cstring>
const int MAXN=2005;
using namespace std;
int SG[MAXN];
int get_sg(int n){
    if(SG[n]!=-1) return SG[n];
    if(n<=0) return SG[n]=0;
    bool vis[MAXN/8]; //sg用到的值不会太多,故除以8.实际除以2较保险
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
        vis[ get_sg(i-3)^get_sg(n-i-2) ] = true;
    for(int i=0; i<MAXN/8; i++)
        if(!vis[i])
            return SG[n]=i;
}
int main(){
    int n,i;
    while(scanf("%d",&n)!=EOF){
        memset(SG,-1,sizeof(SG));
        if(get_sg(n))
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}
