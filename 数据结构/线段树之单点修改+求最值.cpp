#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 7;
const ll mod = 2147483647;
struct node
{
    ll sum, l, r;
}tree[N];
ll input[N];
inline int read()//inline 加速读入
{
	int x=0;char c=getchar();//x代表返回值，c代表读取的字符
	while (c<'0'||c>'9') c=getchar();//读取所有非数部分
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();//如果读取的字符为数，加入返回值
	return x;
}
#define maxn 100007  //元素总个数
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1
int Sum[maxn << 2], Add[maxn << 2];//Sum求和，Add为懒惰标记 
int mm[maxn<<2];
int A[maxn], n,m;//存原数组数据下标[1,n] 
void PushUp(int rt) { 
	//Sum[rt] = Sum[rt << 1] + Sum[rt << 1 | 1]; 
    mm[rt]=max(mm[rt << 1],mm[rt << 1 | 1]);
}
void Build(int l, int r, int rt) { 
	if (l == r) {
        mm[rt]=A[l];
		return;
	}
	int m = (l + r) >> 1;
	Build(l, m, rt << 1);
	Build(m + 1, r, rt << 1 | 1);
	PushUp(rt);
}
void Update(int L, int C, int l, int r, int rt) {
	if (l == r) {
		mm[rt] = C;
		return;
	}
	int m = (l + r) >> 1;
	if (L <= m) Update(L, C, l, m, rt << 1);
	else       Update(L, C, m + 1, r, rt << 1 | 1);
	PushUp(rt);
}
int Query(int L, int R, int l, int r, int rt) {//L,R表示操作区间，l,r表示当前节点区间，rt表示当前节点编号
	if (L <= l && r <= R) {
		return mm[rt];
	}
	int m = (l + r) >> 1;
	int ANS = 0;
	if (L <= m) ANS = max(Query(L, R, l, m, rt << 1),ANS);
	if (R > m) ANS = max(Query(L, R, m + 1, r, rt << 1 | 1),ANS);
	return ANS;
}
int main(){
    freopen("in.txt","r",stdin);//输入重定向，输入数据将从in.txt文件中读取
    freopen("out.txt","w",stdout);//输出重定向，输出数据将保存在out.txt文件中
    while(cin>>n>>m){

        memset(mm,0,sizeof(mm));
        for(int i=1;i<=n;i++){
            A[i]=read();
        }
        int l,r;
        Build(1,n,1);
        for(int i=1;i<=m;i++){
            char s;
            cin>>s;
            if(s=='Q'){
                l=read();
                r=read();
                cout<<Query(l,r,1,n,1)<<"\n";
            }else if(s=='U'){
                l=read();
                r=read();
                Update(l,r,1,n,1);
            }
        }
    }
}