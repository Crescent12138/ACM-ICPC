#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll maxn = 5e5 + 5;
ll a[maxn];
ll partLen;       //�鳤
ll partID[maxn];  //���
ll partSum[maxn]; //���
ll tag[maxn];     //����

void add(ll l, ll r, ll c)
{
    ll startID = partID[l], endID = partID[r];
    if (startID == endID) //l��r��ͬһ���飬ֱ�ӱ���
    {
        for (ll i = l; i <= r; i++)
        {
            a[i] += c;
            partSum[startID] += c;
        }
        return;
    }
    //����ͬһ���飬�ֳ����δ���
    for (ll i = l; partID[i] == startID; i++)//��ʼ��
    {
        a[i] += c;
        partSum[startID] += c;
    }
    for (ll i = startID + 1; i < endID; i++)//�м����ɸ�����
    {
        tag[i] += c;
        partSum[i] += c * partLen;
    }
    for (ll i = r; partID[i] == endID; i--)//ĩβ��
    {
        a[i] += c;
        partSum[endID] += c;
    }
}
//��ѯ��˼����޸Ļ�����ͬ
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
