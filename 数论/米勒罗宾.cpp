#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long ll;
const ll test_long_long[]={2,325,9375,28178,450775,9780504,1795265022};
const int test_int[]={2,7,61};
ll qpow(ll x,ll n,ll mod){
	ll c=1;
	for(x%=mod;n;n/=2,x=x*x%mod) if(n&1) c=c*x%mod;
	return c;
}
int miller_robin(ll n){
	if(n==2) return 1;
	if(n%2==0||n<2) return 0;
	ll m=n-1,q=0;
	while(m%2==0) m/=2,q++;
	for(int a:test_int){
		if(a>=n) break;
		ll x=qpow(a,m,n);
		for(int i=0;i<q;i++){
			ll x1=x*x%n;
			if(x1==1&&x!=1&&x!=n-1) return 0;
			x=x1;
		}
		if(x!=1) return 0;
	}
	return 1;
}
int main(){
	int n,a,ans;
	while(~scanf("%d",&n)){
		ans=0;
		while(n--) scanf("%d",&a),ans+=miller_robin(a);
		printf("%d\n",ans);
	}
}

