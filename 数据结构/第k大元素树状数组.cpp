///here is jmr's codes
///if you want to copy,please call me 29856325137
///thanks
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long
double eps = 1e-6;
const int maxn = 1e5 + 5;
int n, m;
int tre[maxn << 1];
inline int lowbit(int x) {
	return x & (-x);
}
inline void  add(int x,int k) {
	while (x <= 1e5+7) {
		tre[x] += k;
		x += lowbit(x);
	}
}
inline int sums(int x) {
	int res = 0;
	while (x) {
		res += tre[x];
		x -= lowbit(x);
	}
	return x;
}
int kth(int k) {
	int cnt = 0, res = 0;
	for (int i = 20; ~i; i--) {
		res += 1 << i;
		if (res >= 1e5 || cnt + tre[res] >= k) {
			res -= 1 << i;
		}
		else cnt += tre[res];
	}
	return res + 1;
}
int main() {
	//freopen("1.txt", "w", stdout);
	cin >> m;
	stack<int>st;
	while (m--) {
		string s;
		cin >> s;
		if (s[1] == 'o') {
			if (st.empty())cout << "Invalid";
			else {
				n--;
				int k = st.top();
				add(k, -1);
				st.pop();
				cout << k;
			}
			cout << "\n";
		}
		else if (s[1] == 'u') {
			int x;
			cin >> x;
			n++;
			st.push(x);
			add(x, 1);
		}
		else {
			if (st.empty())cout << "Invalid";
			else {
				cout << kth((n+1)/ 2);
			}
			cout << "\n";
		}
		
	}








}