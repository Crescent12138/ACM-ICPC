#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll maxn = 5e5 + 5;
ll a[maxn];
ll partLen;       //块长
ll partID[maxn];  //块号
ll partSum[maxn]; //块和
ll tag[maxn];     //块标记

void add(ll l, ll r, ll c)
{
    ll startID = partID[l], endID = partID[r];
    if (startID == endID) //l和r在同一个块，直接暴力
    {
        for (ll i = l; i <= r; i++)
        {
            a[i] += c;
            partSum[startID] += c;
        }
        return;
    }
    //不在同一个块，分成三段处理
    for (ll i = l; partID[i] == startID; i++)//起始段
    {
        a[i] += c;
        partSum[startID] += c;
    }
    for (ll i = startID + 1; i < endID; i++)//中间若干个整块
    {
        tag[i] += c;
        partSum[i] += c * partLen;
    }
    for (ll i = r; partID[i] == endID; i--)//末尾段
    {
        a[i] += c;
        partSum[endID] += c;
    }
}
//查询的思想和修改基本相同
ll query(ll l, ll r, ll c)
{
    ll ans = 0;
    ll startID = partID[l], endID = partID[r];
    if (startID == endID)
    {
        for (ll i = l; i <= r; i++)
        {
            ans += a[i] + tag[endID];
            ans %= c;
        }
        return ans;
    }
    for (ll i = l; partID[i] == startID; i++)
    {
        ans += a[i] + tag[startID];
        ans %= c;
    }
    for (ll i = startID + 1; i < endID; i++)
    {
        ans += partSum[i];
        ans %= c;
    }
    for (ll i = r; partID[i] == endID; i--)
    {
        ans += a[i] + tag[endID];
        ans %= c;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    partLen = sqrt(n);
    memset(partID, -1, sizeof(partID));
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        partID[i] = i / partLen + 1;
        partSum[partID[i]] += a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        ll opt, l, r, c;
        cin >> opt >> l >> r >> c;
        l--, r--;
        if (opt)
            cout << query(l, r, c + 1) << '\n';
        else
            add(l, r, c);
    }
    return 0;
}
