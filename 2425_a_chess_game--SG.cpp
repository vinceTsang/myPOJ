#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int SG[1002];
struct pos_node{
    int nums; //nums of its follows
    int follows[1001];
}pos[1002];
int get_sg(int idx){
    if(SG[idx]!=-1) return SG[idx];
    if(pos[idx].nums==0) return SG[idx]=0;
    bool vis[1002]={ false };
    for(int i=0;i<pos[idx].nums;i++){
        vis[ get_sg(pos[idx].follows[i]) ] = true;
    }
    for(int i=0;i<1002;i++)
        if(!vis[i])
            return SG[idx]=i;
}
int main(){
    int n,m,x,i,j,ans;
    while(scanf("%d",&n)!=EOF){
        memset(SG,-1,sizeof(SG));
        for(i=0;i<n;i++){
            scanf("%d",&x);
            pos[i].nums=x;
            for(j=0;j<x;j++)
                scanf("%d",&(pos[i].follows[j]) );
        }
        while(scanf("%d",&m),m!=0){
            ans=0;
            for(i=0;i<m;i++){
                scanf("%d",&x);
                ans ^= get_sg(x);
            }
            if(ans)
                printf("WIN\n");
            else
                printf("LOSE\n");
        }
    }
    return 0;
}
