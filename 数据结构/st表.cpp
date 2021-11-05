#include <bits/stdc++.h>
#define maxn 50005
using namespace std;
int read()
{
    int ans = 0;
    char c = getchar();
    while (!isdigit(c))
        c = getchar();
    while (isdigit(c))
    {
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return ans;
}
int Log2[maxn], Min[maxn][17], Max[maxn][17];
int n, m;
void init() {
    for (int i = 2; i <= n; ++i)
        Log2[i] = Log2[i / 2] + 1;
    for (int i = 1; i <= 16; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
        {
            Min[j][i] = min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
            Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
        }
}
int search_max(int l, int r) {
    int s = Log2[r - l + 1];
    int ma = max(Max[l][s], Max[r - (1 << s) + 1][s]);
    return ma;
}
int search_min(int l, int r) {
    int s = Log2[r - l + 1];
    int mi = min(Min[l][s], Min[r - (1 << s) + 1][s]);
    return mi;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; ++i)
    {
        int x = read();
        Min[i][0] = x;
        Max[i][0] = x;
    }

    for (int i = 0; i < m; ++i)
    {
        int l = read(), r = read();
        printf("%d\n", search_max(l, r) - search_min(l, r));
    }
    return 0;
}