#include <cstdio>
#include <cstring>
#define N 1005
int s[N][N],f[N][N],sum[N],n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(f,127,sizeof(f));
        sum[0]=0;
        for(int i=1; i<=n; i++){
            scanf("%d",&sum[i]);
            sum[i]+=sum[i-1];
            f[i][i]=0;
            s[i][i+1]=i;
        }
        for(int i=1; i<=n; i++)
            f[i][i+1]=sum[i+1]-sum[i-1];

        for(int i=n-2; i>=1; i--)
            for(int j=i+2; j<=n; j++)
                for(int k=s[i][j-1]; k<=s[i+1][j]; k++)
                if(f[i][j]>f[i][k]+f[k+1][j]+sum[j]-sum[i-1])
                {
                    f[i][j]=f[i][k]+f[k+1][j]+sum[j]-sum[i-1];
                    s[i][j]=k;
                }
    
        printf("%d\n",f[1][n]);
    }
    return 0;
}