///here is jmr's codes
///if you want to copy,please call me 29856325137
///thanks
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long 
double eps = 1e-6;
const int maxn = 2e5 + 5;
int n, m;
#define ls (nod << 1)
#define rs (nod << 1 | 1)
typedef struct node {
	int l, r, sum, max, lz;

}T;
T tre[maxn << 1];
int x[maxn];
inline void update(int nod) {
	tre[nod].max = max(tre[ls].max, tre[rs].max);
	tre[nod].sum = tre[ls].sum + tre[rs].sum;
}
void build(int l, int r, int nod) {
	tre[nod].l = l;
	tre[nod].r = r;
	if (l == r) {
		tre[nod].sum = tre[nod].max = x[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	update(nod);
}
void pushup(int l, int r, int nod) {
	if (tre[nod].max <= 1)return;
	if (tre[nod].l == tre[nod].r) {
		if (tre[nod].max > 1) {
			tre[nod].sum = tre[nod].max = pow(tre[nod].max, 0.5);
		}
		return;
	}
	int mid = (tre[nod].l + tre[nod].r) >> 1;
	if (r <= mid)
		pushup(l, r, ls);
	else
		if (l > mid)
			pushup(l, r, rs);
		else
			pushup(l, mid, ls), pushup(mid + 1, r, rs);
	update(nod);
}
int query(int l, int r, int nod) {
	if (tre[nod].l >= l && tre[nod].r <= r) {
		return tre[nod].sum;
	}
	int mid = (tre[nod].l + tre[nod].r) >> 1;
	int ans = 0;
	if (l > mid)ans += query(l, r, rs);
	else
	if (r <= mid)ans += query(l, r, ls);
	else ans += query(l, mid, ls) + query(mid + 1, r, rs);
	return ans;
}
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> x[i];
	cin >> m;
	build(1, n, 1);
	while (m--) {
		int k, l, r;
		cin >> k >> l >> r;
		if (l > r)swap(l, r);
		if (k == 0)pushup(l, r, 1);
		else cout << query(l, r, 1) << "\n";

		//for (int i = 1; i <= n; i++) {
	//	cout << query(i, i, 1) << " ";
	//	}
	//	cout << "\n";
	}
}