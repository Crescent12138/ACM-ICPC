#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = (1<<17),mod = 998244353;
int n,mx,a[N],b[N],ta[N],tb[N];
void OR(int f[],int type)
{
	for(int mid=2,k=1;mid<=mx;mid<<=1,k<<=1)
	for(int i=0;i<mx;i+=mid )
	for(int j=0;j<k;j++)
		f[i+j+k] = ( f[i+j+k]+f[i+j]*type )%mod;
}
void AND(int f[],int type)
{
	for(int mid=2,k=1;mid<=mx;mid<<=1,k<<=1)
	for(int i=0;i<mx;i+=mid )
	for(int j=0;j<k;j++)
		f[i+j] = ( f[i+j]+f[i+j+k]*type )%mod;
}
void XOR(int f[],int type)
{
	for(int mid=2,k=1;mid<=mx;mid<<=1,k<<=1)
	for(int i=0;i<mx;i+=mid)
	for(int j=0;j<k;j++)
	{
		int t = i+j, v = i+j+k;
		f[t] = ( f[t]+f[v] )%mod;
		f[v] = ( f[t]-f[v]-f[v] )%mod;
		f[t]=f[t]*type%mod, f[v]=f[v]*type%mod;
	}
}
void init(){ for(int i=0;i<mx;i++)	ta[i]=a[i],tb[i]=b[i]; }
void print(int a[]){ for(int i=0;i<mx;i++)	printf("%lld%c",(a[i]%mod+mod)%mod,(i==mx-1)?'\n':' '); }
void mul(int a[],int b[] ){ for(int i=0;i<mx;i++)	a[i] = a[i]*b[i]%mod; }
signed main()
{
	scanf("%lld",&n);
	mx = (1<<n);
	for(int i=0;i<mx;i++)	scanf("%lld",&a[i] ),a[i]%=mod;
	for(int i=0;i<mx;i++)	scanf("%lld",&b[i] ),b[i]%=mod;
	init(); OR(ta,1); OR(tb,1); mul( ta,tb ); OR(ta,-1); print(ta); 
	init(); AND(ta,1); AND(tb,1); mul( ta,tb ); AND(ta,-1); print(ta);
	init(); XOR(ta,1); XOR(tb,1); mul( ta,tb ); XOR(ta,(mod+1)>>1); print(ta); 
} 
