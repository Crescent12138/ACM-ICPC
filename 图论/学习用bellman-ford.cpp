#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    int u[8], v[8], w[8];	// 起点、终点、权值
    
    int first[6] = { 0 }, next[8] = { 0 };      // 用于构建邻接表
    int dis[6] = { 0 }, book[6] = { 0 };  // 存储路径 与 标记
    int que[101] = { 0 }, head = 1, tail = 1; // 队列完成此例
    
    int inf = 999999999;      // inf 表示无穷大

    scanf("%d%d", &n, &m);      // 顶点与边的数量
    for (i = 1; i <= n; i++) {	// 初始点的估计值
        dis[i] = inf;
    }
    dis[1] = 0;         // 一号顶点就位
    
    for (i = 1; i <= n; i++) {
        first[i] = -1;       // 表示所有的顶点当前没有边
    }

    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
	
	// 形成邻接表的关键
	// first[u[i]] 保存顶点 u[i] 的第一条边的编号
	// next[i] 存储 "编号为 i 的边" 的 "下一条边" 的编号
  	next[i] = first[u[i]];
  	first[u[i]] = i;
    }

    que[tail++] = 1;
    book[1] = 1;         // 1号顶点标记

    while (head < tail) {
    
        k = first[que[head]];      // 当前需要处理的队首顶点
        while (k != -1) {
            if (dis[v[k]] > dis[u[k]] + w[k]) {  // 判断是否可以松弛
    	        dis[v[k]] = dis[u[k]] + w[k];  // 更新路径 
    	        if (book[v[k]] == 0)    // 判断是否已经存在于队列之中
    	        {
     	            que[tail++] = v[k];    // 当前点入队
       	            book[v[k]] = 1;     // 标记当前点
    	        }
            }
            k = next[k];
        }
        book[que[head]] = 0;      // 可能会有重复的顶点入队
        head++;          // 出队
    }

    for (i = 1; i <= n; i++){
        printf("%d ", dis[i]);
    }   

    return 0;
}
