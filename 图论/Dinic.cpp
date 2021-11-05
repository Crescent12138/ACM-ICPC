#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=2e4+9,inf=1e9;
int head[maxn],sz=0,dis[maxn],iter[maxn];
struct {int nex,t,cap;} g[maxn*8];
void addedge(int f,int t,int cap){
	g[sz]={head[f],t,cap};
	head[f]=sz++;
	g[sz]={head[t],f,0};
	head[t]=sz++;
}
int Q[maxn];
int bfs(int s,int t){
	int l=0,r=0;Q[r++]=s;
	mem(dis,0);dis[s]=1;iter[s]=head[s];
	while(l<r) 
		for(int u=Q[l++],i=head[u];~i;i=g[i].nex){
			int v=g[i].t;
			if(g[i].cap&&!dis[v]){
				dis[v]=dis[u]+1;
				iter[v]=head[v];
				if(t==v) return 1;
				Q[r++]=v;
			}
		}
	return 0;
}
int dfs(int s,int t,int cap,int flow=0){
	if(s==t) return cap;
	for(int &i=iter[s];~i;i=g[i].nex){
		auto &e=g[i];
		if(dis[s]+1==dis[e.t]&&e.cap){
			int di=dfs(e.t,t,min(e.cap,cap-flow));
			if(di) flow+=di,
				e.cap-=di,g[i^1].cap+=di;
			else dis[e.t]=-9;
			if(flow==cap) break;
		}
	}
	return flow;
}
int dinic(int s,int t){
	int ans=0;
	while(bfs(s,t)) ans+=dfs(s,t,inf);
	return ans;
}
int main(){
memset(head,-1,sizeof head),sz=0;...
}
