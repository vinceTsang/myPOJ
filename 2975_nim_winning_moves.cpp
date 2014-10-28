#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n,i;
    int k[1002], z;
    while(scanf("%d",&n), n!=0){
        z=0;
        for(i=0;i<n;i++){
            scanf("%d",k+i);
            z = z^k[i];
        }
        if(!z){
            printf("0\n");
            continue;
        }
        /*
        for(i=2; true ;i++){
            z=z/2;
            if(!z)
                break;
        }
        z = 1 << (i-2) ;
        */
        int ans=0,tmp;
        for(i=0;i<n;i++){
            //if(k[i]/z>0) //不能简单用除法判断
                           //否则对于"最大的奇数个1的位置"较低时,几乎所有k[i]都满足该除法,错误
            tmp=z^k[i]; //此时tmp为不含k[i]的其余数的异或
            if(k[i] > tmp) //缺少k[i]后异或值变小,即k[i]在最高奇数个1的位置上有1.
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
