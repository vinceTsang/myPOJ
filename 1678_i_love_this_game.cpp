/**                                                                                                                                                       
 * 记忆化搜索
 * dfs返回的是对于前一个选手选了下标为pre的数后
 * 当前选手从下标cur开始寻找合适的数所获得最大的分数差
 * 在dfs中用当前考虑的num减去下一个选手在博弈中取得的分数差
 * 即能得到最终的分数差
 * 即x1-(y1-(x2-(y2...)))=x1-y1+x2-y2...即为所求
 * 各数不小于a的才加入num中并排序
 * 由于a大于0,故让num[0]=0
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
const int inf=1<<25;
using namespace std;
int value[10002];
int num[10002], a, b, len;
int dfs(int m){ //dfs表示当前取了第m个数后可以达到的最大分差
    if(value[m]!=-1){
        return value[m]; }
    int ans=inf;
    for(int i=m+1;i<len;i++){
        if(num[i]-num[m] >= a && num[i]-num[m] <= b){
            ans=min(ans,num[m]-dfs(i)); //即value[m]=num[m]-max{dfs(i)},后续依然采用的是最优策略
        }else if(num[i]-num[m] > b) //过大,其后不再枚举
            break;
    }
    if(ans==inf) //其后没有有效数
        ans=num[m];
    return value[m]=ans;
}
int main(){
    //freopen("d:\\inputDate.txt","r",stdin);
    int T,n,i,x;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&a,&b);
        num[0]=0, len=1;
        for(i=0;i<n;i++){
            scanf("%d",&x);
            if(x>=a)
                num[len++]=x;
        }
        sort(num,num+len);
        memset(value,-1,sizeof(value));
        int ans=-inf;
        for(i=1;i<len;i++){
            if(num[i]>=a && num[i]<=b)
                ans=max(ans,dfs(i));
            else if(num[i]>b)
                break;
        }
        ans = ans==-inf? 0 : ans;
        printf("%d\n", ans );
    }
    return 0;
}
