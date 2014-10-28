#include <iostream>
#include <cstdio>
using namespace std;
long long a[22];
int main(){
    int M, i, z;
    while(scanf("%d",&M)!=EOF){
        z=0;
        for(i=0;i<M;i++){
            scanf("%lld",a+i);
            z ^= a[i];
        }
        if(z)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
