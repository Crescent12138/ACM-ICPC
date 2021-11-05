#include<iostream>
#include<algorithm>
#include<cstring>
#define rep(i,a,b) for(int i=a,_b=b;i<_b;i++)
typedef long long ll;
using namespace std;
#include<queue>
const ll mod=1e9+7;
ll qpow(ll x,ll n){
	ll c=1;
	for(;n;n/=2,x=x*x%mod) if(n&1) c=c*x%mod;
	return c;
}//              inital value
vector<ll> BM(const vector<ll>&s){
	int n=s.size(),L=0,m=0;
	vector<ll> C(n),B(n),T;
	C[0]=B[0]=1;
	ll b=1,d;
	for(int i=0;i<n;i++){
		m++;d=s[i];
		for(int j=1;j<=L;j++) 
			d=(d+C[j]*s[i-j])%mod;
		if(!d) continue;
		T=C;ll coef=d*qpow(b,mod-2)%mod;
		for(int j=m;j<n;j++) 
			C[j]=(C[j]+mod-coef*B[j-m]%mod)%mod;
		if(2*L>i) continue;
		L=i+1-L;B=T,b=d;m=0;
	}
	C.resize(L+1),C[0]=0;
	for(ll&i:C) i=(mod-i%mod)%mod;
	return C;
}
void mul(vector<ll>&rec,ll a[],ll b[],int k){
	ll c[2*k]={};
	rep(i,0,k) rep(j,0,k) 
		c[i+j]=(c[i+j]+a[i]*b[j])%mod;
	for(int i=k*2-2;i>=k;i--)
		for(int j=1;j<=k;j++)//use recursion to go back
			c[i-j]=(c[i-j]+rec[j]*c[i])%mod;
	rep(i,0,k) a[i]=c[i];
}//   recursion   initial value   nth item
ll linear(vector<ll>&a,vector<ll>&b,ll n){
	int k=a.size()-1;ll res[2*k]={},c[2*k]={};
	c[1]=res[0]=1;
	for(;n;n/=2,mul(a,c,c,k))
		if(n&1) mul(a,res,c,k);
	ll ret=0;
	rep(i,0,k) ret=(ret+b[i]*res[i])%mod;
	return ret;
}
ll f[30][30]={};
ll F(ll n,ll k){
	if(n==1) return 1;
	if(f[n][k]) return f[n][k];
	ll res=0;
	for(int i=1;i<n;i++) res+=F(i,k);
	return f[n][k]=(res+qpow(n,k))%mod;
}
int main() {
	ll n,k;
	for(;~scanf("%lld%lld",&n,&k);) {
		vector<ll> a;
		for(int i=1;i<=29;i++) a.push_back(F(i,k));
		vector<ll> ans=BM(a);
		printf("%lld\n",linear(ans,a,n-1));
	}
}