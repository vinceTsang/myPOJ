#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int a[1020],n,i,l;
    while(scanf("%d",&n)!=EOF){
        l=0;
        bool flag=false;
        for(i=1;i*i<n;i++){
            if(n%i==0){
                a[l++]=i;
                a[l++]=n/i;
            }
        }
        sort(a,a+l);
        for(i=0;i<l;i++){
            if(a[i]<=2) continue;
            printf("%d\n",a[i]-1);
            flag=true;
            break;
        }
        if(!flag)
            printf("0\n");
    }
}
