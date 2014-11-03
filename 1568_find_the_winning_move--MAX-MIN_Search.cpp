#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int inf=1<<30;
char str[5][5];
int X,Y,chess;
bool check(int x,int y){
    int tot=0,i;
    //横向判断
    for(i=0;i<4;i++)
        if(str[x][i]=='o') tot++;
        else if(str[x][i]=='x') tot--;
    if(tot==4 || tot==-4) return true;
    tot=0;
    //纵向判断
    for(i=0;i<4;i++)
        if(str[i][y]=='o') tot++;
        else if(str[i][y]=='x') tot--;
    if(tot==4 || tot==-4) return true;
    tot=0;
    //正对角线
    for(i=0;i<4;i++)
        if(str[i][i]=='o') tot++;
        else if(str[i][i]=='x') tot--;
    if(tot==4 || tot==-4) return true;
    tot=0;
    //反对角线
    for(i=0;i<4;i++)
        if(str[i][3-i]=='o') tot++;
        else if(str[i][3-i]=='x') tot--;
    if(tot==4 || tot==-4) return true;
    return false;
}
int MinSearch(int x,int y,int beta);
int MaxSearch(int x,int y,int alpha){
    //cout<<"begin Max in "<<x<<" "<<y<<endl;
    int ans=-inf;
    if(check(x,y)){
        //cout<<"check in Max!"<<endl;
        return ans; //已结束
    }
    if(chess==16) return 0; //平局
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            if(str[i][j]=='.'){
                str[i][j]='x'; chess++;
                int tmp=MinSearch(i,j,ans);
                //cout<<"MAXSearch "<<tmp<<" === "<<ans<<" === "<<alpha<<endl;
                str[i][j]='.'; chess--;
                ans=max(ans,tmp);
                /*
                 * 作为Max过程，返回值尽可能大，而当前已计算出ans
                 * 则最小返回ans，不可能更小
                 * 即对于该过程的父Min过程(希望达到最小)而言，最优只能在当前过程获得ans的值。
                 * 如果ans已经比传入的alpha要大
                 * (注意该alpha实际是父Min过程的beta值，该值意味着父亲至少已经能达到beta值)
                 * 那么当前Max过程不必再搜索下去了，继续搜索对于父过程而言结果不会更好
                 * 于是父过程完全舍弃该子Max过程，要求当前过程立即终止
                 */
                //对方需要找的最差估价,如果当前比之前最高的高,剪枝
                if(ans>=alpha) {
                    //cout<<"found in MAX!!"<<endl<<endl;
                    return ans;
                }
            }
    }
    return ans;
}
int MinSearch(int x,int y,int beta){
    //cout<<"begin Min in "<<x<<" "<<y<<endl;
    int ans=inf;
    if(check(x,y)){
        //cout<<"check in Min!"<<endl;
        return ans;
    }
    if(chess==16) return 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            if(str[i][j]=='.'){
                str[i][j]='o'; chess++;
                int tmp=MaxSearch(i,j,ans);
                //cout<<"MINSearch "<<tmp<<" === "<<ans<<" === "<<beta<<endl;
                str[i][j]='.'; chess--;
                ans=min(ans,tmp);
                /*
                 * 作为Min过程，返回值尽可能小，而当前已计算出ans
                 * 则最大返回ans，不可能更大
                 * 即对于该过程的父Max过程而言，最多只能在当前过程获得ans的值。
                 * 如果ans已经比传入的beta要小
                 * (注意该beta实际是父Max过程的alpha值，该值意味着父亲最少已经能得到alpha值)
                 * 那么当前Min过程不必再搜索下去了，继续搜索对于父过程而言结果不会更好
                 * 于是父过程完全舍弃该子Min过程，要求当前过程立即终止
                 */
                if(ans<=beta){
                    //cout<<"found in MIN!!"<<endl<<endl;
                    return ans;
                }
            }
    }
    return ans;
}
bool solve(){
    int beta=-inf;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            //枚举然后搜索
            if(str[i][j]=='.'){
                str[i][j]='x'; chess++;
                int tmp=MinSearch(i,j,beta);
                str[i][j]='.'; chess--;
                beta=max(tmp,beta);
                if(beta==inf){
                    X=i;
                    Y=j;
                    return true;
                }
            }
    return false;
}
int main(){
    //freopen("d:\\inputDate.txt","r",stdin);
    //freopen("d:\\outputDate.txt","w",stdout);
    char ch[5];
    while(scanf("%s",ch)!=EOF && ch[0]!='$'){
        chess=0;
        for(int i=0;i<4;i++){
            scanf("%s",str[i]);
            for(int j=0;j<4;j++)
                chess+=str[i][j]!='.';
        }
        if(chess<=4){ //强剪枝,当前走的棋子共小于等于4则无必胜策略
            printf("#####\n");
            continue;
        }
        if(solve()) printf("(%d,%d)\n",X,Y);
        else printf("#####\n");
    }
}
