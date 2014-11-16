/**
 * 带权并查集
 * 如果两个节点在同一颗树,则关系明确,否则不确定
 * 权值ans 0/1分别表示两个集合
 * 初始均为0
 * find步骤修复ans确保相邻的层权值总相反
 * 合并树只将一颗树的树根连至另一棵树的树根下
 */
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXV=100010;
int ans[MAXV], tree[MAXV];

int find(int x){
    int rt;
    if(tree[x]!=x){
        rt=find(tree[x]);
        ans[x]=ans[x]^ans[tree[x]];
            //每次递归寻找必定会寻找至根,而每次都会至顶向下修复权值ans,确保修复后相邻的层权值总相反
        return tree[x]=rt;
    }
    return x;
}
void TUnion(int x, int y){
    int fx,fy;
    fx=find(x);
    fy=find(y);
    tree[fx]=fy; //x的树根连到y的树根下
    ans[fx]=~(ans[y]^ans[x]); //确保初始节点链接时正确即可.多层树时该值不重要.在find步骤能得以维护
}
int main(){
    int i,n,m,a,b,T;
    char c;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d\n",&n,&m);
        for(i=0;i<=n;i++){
            ans[i]=0;
            tree[i]=i;
        }
        for(i=1;i<=m;i++){
            scanf("%c %d %d\n",&c,&a,&b);
            if(c=='D'){
                TUnion(a,b);
            }else{
                if(n==2)
                    printf("In different gangs.\n");
                else if(find(a)==find(b)){
                    if(ans[a]==ans[b])
                        printf("In the same gang.\n");
                    else
                        printf("In different gangs.\n");
                }else
                    printf("Not sure yet.\n");
            }
        }
    }
    return 0;
}
