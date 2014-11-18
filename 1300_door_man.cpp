/**
 * 判欧拉路
 * 度全都偶数或者仅有头尾两点度为奇数则有欧拉(回)路
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=101;
int main()
{
    //freopen("d:\\inputDate.txt","r",stdin);
    char s[200];
    int door, de[N], odd, even, n, m, p, cc, len, k, i;
    while(scanf("%s",s)!=EOF){
        if(s[3]=='O') break; //ENDOFINPUT
        scanf("%d %d",&m,&n);
        getchar();
        memset(de,0,sizeof(de));
        door = odd = even = 0;
        for(i=0; i<n; ++i ){
            p=0;
            gets(s);
            while(s[p] && s[p]==' ') ++p;
            while(sscanf(s+p,"%d%n",&k,&cc)==1){ //%n获取字符数
                ++door; //有些门本身就是关着的
                de[i]++;
                de[k]++;
                p+=cc;
                while(s[p] && s[p]==' ') ++p;
            }
        }
        scanf("%*s"); //跳过一个字符串 END
        for(i=0; i<n; ++i)
            if(de[i]&1)
                ++odd;
            else
                ++even;
        if(odd==0 && m==0 || odd==2 && (de[m]&1) && (de[0]&&1) && m!=0)
            printf("YES %d\n",door);
        else
            printf("NO\n");
    }
    return 0;
}
