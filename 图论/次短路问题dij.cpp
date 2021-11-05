#define N 100000+10
#define INF 100000000
typedef pair<int, int>P;
int n,r;
struct Edge{ int to, cost; };
vector<Edge>G[N];
int dist[N], dist2[N];
void addedge(int u, int v,int w)
{
	G[u].push_back(Edge{ v, w });
	G[v].push_back(Edge{ u, w });
}
void solve()
{
	priority_queue<P, vector<P>, greater<P> >q;
	fill(dist, dist + n, INF);
	fill(dist2, dist2 + n, INF);
	dist[0] = 0;
	q.push(P(0, 0));
	while (!q.empty())
	{
		P u = q.top(); q.pop();
		int v = u.second, d = u.first;
		if (dist2[v] < d)continue;//取出的不是次短距离，抛弃
		for (int i = 0; i < G[v].size(); i++)
		{
			Edge&e = G[v][i];
			int d2 = d + e.cost;
			if (dist[e.to]>d2)//更新最短距离
			{
				swap(dist[e.to], d2);
				q.push(P(dist[e.to], e.to));
			}
			if (dist2[e.to]>d2&&dist[e.to] < d2)//更新次短距离
			{
				dist2[e.to] = d2;
				q.push(P(dist2[e.to], e.to));
			}
		}
	}
	printf("%d\n", dist2[n - 1]);
}