#include<stdio.h>
#include<bits/stdc++.h>
#define maxc 28
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
typedef long long ll;
int len[maxn * 2], //最长子串的长度(该节点字串数量=len[x]-len[link[x]])
link[maxn * 2],   //后缀链接(最短串前部减少一个字符所到达的状态)
cnt[maxn * 2],    //被后缀连接的数
nex[maxn * 2][maxc],  //状态转移(尾部加一个字符的下一个状态)(图)
idx, //节点编号
last;    //最后节点
ll epos[maxn * 2]; // enpos数（该状态子串出现数量）
char str[maxn];
ll a[maxn];		//长度为i的子串出现最大次数

void Iint() {	//初始化
	last = idx = 1; //1表示root起始点 空集
	link[1] = len[1] = 0;
}
//SAM建图
void Extend(int c) {     //插入字符，为字符ascll码值
	int x = ++idx; //创建一个新节点x;
	len[x] = len[last] + 1; //  长度等于最后一个节点+1
	epos[x] = 1;  //接受节点子串除后缀连接还需加一
	int p;  //第一个有C转移的节点;
	for (p = last; p && !nex[p][c]; p = link[p])nex[p][c] = x;//沿着后缀连接 将所有没有字符c转移的节点直接指向新节点
	if (!p)link[x] = 1, cnt[1]++;  //全部都没有c的转移 直接将新节点后缀连接到起点
	else {
		int q = nex[p][c];    //p通过c转移到的节点
		if (len[p] + 1 == len[q])    //pq是连续的
			link[x] = q, cnt[q]++; //将新节点后缀连接指向q即可,q节点的被后缀连接数+1
		else {
			int nq = ++idx;   //不连续 需要复制一份q节点
			len[nq] = len[p] + 1;   //令nq与p连续
			link[nq] = link[q];   //因后面link[q]改变此处不加cnt
			memcpy(nex[nq], nex[q], sizeof(nex[q]));  //复制q的信息给nq
			for (; p&&nex[p][c] == q; p = link[p])
				nex[p][c] = nq;    //沿着后缀连接 将所有通过c转移为q的改为nq
			link[q] = link[x] = nq; //将x和q后缀连接改为nq
 			cnt[nq] += 2; //  nq增加两个后缀连接
		}
	}
	last = x;  //更新最后处理的节点
}
void GetNpos() {	//求npos数，即该节点字串出现次数
	queue<int>q;
	for (int i = 1; i <= idx; i++)
		if (!cnt[i])q.push(i);   //将所有没被后缀连接指向的节点入队
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		epos[link[x]] += epos[x]; //子串数量等于所有后缀连接指向该节点的子串数量和+是否为接受节点
		if (--cnt[link[x]] == 0)q.push(link[x]);   //当所有后缀连接指向该节点的处理完毕后再入队
	}
}
void GetSubNum() {	//求不相同字串数量
	ll ans = 0;
	for (int i = 2; i <= idx; i++)ans += len[i] - len[link[i]];	//一状态子串数量等于len[i]-len[link[i]]
	printf("%lld\n",ans);
}
void GetSubMax() {	//求出所有长度为k的子串中出现次数最多的子串出现次数
	GetNpos();
	int n = strlen(str);
	for (int i = 1; i <= idx; i++)a[len[i]] = max(a[len[i]], epos[i]);	//长度≤k的子串中出现次数最多的子串出现次数的最小值
	for (int i = n - 1; i >= 1; i--)a[i] = max(a[i], a[i + 1]);		//求一遍后缀最大值就是答案
	for (int i = 1; i <= n; i++)printf("%lld\n", a[i]);

}
int main() {
	//freopen("c:/input.txt","r",stdin);
	return 0;
}
/*
问题1.给定文本T，询问格式如下：给定字符串P，问P是否是T的子串。
问题2.给定字符串S，问它有多少不同的子串。（模板中的GetSubNum函数）
问题3.给定字符串S，求其所有不同子串的总长度。
问题4.给定字符串S，一系列询问——给出整数K_i，计算S的所有子串排序后的第K_i个。
问题5.给定字符串S，找到和它循环同构的字典序最小字符串。
问题.给定文本T，询问格式如下：给定字符串P，希望找出P作为子串在文本T中出现了多少次（出现区间可以相交）。
问题6.给定文本T，询问格式如下：给定字符串P，求P在文本中第一次出现的位置。
问题7.给定文本T，询问格式如下：给定字符串P，要求给出P在T中的所有出现位置（出现区间可以相交）。
问题8.给定两个字符串S和T。要求找出它们的最长公共子串，即一个字符串X，它同时是S和T的子串。

*/