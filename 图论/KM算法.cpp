#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define int long long 
vector<long long >ve[400];
const int N = 304;
const int INF = 0x3f3f3f3f;
int n;
int A[N], B[N];
char str[N];
long long  g[N][N];
int lx[N], ly[N], match[N];
int pre[N];
ll slack[N];
bool vis[N];
void bfs(int k) {
    int px, py = 0, y = 0;
    ll d;
    memset(pre, 0, sizeof pre);
    memset(slack, 0x3f, sizeof slack);
    match[py] = k;
    do {
        px = match[py], d = INF, vis[py] = 1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                int tp = lx[px] + ly[i] - g[px][i];
                if (slack[i] > tp)
                    slack[i] = tp, pre[i] = py;
                if (slack[i] < d)
                    d = slack[i], y = i;
            }
        }
        for (int i = 0; i <= n; i++) {
            if (vis[i])  lx[match[i]] -= d, ly[i] += d;
            else    slack[i] -= d;
        }
        py = y;
    } while (match[py]);
    while (py)   match[py] = match[pre[py]], py = pre[py];
}
ll KM() {
    memset(lx, 0, sizeof lx);
    memset(ly, 0, sizeof ly);
    memset(match, 0, sizeof match);
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        bfs(i);
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += g[match[i]][i];
    return res;
}
signed main() {

    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long  a, b, c, d;
        cin >> a >> b >> c >> d;
        // ans += a * a + b * b ;
        ve[i].emplace_back(a);
        ve[i].emplace_back(b);
        ve[i].emplace_back(c);
        ve[i].emplace_back(d);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = ve[i][0] * ve[i][0] + ve[i][1] * ve[i][1] + (ve[i][2] + (j - 1) * ve[i][3]) * (ve[i][2] + (j - 1) * ve[i][3]);
            g[i][j] = -g[i][j];
        }
    }
    //long long  ans = 0;

    cout << -KM() << "\n";

}