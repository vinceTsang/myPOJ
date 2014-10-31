/**
 * 暴力则时空都将超限制
 * 而pairs数只有1000个,可以从此处着手
 * 如果一个像素自身及其周围8个格子的情况跟其左边的像素完全一样
 * 则该像素的输出值也会与左边像素的值一样
 * 一旦自身跟左边不同,或环境不同,则需重新计算输出值
 * 而每一个可能变化的这样的边界性的点都必定位于某段开头的周遭
 * 因为出现了新的段才会导致有点的环境变得跟左边不一样
 * 故只需枚举每段的开头及其周围8个点
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
const int size=1005;
using namespace std;
struct pix{
    int pos,code;
}outmap[size*8];

int inmap[size][2]; //inmap[][0]表该连续段的数值,[1]表示长度
int width,cntp,tot; //cntp是输入pairs的个数,tot是像素总数

int cmp(pix x,pix y){
    return x.pos<y.pos;
}

int getnum(int pos){ //返回原图中pos位置上的数值
    int p=0,i=0;
    while(p<pos)
        p+=inmap[i++][1];
    return inmap[i-1][0];
}
int getcode(int pos){ //计算pos位置上的答案
    int num=getnum(pos), ret=0;
    int row=(pos-1)/width; //根据编号模拟二维坐标
    int col=(pos-1)%width;
    for(int i=row-1;i<=row+1;i++){
        for(int j=col-1;j<=col+1;j++){
            int tpos=i*width+j;
            if(i<0 || j<0 || j>=width || tpos >=tot || tpos==pos-1) //不包括自己
                continue;
            int tmp=getnum(tpos+1);
            if( abs(tmp-num) > ret )
                ret=abs(tmp-num); //ret取最大
        }
    }
    return ret;
}
int main(){
    while(scanf("%d",&width), width>0){
        int num,len;
        cntp=tot=0;
        while(scanf("%d%d",&num,&len), len>0){
            inmap[cntp][0]=num;
            inmap[cntp++][1]=len;
            tot+=len;
        }
        printf("%d\n",width);
        int pos=1,k=0; //pos从1开始编号,k为输出pairs的个数
        for(int p=0;p<=cntp;p++){ //枚举每一个连续段
            int row=(pos-1)/width; //模拟二维坐标,下标从0开始
            int col=(pos-1)%width;

            for(int i=row-1;i<=row+1;i++){
                for(int j=col-1;j<=col+1;j++){
                    int tpos=i*width+j+1;
                    if(i<0 || j<0 || j>=width || tpos>tot)
                        continue;
                    outmap[k].pos=tpos;
                    outmap[k++].code=getcode(tpos);
                }
            }

            pos+=inmap[p][1]; //编号跳跃到下一个连续段的初始格
        }

        sort(outmap,outmap+k,cmp);
        pix tmp=outmap[0];
        for(int i=1;i<k;i++){
            if(outmap[i].code==tmp.code) //表明连续,重复计算会导致该情况
                continue;
            printf("%d %d\n",tmp.code, outmap[i].pos-tmp.pos);
            tmp=outmap[i];
        }
        printf("%d %d\n",tmp.code,tot-tmp.pos+1);
        printf("0 0\n");
    }
    printf("0\n");
    return 0;
}
