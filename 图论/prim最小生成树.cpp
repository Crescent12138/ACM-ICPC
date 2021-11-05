<<<<<<< HEAD
/*
*邮箱：unique_powerhouse@qq.com
*blog:https://me.csdn.net/hzf0701
*注：文章若有任何问题请私信我或评论区留言，谢谢支持。
*
*/
#include<bits/stdc++.h>	//POJ不支持

#define rep(i,a,n) for (int i=a;i<=n;i++)//i为循环变量，a为初始值，n为界限值，递增
#define per(i,a,n) for (int i=a;i>=n;i--)//i为循环变量， a为初始值，n为界限值，递减。
#define pb push_back
#define IOS ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fi first
#define se second
#define mp make_pair

using namespace std;

const int inf = 0x3f3f3f3f;//无穷大
const int maxn = 1e3;//最大值。
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll>  pll;
typedef pair<int, int> pii;
//*******************************分割线，以上为自定义代码模板***************************************//

int n,m;//图的大小和边数。
int graph[maxn][maxn];//图
int lowcost[maxn],closest[maxn];//lowcost[i]表示i到距离集合最近的距离，closest[i]表示i与之相连边的顶点序号。
int sum;//计算最小生成树的权值总和。
void Prim(int s){
	//初始化操作，获取基本信息。
	rep(i,1,n){
		if(i==s)
			lowcost[i]=0;
		else
			lowcost[i]=graph[s][i];
		closest[i]=s;
	}
	int minn,pos;//距离集合最近的边，pos代表该点的终边下标。
	sum=0;
	rep(i,1,n){
		minn=inf;
		rep(j,1,n){
			//找出距离点集合最近的边。
			if(lowcost[j]!=0&&lowcost[j]<minn){
				minn=lowcost[j];
				pos=j;
			}
		}
		if(minn==inf)break;//说明没有找到。
		sum+=minn;//计算最小生成树的权值之和。
		lowcost[pos]=0;//加入点集合。
		rep(j,1,n){
			//由于点集合中加入了新的点，我们要去更新。
			if(lowcost[j]!=0&&graph[pos][j]<lowcost[j]){
				lowcost[j]=graph[pos][j];
				closest[j]=pos;//改变与顶点j相连的顶点序号。
			}
		}
	}
	cout<<sum<<endl;//closest数组就是我们要的最小生成树。它代表的就是边。
}
void print(int s){
	//打印最小生成树。
	int temp;
	rep(i,1,n){
		//等于s自然不算，故除去这个为n-1条边。
		if(i!=s){
			temp=closest[i];
			cout<<temp<<"->"<<i<<"边权值为："<<graph[temp][i]<<endl;
		}
	}
}
int main(){
	//freopen("in.txt", "r", stdin);//提交的时候要注释掉
	IOS;
	while(cin>>n>>m){
		memset(graph,inf,sizeof(graph));//初始化。
		int u,v,w;//临时变量。
		rep(i,1,m){
			cin>>u>>v>>w;
			//视情况而论，我这里以无向图为例。
			graph[u][v]=graph[v][u]=w;
		}
		//任取根结点，我这里默认取1.
		Prim(1);
		print(1);//打印最小生成树。
	}
	return 0;
}



=======
#include<iostream>  
#include<fstream>  
using  namespace std;  
  
#define MAX 100  
#define MAXCOST 0x7fffffff  
  
int graph[MAX][MAX];  
  
int prim(int graph[][MAX], int n)  
{  
    int lowcost[MAX];  
    int mst[MAX];                                 
    int i, j, min, minid, sum = 0;  
    for (i = 2; i <= n; i++)  
    {  
        lowcost[i] = graph[1][i];  
        mst[i] = 1;                                       //mst[]存放MST外的点i到MST最短距离时候对应的MST里的点标号
    }  
    mst[1] = 0;  
    for (i = 2; i <= n; i++)                        //要找出n-1个点为止
    {  
        min = MAXCOST;  
        minid = 0;  
        for (j = 2; j <= n; j++)  
        {  
            if (lowcost[j] < min && lowcost[j] != 0)  
            {  
                min = lowcost[j];  
                minid = j;  
            }  
        }  
        cout << "V" << mst[minid] << "-V" << minid << "=" << min << endl;  
        sum += min;  
        lowcost[minid] = 0;  
        for (j = 2; j <= n; j++)  
        {  
            if (graph[minid][j] < lowcost[j])                //不更新的话，lowcost[j]存的只是上一时刻的Lowcost[j]，MST外部的点到minid的距离会不会比到之前的MST里点得最小距离小？
       {  
                lowcost[j] = graph[minid][j];  
                mst[j] = minid;                               //点j到MST内的lowcot对应的MST里的点事minid
            }  
        }  
    }  
    return sum;  
}  
  
int main()  
{  
    int i, j, k, m, n;  
    int x, y, cost;  
    ifstream in("input.txt");  
    in >> m >> n;//m=顶点的个数，n=边的个数  
    //初始化图G  
    for (i = 1; i <= m; i++)  
    {  
        for (j = 1; j <= m; j++)  
        {  
            graph[i][j] = MAXCOST;  
        }  
    }  
    //构建图G  
    for (k = 1; k <= n; k++)  
    {  
        in >> i >> j >> cost;  
        graph[i][j] = cost;  
        graph[j][i] = cost;  
    }  
    //求解最小生成树  
    cost = prim(graph, m);  
    //输出最小权值和  
    cout << "最小权值和=" << cost << endl;  
    system("pause");  
    return 0;  
}  
>>>>>>> 278fb314a3da4713da79a94cc121bd19c9560df9
