#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct Point
{
    double x, y;
    Point() {}
    Point(double xx, double yy) : x(xx), y(yy) {}
    bool operator<(const Point &a) const
    {
        if (x == a.x)
            return y < a.y;
        return x < a.x;
    }
    Point operator-(const Point a) const
    {
        return Point(x - a.x, y - a.y);
    }
} p[N], st[N];//p是点,st是栈

bool check(Point a, Point b)
{
    return a.x * b.y <= b.x * a.y;
}//检查斜率

bool judge()
{
    sort(p + 1, p + n + 1);
    int head = 0;
    //凸包下半边
    for (int i = 1; i <= n; ++i)
    {
        while (head > 1 && check(st[head] - st[head - 1], p[i] - st[head]))
            head--;
        st[++head] = p[i];
    }
    int tmp = head;
    //凸包上半边
    for (int i = n - 1; i >= 1; --i) //起点一定要加进去，为了把栈里面不符合的点除去，然后最后结果减1即可
    {
        while (head > tmp && check(st[head] - st[head - 1], p[i] - st[head]))
            head--;
        st[++head] = p[i];
    }
    return head - 1 == n;
}
