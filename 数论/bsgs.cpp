#include<map>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll qpow(ll x,ll n,ll m ){
    x %= m;
    assert(0 <= n && 1 <= m && x <= m && 0 <= x);
    ll ans = 1%m;
    while(n){
        if(n&1)ans = ans * x % m;
        n >>= 1;
        x = x * x % m;
    }
    return ans;
}
/***
 * BSGS 大步小步求最小离散对数
 * @param a 底数
 * @param b 指数
 * @param Mod 取模数
 * @return
 */
ll BSGS(ll a,ll b,ll Mod ) {
    std::map<ll,ll> mp;
    ll m=sqrtl(Mod+0.5),p=1,x=1;
    if(b==1) return 0;
    for(int i=0;i<m;i++) mp[b*p%Mod]=i,p=(p*a)%Mod;
    for(ll i=m;i<=Mod;i+=m){
        x=(x*p)%Mod;
        if(mp.count(x)) return i-mp[x];
    }
    return -1;
}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);
    int n ,b,p;
    std::cin >> p>>b>>n ;
    ll ans = BSGS(b,n,p);
    if(ans == -1){
        std::cout<<"no solution\n";
    }else{
        std::cout<<ans<<"\n";
    }

}