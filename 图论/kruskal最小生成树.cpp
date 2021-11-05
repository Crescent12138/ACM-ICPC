#include<algorithm>
using namespace std;
//int fa[10];
int n,m;
int i,j;
const int maxn=1e4;
int fa[maxn];
int rak[maxn];
struct edge{
	int u,v,w; //边的顶点，权值
}edges[maxn];
 //初始化（按秩合并）
inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        rak[i] = 1;
    }
}

//路径压缩
int findfa(int x) {                  //找到某个数x的祖先
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}


//合并（按秩合并）
inline void merge(int i, int j)
{
    int x = findfa(i), y = findfa(j);    //先找到两个根节点
    if (rak[x] <= rak[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (rak[x] == rak[y] && x != y)
        rak[y]++;                   //如果深度相同且根节点不同，则新的根节点的深度+1
}
void kruskal(){
	int sum = 0;
	int num = 0;
	int u,v;
	init(n);
	for(int i=0; i<m; i++)
	{
		u = edges[i].u;
		v = edges[i].v;
 
		if(findfa(u) != findfa(v)){ //u和v不在一个集合
			//printf("加入边：%d %d,权值： %d\n", u,v,edges[i].w);
			sum += edges[i].w;
			num ++;
			merge(u, v); //把这两个边加入一个集合。
		}
	}
    cout<<sum<<"\n";
	//printf("weight of MST is %d \n", sumWeight);
}
 
//比较函数，用户排序
bool cmp(edge a,edge b){
    return a.w<b.w;
}

int main() {
    //freopen("in.txt","r",stdin);//输入重定向，输入数据将从in.txt文件中读取
    //freopen("out.txt","w",stdout);//输出重定向，输出数据将保存在out.txt文件中
    while(cin>>n&&n){
        memset(edges,0,sizeof(edges));
        scanf("%d", &m);
        for(i=0; i<m; i++){
            scanf("%d %d %d", &edges[i].u,  &edges[i].v,  &edges[i].w);
            edges[i+m].u=edges[i].v;
            edges[i+m].v=edges[i].u;
            edges[i+m].w=edges[i].w;
        }
        sort(edges,edges+m, cmp);
        kruskal();
    }
	return 0;
}
