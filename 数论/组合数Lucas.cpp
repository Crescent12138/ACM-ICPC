#define ll long long 
const int maxn = 1e5 + 100;
ll fac[maxn];
const int mod = 101;
ll quick(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1)ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans % mod;
}
ll ccc(ll n, ll m) {//求组合数
    if (m > n) return 0;
    return (fac[n] * quick(fac[m], mod - 2) % mod * quick(fac[n - m], mod - 2) % mod) % mod;
}
void pre()
{
   fac[0] = 1;
        for (ll i = 1; i <= mod; i++) {
            fac[i] = fac[i - 1] * i % mod;
        }
}