/**
 * 用dp(j, k)表示，取j个候选人，使其辩控差为k 的所有方案中，辩控和最大的那个方案（该方案称为“方案dp(j, k)”）的辩控和
 * 可行方案dp(j-1, x)能演化成方案dp(j, k)的必要条件是：
 * 存在某个候选人i，i 在方案dp(j-1, x)中没有被选上，且x+V(i) = k。
 * 在所有满足该必要条件的dp(j-1, x)中，选出 dp(j-1, x) + S(i) 的值最大的那个
 * 那么方案dp(j-1, x)再加上候选人i，就演变成了方案 dp(j, k)。
 */
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;
int n,m;
int dp[21][801];
int path[21][801];

bool select(int j,int k,int i,int *v){
    while(j>0 && path[j][k]!=i)
    {
        k-=v[ path[j][k] ];
        j--;
    }
    return j?false:true;
}
int main()
{
    int time=1;
    while(1){
        scanf("%d%d",&n,&m);
        if(n==0 && m==0)break;
        int j,k,i;
        int *p=new int[n+1];
        int *d=new int[n+1];
        int *s=new int[n+1];
        int *v=new int[n+1];
        memset(dp,-1,sizeof(dp));
        memset(path,0,sizeof(path));

        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&p[i],&d[i]);
            s[i]=p[i]+d[i];
            v[i]=p[i]-d[i];
        }
        int fix=m*20;
        dp[0][fix]=0;
        for(j=1;j<=m;j++){
            for(k=0;k<=2*fix;k++){
                if(dp[j-1][k]>=0){
                    for(i=1;i<=n;i++){
                        if(dp[j][ k+v[i] ] < dp[j-1][k]+s[i]){
                            if(select(j-1,k,i,v)){ //i没被j-1方案选择过
                                dp[j][k+v[i]] = dp[j-1][k]+s[i];
                                path[j][ k+v[i] ] = i;
                            }
                        }
                    }
                }
            }
        }
        for(k=0;k<=fix;k++)
            if(dp[m][fix-k]>=0 || dp[m][fix+k]>=0) break;

        int div=dp[m][fix-k] > dp[m][fix+k] ? (fix-k) : (fix+k);

        printf("Jury #%d\n",time++);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",(dp[m][div]+div-fix)/2,(dp[m][div]-div+fix)/2);

        int *id=new int[m];
        for(i=0,j=m,k=div;i<m;i++){
            id[i]=path[j][k];
            k-=v[ id[i] ];
            j--;
        }
        sort(id,id+m);
        for(i=0;i<m;i++)
            printf(" %d",id[i]);
        printf("\n\n");
        delete p;
        delete d;
        delete s;
        delete v;
        delete id;
    }
    return 0;
}
