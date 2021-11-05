#include <bits/stdc++.h>
using namespace std;
#define ls (in << 1)
#define rs ((in << 1) + 1)
#define mid (l + r >> 1)
const int maxn = 5e4 + 9;
int tr[maxn << 2], n, L, R, D, lz[maxn << 2];
void build(int in = 1, int l = 1, int r = n)
{
    if (l == r)
        return void(tr[in] = 1); //返回权值
    build(ls, l, mid), build(rs, mid + 1, r);
}

void pushdown(int in = 1, int l = 1, int r = n)
{
    if (lz[in] == -1)
        return;
    int la = lz[in];
    lz[ls] = lz[rs] = la;
    tr[ls] = (mid - l + 1) * la;
    tr[rs] = (r - mid) * la;
    lz[in] = -1;
}
void update(int in = 1, int l = 1, int r = n)
{
    if (l > R || r < L)
        return;
    if (L <= l && R >= r)
    {
        tr[in] = D * (r - l + 1);
        lz[in] = D;
        return;
    }
    pushdown(in, l, r);
    update(ls, l, mid), update(rs, mid + 1, r);
}
int query(int in = 1, int l = 1, int r = n)
{
    if (l > R || r < L)
        return 0;
    if (L <= l && R >= r)
        return tr[in];
    pushdown(in, l, r);
    return query(ls, l, mid) + query(rs, mid + 1, r);
}
int q2(int k, int in = 1, int l = 1, int r = n)
{
    if (l == r)
        return l;
    pushdown(in, l, r);
    if (tr[ls] >= k)
        return q2(k, ls, l, mid);
    else
        return q2(k - tr[ls], rs, mid + 1, r);
}
int main()
{
    cin >> n;
}