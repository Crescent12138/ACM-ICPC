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