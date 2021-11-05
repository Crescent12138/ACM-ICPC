#include<cstdio>
#include<cmath>
#include<algorithm>
 
#define MAXN 100010
 
using namespace std;
int dp[MAXN][40];
 
void RMQ(int A[],int n)
{
	int i,j;
	for(i=1;i<=n;i++)
		dp[i][0]=A[i];
	for(j=1;j<=(int)(log(n*1.0)/log(2.0));j++)
		for(i=1;i+(1<<j)-1<=n;i++)
			dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
 
int query(int L,int R)
{
	int k=(int)((log(R-L+1)*1.0)/log(2.0));
	return min(dp[L][k],dp[R-(1<<k)+1][k]);
}
 
int main(int argc,char *argv[])
{
	int i,n,ans;
	int A[MAXN];
	int T,L,R;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&A[i]);
		RMQ(A,n);
		scanf("%d",&T);
		while(T--)
		{
			scanf("%d%d",&L,&R);
			ans=query(L,R);
			printf("%d\n",ans);
		}
	}
 
	return 0;
}