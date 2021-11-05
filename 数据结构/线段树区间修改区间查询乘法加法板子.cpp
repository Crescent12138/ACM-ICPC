///here is jmr's codes
///if you want to copy,please call me 29856325137
///thanks
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
double eps = 1e-6;
const int maxn = 1e5 + 5;
const ll mod = 998244353;
#define ls k << 1
#define rs k << 1 | 1
ll n, m, x, y, mul, add , k;
struct node
{
    ll l, r, w;
    ll add_lz, mul_lz;//懒标记 
}tree[4 * 100000 + 10];
ll p = mod, a[100010];
void build(ll k = 1, ll l = 1, ll r = n)//建树 
{
    tree[k].l = l, tree[k].r = r;
    tree[k].add_lz = 0, tree[k].mul_lz = 1;
    if (l == r)
        tree[k].w = a[l];
    else
    {
        ll m = (l + r) >> 1;
        build(ls, l, m);
        build(rs, m + 1, r);
        tree[k].w = tree[ls].w + tree[rs].w;
    }
    tree[k].w %= p;
    return;
}
void down(ll k)//双懒标记下传 
{
    ll l = tree[k].l, r = tree[k].r, m = (l + r) >> 1;
    tree[ls].w = (tree[ls].w * tree[k].mul_lz + (m - l + 1) * tree[k].add_lz) % p;
    tree[rs].w = (tree[rs].w * tree[k].mul_lz + (r - m) * tree[k].add_lz) % p;
    tree[ls].mul_lz = (tree[ls].mul_lz * tree[k].mul_lz) % p;
    tree[rs].mul_lz = (tree[rs].mul_lz * tree[k].mul_lz) % p;
    tree[ls].add_lz = (tree[ls].add_lz * tree[k].mul_lz + tree[k].add_lz) % p;
    tree[rs].add_lz = (tree[rs].add_lz * tree[k].mul_lz + tree[k].add_lz) % p;
    tree[k].mul_lz = 1;
    tree[k].add_lz = 0;
    return;
}
void mu(ll k = 1)
{
    ll l = tree[k].l, r = tree[k].r, m = (l + r) >> 1;
    if (y < l || r < x)return;
    if (x <= l && y >= r)
    {
        tree[k].w = (tree[k].w * mul) % p;
        tree[k].mul_lz = (tree[k].mul_lz * mul) % p;
        tree[k].add_lz = (tree[k].add_lz * mul) % p;
        return;
    }
    down(k); mu(ls); mu(rs);
    tree[k].w = (tree[ls].w + tree[rs].w) % p;
    return;
}
void ad(ll k = 1)
{
    ll l = tree[k].l, r = tree[k].r, m = (l + r) >> 1;
    if (y < l || r < x)return;
    if (x <= l && y >= r)
    {
        tree[k].add_lz = (tree[k].add_lz + add) % p;
        tree[k].w = (tree[k].w + add * (r - l + 1)) % p;
        return;
    }
    down(k); ad(ls); ad(rs);
    tree[k].w = (tree[ls].w + tree[rs].w) % p;
    return;
}
ll query(ll k = 1)
{
    ll l = tree[k].l, r = tree[k].r, m = (l + r) >> 1;
    if (y < l || r < x)return 0;
    if (x <= l && y >= r)return tree[k].w;
    down(k);
    return (query(ls) + query(rs)) % p;
}

int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)cin >> a[i];
    build();
    ll ans = 0;
    while (m--) {
        int op = 0;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> mul;
            mu();
        }
        else if (op == 2) {
            cin >> x >> y >> add;
            ad();
           /* for (int i = 1; i <= n; i++)x = y = i,cout<< query() << " ";
            cout << "\n";*/
        }
        else {
            cin >> x >> y;
            cout << query() << "\n";
        }
    }
}