#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5;
int sum1[N],sum2[N];//差分数组sum1，sum2[i]=sum1[i]*i，当然是用树状数组维护的啦
int a[N];
//lowbit, 查询最低1的位数
inline int lowbit(int x){
    return x&(-x);
}
//树状数组构造,单点增加(这里用差分值存点)
inline void add(int i,int k){
    int x=i;
    while(i<=n){
        sum1[i]+=k;
        sum2[i]+=k*x;
        i+=lowbit(i);
    }
}
//区间增加
void add2(int l,int r,int k){
    add(l,k),add(r+1,-k);
}
//1-k求和，差分数组就直接求得第k个数字
int getsum(int *s,int k){
    int res=0;
    while(k){
        res+=s[k];
        k-=lowbit(k);
    }
    return res;
}
//返回的是区间和，公式计算得到的,这里优化必须得是差分数组
int gets_(int l,int r,int k){
    return (r+1)*getsum(sum1,r)-l*getsum(sum1,l-1)-(getsum(sum2,r)-getsum(sum2,l-1));
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        add(i,a[i]-a[i-1]);//存的是差分数组
    }
    int q,_l,_r,_k;
    for(int i=0;i<m;i++){
        cin>>q;
        if(q==1){
            cin>>_l>>_r>>_k;
            add2(_l,_r,_k);
        }else {
            cin>>_l;
            cout<<getsum(sum1,_l)<<'\n';//获得的是当前_l的值
        }
    }
}