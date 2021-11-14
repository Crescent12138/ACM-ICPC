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
void modify(int x,int y)//��val[x]�滻Ϊval[x]��y�нϴ���� 
{
    for(;x<=n;x+=x&(-x)) T[x]=max(T[x],y);
}
int query(int x)//����val[1]~val[x]�е����ֵ 
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
        z[i].num=i;//��סval[i]�ı�ţ��е���������ɢ���Ĵ�����û��ȥ�� 
    }
    sort(z+1,z+n+1,cmp);//��ȨֵΪ��һ�ؼ��ִ�С�������� 
    for(int i=1;i<=n;i++)//��Ȩֵ��С����ö�� 
    {
        int maxx=query(z[i].num);//��ѯ���С�ڵ���num[i]��LIS��󳤶�
        modify(z[i].num,++maxx);//�ѳ���+1����ȥ����ǰ���LIS����
        ans=max(ans,maxx);//���´�
    }
    printf("%d\n",ans);
    return 0;
}

