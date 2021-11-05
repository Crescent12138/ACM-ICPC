#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,mod=1e9+7;
int dp[N],g[N];
int main()
{
    int n,m;
    cin>>n>>m;
    // memset(dp,-0x3f,sizeof dp);
    // dp[0]=0;
    g[0]=1;//
    for(int i=1;i<=n;i++)
    {
        int v,w;
        cin>>v>>w;
        
        for(int j=m;j>=v;j--)
        {
            int maxv=max(dp[j],dp[j-v]+w);
            int cnt=0;
            if(maxv==dp[j])cnt+=g[j];
            if(maxv==dp[j-v]+w)cnt+=g[j-v];
            g[j]=cnt%mod;
            dp[j]=max(dp[j],maxv);
        }
    }
    int cnt=0;
    for(int i=0;i<=m;i++)
    {
        cnt=max(dp[i],cnt);
    }
    int ans=0;
    for(int i=0;i<=m;i++)
    {
        if(dp[i]==cnt)ans=(ans+g[i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
