#include<bits/stdc++.h>
using namespace std;
int n,V,t=0,N;
int v[10000];
int w[10000];
int ans[1000];
int f[2000][2000];
int main()
{
    ios::sync_with_stdio(false); 
    cin>>N>>V;n=N;
    for (int i=n;i>=1;i--)
        cin>>v[i]>>w[i];
    for (int i=1;i<=n;i++)
        for (int j=0;j<=V;j++)
        {
            if (j<v[i]) f[i][j]=f[i-1][j];
            else f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
        }
    while (n>0&&V>0)
    {
        if (f[n][V]==f[n-1][V-v[n]]+w[n])
        {
            cout<<N-n+1<<' ';
            V=V-v[n];
        }
        n--;
    }
    return 0;
}
