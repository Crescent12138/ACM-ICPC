#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define MAX 10005
#define ll long long

vector<ll> g[MAX];
ll color[MAX], vis[MAX], stack[MAX], dfn[MAX], low[MAX], cnt[MAX];
//deep:节点编号 top：栈顶  sum：强连通分量数目
ll deep, top, sum, res = 0;

void tanjan(ll v) {
	dfn[v] = ++deep;
	low[v] = deep;   //(1)初始化dfn数组，同时将low设置为相同值
	vis[v] = 1;
	stack[++top] = v;//(2)入栈，作为栈顶元素，同时更新vis数组

	for (unsigned i = 0; i < g[v].size(); i++) {//(3)遍历所有可能到达的点
		ll id = g[v][i];
		if (!dfn[id]) {//如果这个点从没访问过，则先放问它，再用它更新low[v]的值
			tanjan(id);
			low[v] = min(low[v], low[id]); //他的儿子如果能连到更小的祖先节点，显然他也可以
		}
		else {
			if (vis[id]) {//不在栈中的点，要么没有访问，要么不能到达id，所以只需要判断栈中的
				low[v] = min(low[v], low[id]);
			}
		}
	}

	if (low[v] == dfn[v]) {//(4)自己和子节点形成了强连通分量，或者只有自己孤身一人
		color[v] = ++sum;
		vis[v] = 0;
		while (stack[top] != v) {//将从v开始所有的点取出
			color[stack[top]] = sum;//给予同一颜色
			vis[stack[top--]] = 0;//出栈要顺便修改vis
		}
		top--;
	}
}
