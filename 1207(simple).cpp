#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=10002;
int val[MAXN];
int main(){
    int i,j,count;
    memset(val,-1,sizeof(val));
    val[1]=1;
    for(i=2;i<MAXN;i++){
        count=1;
        int tmp=i;
        while(tmp!=1){
            if(tmp<MAXN && val[tmp]!=-1){
                count+=val[tmp]-1; //1计算了两遍,减1
                break;
            }
            count++;
            if(tmp%2)
                tmp=3*tmp+1;
            else
                tmp/=2;
        }
        val[i]=count;
    }
    int x,y,ans,xx,yy;
    while(scanf("%d %d",&x,&y)!=EOF){
        ans=0;
        if(y<x){
            xx=y; yy=x;
        }else{
            xx=x; yy=y;
        }
        for(i=xx;i<=yy;i++){
            ans=max(ans,val[i]);
        }
        printf("%d %d %d\n",x,y,ans);
    }
}
