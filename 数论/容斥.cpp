
///here is jmr's codes
///if you want to copy,please call me 29856325137
///thanks
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<random>
using namespace std;
#define ll long long
double eps = 1e-6;
const int maxn = 2e5 + 5;
const int MAXX = 2e5 + 5;
ll x[maxn],y[maxn];
vector<ll>ve{2,5,11,13};

int main() {
	ll n;
	while (cin >> n)
	{
		ll ans = 0;
		for (int i = 0; i < (1 << 4); i++) {
			ll cnt = 0, num = n;
			for (int j = 0; j < 4; j++) {
				if ((i >> j) & 1)num /= ve[j], cnt++;
			}
			if (cnt & 1)ans -= num;
			else ans += num;
		}
		cout << ans << "\n";
	}
	
}



