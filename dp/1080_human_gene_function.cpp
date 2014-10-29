/*
 * 经典dp
 * LCS变型
 * dp[i][j]表示s1前i个字符与s2前j个字符可取得的最大值
 * 转移方程为dp[i][j]=max{ dp[i-1][j-1]+matrx[i][j],
 *                         dp[i-1][j]+matrx[i]['-'],
 *                         dp[i][j-1]+matrx['-'][j]
 *                       }
 * 三项分别表示为
 * i与j对应;
 * i与'-'对应,而j与i-1求dp,即在j后插入'-';
 * i后插入'-';
 * 注意初始化时,分别计算两个串前若干个字符均与空串对应,即均与'-'对应
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXV=110;
int matrix[5][5]={
    5,-1,-2,-1,-3,
    -1,5,-3,-2,-4,
    -2,-3,5,-2,-2,  
    -1,-2,-2,5,-1,  
    -3,-4,-2,-1,0
};
int GetId(char a){
    switch(a){
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        //case '-': return 4;
    }
}

int max(int a, int b, int c){
    if(a>=b && a>=c) return a;
    if(b>=a && b>=c) return b;
    return c;
}

int main(){
    int len1,len2,T,i,j,t1,t2,t3;
    char s1[MAXV],s2[MAXV];
    int dp[MAXV][MAXV];
    scanf("%d",&T);
    while(T--){
        scanf("%d%s%d%s",&len1,s1,&len2,s2);
        memset(dp,0,sizeof(dp));
        dp[0][0]=0;
        for(i=1;i<=len1;i++)
            dp[i][0]=dp[i-1][0] + matrix[GetId(s1[i-1])][4]; //dp下标从1开始,串下标从0开始,当前字符与'-'对应
        for(i=1;i<=len2;i++)
            dp[0][i]=dp[0][i-1] + matrix[4][GetId(s2[i-1])];

        for(i=1;i<=len1;i++){
            for(j=1;j<=len2;j++){
                t1=dp[i-1][j-1] + matrix[GetId(s1[i-1])][GetId(s2[j-1])]; //当前字符i与j相对应
                t2=dp[i-1][j] + matrix[GetId(s1[i-1])][4]; //s1当前i对应'-',s2当前j对应i-1以前的,即在j后插入了'-'与i对应
                t3=dp[i][j-1] + matrix[4][GetId(s2[j-1])];
                dp[i][j]=max(t1,t2,t3);
            }
        }
        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}
