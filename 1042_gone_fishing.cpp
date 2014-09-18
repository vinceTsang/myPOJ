#include <iostream>
#include <stdio.h>
using namespace std;

const int N=25;

int main()
{
    int plan[N]={0};
    int temp_plan[N]={0};
    int f[N],d[N],t[N];
    int f_on_change[N];
    int Sum[N];
    int n,h,intervals,i,j,on_lakes,Max,choose;
    int Maximun_sum,enum_lake;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        scanf("%d",&h);
        for(i=0;i<n;i++) scanf("%d",&f[i]);
        for(i=0;i<n;i++) scanf("%d",&d[i]);
        for(i=1;i<n;i++) scanf("%d",&t[i]);
        t[0]=0;
        intervals=h*12;
        Maximun_sum=-1;
        enum_lake=-1;
        for(on_lakes=0;on_lakes<n;on_lakes++){
            Sum[on_lakes]=0;
            intervals-=t[on_lakes];
            for(j=0;j<n;j++){
                f_on_change[j]=f[j];
                temp_plan[j]=0;
            }
            for(j=0;j<intervals;j++){
                Max=-1;
                choose=-1;
                for(i=0;i<=on_lakes;i++){
                    if(f_on_change[i]>Max){
                        Max=f_on_change[i];
                        choose=i;
                    }
                }
                if(Max==-1){
                    temp_plan[0]++;
                    continue;
                }
                Sum[on_lakes]+=Max;
                temp_plan[choose]++;
                f_on_change[choose]-=d[choose];
                    // 为负虽不影响最优解的和，但在两者皆无鱼可取（即实际为0而此处可能为负）时，应优先选最前面的岛
                    // 此时将负赋值为0即可
                f_on_change[choose] = f_on_change[choose] < 0 ? 0: f_on_change[choose];

            }
            if(Sum[on_lakes]>Maximun_sum){
                Maximun_sum=Sum[on_lakes];
                enum_lake=on_lakes;
                for(i=0;i<=enum_lake;i++)
                    plan[i]=temp_plan[i];
            }
        }
        for(i=0;i<n;i++){
            if(i==0)
                printf("%d",plan[i]*5);
            else if(i>enum_lake)
                printf(", 0");
            else
                printf(", %d",plan[i]*5);

        }
        printf("\n");
        printf("Number of fish expected: %d\n\n",Maximun_sum);
    }
    return 0;
}
