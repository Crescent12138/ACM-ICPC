const int N = 1001;
//重点的三个函数（核心部分）
int fa[N];

void init() {                       //初始化
	for (int i = 0; i < N; i++)
		fa[i] = i;
}

int findfa(int x) {                  //找到某个数x的祖先
	return x == fa[x] ? x : (fa[x] = findfa(fa[x]));
}

void Union(int x, int y) {            //把x和y合并（二者之间连一条线）
	int fx = findfa(x), fy = findfa(y);
	if (fx != fy) fa[fx] = fy;              //注意是fa[fx]=fy, 而不是fa[x]=fy; 当然了fa[fy]=fx也行
}
