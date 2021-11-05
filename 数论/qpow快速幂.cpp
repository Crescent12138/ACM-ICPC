const int mod = 101;
ll qpow(ll m, ll k) {
    if(m==0)return 0;
    ll res = 1 % mod;
    while (k) {
        if (k & 1) res = res * m % mod;
        m = m * m % mod;
        k >>= 1;
    }
    return res;
}



ll qpow(ll a, ll b, ll m) {
	if (b == 0) return 1;
	if (b & 1) return a * qpow(a, b - 1, m) % m;
	else {
		ll num = qpow(a, b / 2, m);
		return num * num % m;
	}
}