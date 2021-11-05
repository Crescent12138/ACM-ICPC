#include<iostream>
#include<queue>
using namespace std;
int n,m,s;
#define MM 500005
#define MN 10005
#define INF 99999999
#define IINF 2147483647
struct node{int u,v,w,next;};
node edge[MM];
int head[MN];
int spfa[MN];
queue<int>q;
bool inq[MN];
void SPFA()
{
    q.push(s);
    inq[s]=true;
    for(int i=1;i<=n;i++) spfa[i]=INF;
    spfa[s]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        inq[u]=false;
        for(int i=head[u];i>0;i=edge[i].next)
        {
            int v=edge[i].v;
            int w=edge[i].w;
            if(spfa[v]>spfa[u]+w)
            {
                spfa[v]=spfa[u]+w;
                if(!inq[v])
                {
                    inq[v]=true;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge[i]=(node){u,v,w,head[u]};
        head[u]=i;
    }
    SPFA();
    for(int i=1;i<=n;i++)
    {
        if(spfa[i]==INF) spfa[i]=IINF;
        cout<<spfa[i]<<" "; 
    }
    return 0;
}