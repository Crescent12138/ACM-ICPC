#include<bits/stdc++.h>
using namespace std;
	const int maxn=200005;
	int fa[maxn];
	int va[maxn];//距离祖先节点的距离 
	
	int n,m;
	
	int init(){
		for(int i=0;i<maxn;i++){
			fa[i]=i;
			va[i]=0;
		}
	}
	 
	int find(int x){
		if(fa[x]==x)
			return x;
		int root=find(fa[x]);//祖先节点 
		va[x]+=va[fa[x]];//更新一下va 
		return fa[x]=root; //将x直接连接到祖先节点上 
	}
	
	void unite(int x,int y,int v){
		int fx=find(x),fy=find(y);
		fa[fx]=fy;
		va[fx]=v+va[y]-va[x];
	} 
	
	int main(){
		int n,m,ans,x,y,z;
		while(cin>>n>>m){
			ans=0;
			init();
			while(m--){
				cin>>x>>y>>z;
				x--;
				if(find(x)==find(y)){
					if(va[x]-va[y]!=z) 
						ans++;
				}
				else{
					unite(x,y,z);
				} 
			}
			cout<<ans<<endl;
		}
	}	
