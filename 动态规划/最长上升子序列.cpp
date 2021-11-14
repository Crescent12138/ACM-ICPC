#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
  
using namespace std;  
  
int num[10]={3,6,3,2,4,6,7,5,4,3};  
  
const int INF=0x3f3f3f3f;  
int l=10, g[100], d[100];  
 
int main()  
{  
    fill(g, g+l, INF);  
    int max_=-1;  
    for(int i=0; i<l; i++)  
    {  
        int j = lower_bound(g, g+l, num[i]) - g;  
        d[i] = j+1;  
        if(max_<d[i])  
            max_=d[i];  
        g[j] = num[i];  
    }  
    printf("%d\n", max_);  
    return 0;  
}  
  
  #include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn =103,INF=0x7f7f7f7f;
struct Node{
    int val,num;
}z[maxn]; 
int T[maxn];
int n;
bool cmp(Node a,Node b)
{
    return a.val==b.val?a.num<b.num:a.val<b.val;
}
void modify(int x,int y)//把val[x]替换为val[x]和y中较大的数 
{
    for(;x<=n;x+=x&(-x)) T[x]=max(T[x],y);
}
int query(int x)//返回val[1]~val[x]中的最大值 
{
    int res=-INF;
    for(;x;x-=x&(-x)) res=max(res,T[x]);
    return res;
}
int main()
{
    int ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&z[i].val);
        z[i].num=i;//记住val[i]的编号，有点类似于离散化的处理，但没有去重 
    }
    sort(z+1,z+n+1,cmp);//以权值为第一关键字从小到大排序 
    for(int i=1;i<=n;i++)//按权值从小到大枚举 
    {
        int maxx=query(z[i].num);//查询编号小于等于num[i]的LIS最大长度
        modify(z[i].num,++maxx);//把长度+1，再去更新前面的LIS长度
        ans=max(ans,maxx);//更新答案
    }
    printf("%d\n",ans);
    return 0;
}

