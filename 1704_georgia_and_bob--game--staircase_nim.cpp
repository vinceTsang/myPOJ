/**
 * 等价于倒过来的阶梯博弈
 * 每个棋子位置i与其左邻棋子位置j的差-1构成一个nim堆
 * 堆大小i-j-1即为两者间空闲格子的个数
 * 最左棋子堆为i-0-1
 * 任意棋子左移x个位置等价于将x个棋子移至右侧相邻的堆
 * 首部在棋子序列的尾部,即最右的棋子堆为最低一层的阶梯
 *
 * 对于阶梯博弈,每次从任一层阶梯移动若干棋子至其下方一层
 * 棋子数为[1,k],k为当前层的总棋子数.最下层的棋子不能再移动
 * 阶梯博弈的解决算法是将所有奇数位置的阶梯视为nim堆,而偶数位置忽略
 * 因为所有偶数位置阶梯上的棋子都能移动至下一层(而由于最下一层的原因,奇数位置不满足)
 * 考虑任意nim堆的局势(已方必胜或必败),若对手将偶数堆上k个棋子移至下一层
 * 则自己能立即将该奇数层上新增的k个棋子移走至下一层
 * (在最下一层移动棋子相当于丢弃)
 * 即该k个其则仍处于偶数层这样的遗弃位置,而奇数堆完全不变
 * 总有一方愿意保持这种nim堆的局势
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int T,n,MOD,z,i,pre,cur;
    int p[1002];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n%2==0)
            MOD=1;
        else
            MOD=0;
        z=0;
        for(i=1;i<=n;i++) scanf("%d",p+i);
        sort(p+1,p+n+1);
        p[0]=0;
        for(i=1;i<=n;i++){
            if(MOD==0)
                z ^= p[i]-p[i-1]-1;
            MOD ^= 1;
        }
        if(z)
            printf("Georgia will win\n");
        else
            printf("Bob will win\n");
    }
    return 0;
}
