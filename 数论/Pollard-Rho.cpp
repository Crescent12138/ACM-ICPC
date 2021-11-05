#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 105;
ll x[maxn], ans;
queue<ll> aria;
ll min(ll a, ll b)
{
	if (a < b)	return a;
	else	return b;
}
ll multi(ll a, ll b, ll p)	//¿ìËÙ³Ë£¿ 
{
	ll ans = 0;
	while (b) {
		if (b & 1LL)	ans = (ans + a) % p;
		a = (a + a) % p;
		b >>= 1;
	}
	return ans;
}
ll qpow(ll a, ll b, ll p)
{
	ll ans = 1;
	while (b) {
		if (b & 1LL)	ans = multi(ans, a, p);
		a = multi(a, a, p);
		b >>= 1;
	}
	return ans;
}

bool MR(ll n)
{
	if (n == 2)	return true;
	int s = 20, i, t = 0;
	ll u = n - 1;
	while (!(u & 1)) {
		t++;
		u >>= 1;
	}
	while (s--) {
		ll a = rand() % (n - 2) + 2;
		x[0] = qpow(a, u, n);
		for (i = 1; i <= t; i++) {
			x[i] = multi(x[i - 1], x[i - 1], n);
			if (x[i] == 1 && x[i - 1] != 1 && x[i - 1] != n - 1)	return false;
		}
		if (x[t] != 1)	return false;
	}
	return true;
}

ll gcd(ll a, ll b)
{
	if (b == 0)	return a;
	else	return gcd(b, a % b);
}

ll Pollard_Rho(ll n, int c)
{
	ll i = 1, k = 2, x = rand() % (n - 1) + 1, y = x;
	while (1) {
		i++;
		x = (multi(x, x, n) + c) % n;
		ll p = gcd((y - x + n) % n, n);
		if (p != 1 && p != n)	return p;
		if (y == x)	return n;
		if (i == k) {
			y = x;
			k <<= 1;
		}
	}
}

void find(ll n, int c)
{
	if (n == 1)	return;
	if (MR(n)) {
		aria.push(n);
		return;
	}
	ll p = n, k = c;
	while (p >= n) {
		p = Pollard_Rho(p, c--);
	}
	find(p, k);
	find(n / p, k);
}

int main()
{
	ll n;
	while (~scanf("%lld", &n)) {
		find(n, 107);
		cout << aria.front();
		aria.pop();
		while (!aria.empty()) {
			cout << "*" << aria.front();
			aria.pop();
		}
		cout << endl;
	}
	return 0;
}