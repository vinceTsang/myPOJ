/**
 * 判断两头有颜色的若干木棍能否
 * 连接起来，使得各连接端颜色相同
 * 欧拉路+trie+并查集
 * 视一种颜色为一个点，该颜色的数量为度
 * 则奇数度的个数为0或2能构成欧拉路
 * 用trie(静态数组实现)记录颜色
 * 颜色最后一个字符所在的trie索引确定颜色
 * num记录颜色序号
 * 任给一个颜色，若存在则能迅速查找到序号
 * 并查集用于判断是否连通
 * 若所有点仅有一个公共父亲则连通
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN=500002;
int trie[MAXN][26],f[MAXN],n,r;
unsigned short num[MAXN],degree[MAXN/4];
//trie字典树， num记录当前这个color的序号，degree记录每种颜色的度
//f并查集，n、r分别用于分配num序号和trie序号
int Insert(char s[11]){ //插入颜色，返回颜色序号
    int i,j=0,l=strlen(s);
    for(i=0;i<l;i++){
        if(trie[j][s[i]-'a'])   j=trie[j][s[i]-'a'];
        else    j=trie[j][ s[i]-'a' ]=++r; //分配新位置
    }
    if(num[j]==0)   num[j]=++n; //最后一个位置确定颜色
    return num[j];
}
int Find(int x){
    if(x!=f[x])
        f[x]=Find(f[x]);
    return f[x];
}
int main()
{
    //freopen("d:\\inputDate.txt","r",stdin);
    int i,j,tmpindex;
    char s1[11],s2[11],tmp;
    memset(trie,0,sizeof(trie));
    memset(num,0,sizeof(num));
    memset(degree,0, sizeof(degree));
    n=0; r=0;
    for(i=1;i<MAXN;i++)
        f[i]=i;
    while(scanf("%s %s",&s1,&s2)!=EOF){
        i=Insert(s1);
        j=Insert(s2);
        degree[i]++; degree[j]++; //只需判奇偶
        i=Find(i); j=Find(j);
        if(i!=j)
            f[j]=i;
    }
    j=0;
    for(i=1;i<=n;i++)
        if(degree[i]&1) j++;
    if(j!=0 && j!=2){
        printf("Impossible\n");
    }else{
        //再判断连通性，看是否只有一个父亲
        j=Find(1); //公共父亲
        for(i=2;i<=n;i++){
            if(Find(i)!=j)
                break;
        }
        if(i>n)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    return 0;
}
