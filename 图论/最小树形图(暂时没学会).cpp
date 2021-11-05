#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#include<fstream>
#include<set>
#include<map>
#include<sstream>
#include<iomanip>
#define ll long long
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
const int MAXM = 40010;
struct Edge {
	int u, v;
	int cost;
}edge[MAXM];
int pre[MAXN], id[MAXN], vis[MAXN];
int in[MAXN], pos;
int zhuliu(int rt, int n, int m) {
	int u, v;
	int res = 0;
	while (1) {
		for (int i = 0; i < n; i++) in[i] = INF;
		for (int i = 0; i < m; i++)
			if (edge[i].u != edge[i].v && edge[i].cost < in[edge[i].v]) {
				pre[edge[i].v] = edge[i].u;
				in[edge[i].v] = edge[i].cost;
				if (edge[i].u == rt) pos = i;   //起点
			}
		for (int i = 0; i < n; i++)
			if (i != rt && in[i] == INF) return -1;//不存在最小树形图
		int tn = 0;
		memset(id, -1, sizeof(id));
		memset(vis, -1, sizeof(vis));
		in[rt] = 0;
		for (int i = 0; i < n; i++) {
			res += in[i];
			v = i;
			while (vis[v] != i && id[v] == -1 && v != rt) {
				vis[v] = i;
				v = pre[v];
			}
			if (v != rt && id[v] == -1) {
				for (int u = pre[v]; u != v; u = pre[u]) id[u] = tn;
				id[v] = tn++;
			}
		}
		if (tn == 0) break;//没有有向环
		for (int i = 0; i < n; i++)
			if (id[i] == -1) id[i] = tn++;
		for (int i = 0; i < m; i++) {
			v = edge[i].v;
			edge[i].u = id[edge[i].u];
			edge[i].v = id[edge[i].v];
			if (edge[i].u != edge[i].v) edge[i].cost -= in[v];
			//else swap(edge[i], edge[--m]);
		}
		n = tn;
		rt = id[rt];
	}
	return res;
}
int n, m;
int main() {
	while (~scanf("%d%d", &n, &m)) {
		int L = 0, sum = 0;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &edge[L].u, &edge[L].v, &edge[L].cost);
			sum += edge[L++].cost;
		}
		sum++;
		for (int i = 0; i < n; i++) {
			edge[L].u = n;
			edge[L].v = i;
			edge[L++].cost = sum;
		}
		int ans = zhuliu(n, n + 1, L);
		if (ans == -1 || ans >= 2 * sum) puts("impossible");
		else printf("%d %d\n", ans - sum, pos - m);
		puts("");
	}
	return 0;
}
