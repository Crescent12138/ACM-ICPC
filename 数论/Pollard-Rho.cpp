#include<map>
#include<random>
mt19937 rd((ll)(new int));
typedef __int128_t lll;
// const int test_int[]={2,7,61};
const ll test[]={2,325,9375,28178,450775,9780504,1795265022};
ll qpow(ll x,ll n,ll mod){
	ll c=1;
	for(x%=mod;n;n/=2,x=(lll)x*x%mod) 
		if(n&1) c=(lll)c*x%mod;
	return c;
}
int miller_robin(ll n){
	if (n<2||n%6%4!=1) return (n|1)==3;
	ll q=__builtin_ctzll(n-1),m=(n-1)>>q;
	for(ll a:test){
		if(a>=n) break;
		ll x=qpow(a,m,n),x1,i=q;
		for(;i--&&x!=1;x=x1){
			x1=(lll)x*x%n;
			if(x1==1&&x!=1&&x!=n-1) return 0;
		}
		if(x!=1) return 0;
	}
	return 1;
}
map<ll,ll> ans;
ll pollard_rho(ll x){
	ll s=0,t=0,c=rd()%(x-1)+1,d=1;
	for(ll val,step,g=1;d==1;g<<=1,s=t){
		val=1;
		for(step=1;d==1&&step<=g;step++){
			t=((lll)t*t+c)%x;
			val=(lll)val*abs(t-s)%x;
			if(step%100==0) d=__gcd(val,x);
		}
		d=__gcd(val,x);
	}
	return d;
}
void fac(ll n){
	if(n<2) return;
	if(miller_robin(n)){
		ans[n]++;return;
	}
	ll p=n;
	while(p>=n) p=pollard_rho(n);
	fac(n/p),fac(p);
}
void solve(){
	ll n;
	scanf("%lld",&n);
	if(miller_robin(n)) return void(puts("Prime"));
	ans.clear();
	fac(n);
	printf("%lld\n",ans.rbegin()->first);
	// for(auto [l,r]:ans) printf("%lld %lld\n",l,r);
}
