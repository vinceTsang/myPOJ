#include <iostream>
#include <stdio.h>
int Left=-1,Top=-1,Right,Bottom;
int path[50];
bool visit[30];
int path_index=0;
int path_len;
using namespace std;
bool dfs(int x, int y){
    visit[y*Right+x]=true;
    path[path_index]=y*Right+x;
    path_index++;
    if(path_index==path_len)
        return true;
    if(x-2 >Left && y-1 > Top && !visit[ (y-1)*Right + (x-2) ] ){
        if( dfs(x-2,y-1) ) return true;
    }
    if(x-2 > Left && y+1 < Bottom && !visit[ (y+1)*Right + (x-2) ]){
        if( dfs(x-2,y+1) ) return true;
    }
    if(x-1 > Left && y-2 > Top && !visit[ (y-2)*Right + (x-1) ] ){
        if( dfs(x-1,y-2) ) return true;
    }
    if(x-1 > Left && y+2 < Bottom && !visit[ (y+2)*Right + (x-1) ] ){
        if( dfs(x-1,y+2) ) return true;
    }
    if(x+1 < Right && y-2 > Top && !visit[ (y-2)*Right + (x+1) ] ){
        if( dfs(x+1,y-2) ) return true;
    }
    if(x+1 < Right && y+2 < Bottom && !visit[ (y+2)*Right + (x+1) ] ){
        if( dfs(x+1,y+2) ) return true;
    }
    if(x+2 < Right && y-1 > Top && !visit[ (y-1)*Right + (x+2) ] ){
        if( dfs(x+2,y-1) ) return true;
    }
    if(x+2 < Right && y+1 < Bottom && !visit[ (y+1)*Right + (x+2) ] ){
        if( dfs(x+2,y+1) ) return true;
    }
    path_index--;
    visit[y*Right+x]=false;
    return false;
}
int main()
{
    int testcases=0,n;
    int i,k;
    cin>>n;
    bool succ;
    while(testcases<n){
        scanf("%d %d",&Bottom,&Right);
        if(Bottom==1 && Right==1){
            succ=true;
            printf("Scenario #%d:\nA1\n\n",++testcases);
            continue;
        }
        else if(Bottom<=2 || Right<=2){
            printf("Scenario #%d:\nimpossible\n\n",++testcases);
            continue;
        }
        path_len=Right*Bottom;
        path_index=0;
        for(k=0;k<path_len;k++)
            visit[k]=false;
        succ= dfs(0,0);
        printf("Scenario #%d:\n",++testcases);
        if(!succ){
            printf("impossible\n\n");
            continue;
        }
        int xx,yy;
        for(i=0;i<path_len;i++){
            xx=path[i]/Right;
            yy=path[i]%Right+'A';
            printf("%c%d",yy,xx+1);
        }
        printf("\n\n");
    }
    return 0;
}
