//最长公共子序列
#include<iostream>
#include<string>
#include<cstring>
#define MAX 1001 
using namespace std;
int dp[MAX][MAX];
int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		string a,b;
		cin >> a >> b;
		memset(dp,0,sizeof(dp));
		int len_a=a.size(),len_b=b.size(); 
		for(int i=0;i<len_a;i++)
		{
			for(int j=0;j<len_b;j++)
			{
				if(a.at(i)==b.at(j))
					dp[i+1][j+1]=dp[i][j]+1;
				else 
					dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
			}
		}
		cout << dp[len_a][len_b] << endl;
		a.clear();
		b.clear();
	}
	return 0;
}