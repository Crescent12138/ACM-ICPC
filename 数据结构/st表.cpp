#include<bits/stdc++.h>

using namespace std;

/***
 * st表 模板元编程实现
 * @tparam ty 定义某种类型对象
 * @tparam cmp 定义双变量判断对象的比较重载 默认使用less<ty>
 */
template<typename ty, typename cmp =less<ty>>
class ST_table {
    std::vector<ty> st[23];
#ifndef MINGW32_SUPPORTS_MT_EH
    std::vector<int> Log;
#endif
public:
#define rep(a, b, c) for(int a= b ; a <= c ;a++)

    ST_table(int n, ty _num[]) {
        assert(n >= 1 && n <= 2e6);
        for (int i = 0; i <= log2(n); i++) st[i].resize(n + 1);
#ifndef MINGW32_SUPPORTS_MT_EH
        Log.resize(n + 1);
        rep(i, 1, n) Log[i] = Log[i / 2] + 1;
#endif
        rep(i, 1, n) st[0][i] = _num[i];
        for (int i = 1; 1 << i <= n; i++)
            for (int j = 1; j + (1 << i) - 1 <= n; j++)
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)], cmp());
    }
    ST_table(int n,vector<ty>& _num) {
        array<ty,2000006>_nums;
        int cnt = 0;
        for(auto &k :_num)_nums[++cnt] = k;
        ST_table(n,_nums);
    }
    ty query(int l, int r) {
        if (l > r) swap(l, r);
#ifndef MINGW32_SUPPORTS_MT_EH
        int x = __lg(r - l + 1);
#else
        int x = Log2[r - l + 1];
#endif
        return min(st[x][l], st[x][r - (1 << x) + 1], cmp());
    }
};

int main() {
    struct node {
        int a, b;
    };
    int a[] = {0, 1, 2, 3, 4, 5, 6};
    int n = 5;
    auto ttfff = [](int a, int b) { return a < b; };
    ST_table<int, decltype(ttfff)> stTable(n, a);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i << " " << j << " ";
            cout << stTable.query(i, j) << "\n";
        };
    }
}