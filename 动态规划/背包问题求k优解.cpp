#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MIN -0xffffff
int main(){
	int N,V,K;
	scanf("%d%d%d",&K,&V,&N);
	int c,w,i,j,k,a[K+2],b[K+2],**dp;
	dp=(int**)malloc((V+1)*sizeof(int*));
	for(i=0;i<=V;i++){
		dp[i]=(int*)malloc((K+1)*sizeof(int));
		memset(dp[i],0,(K+1)*sizeof(int));
	}
	for(i=0;i<=V;i++){//有的题目要求要恰好填满背包的最优值，因此除了dp[0][0]，其它都要赋值为负无穷 
		for(j=0;j<=K;j++){
			dp[i][j]=MIN;
		}
	}
	dp[0][1]=0;
	a[0]=b[0]=0;
	for(i=1;i<=N;i++){
		scanf("%d%d",&c,&w);
		for(j=V;j>=c;j--){
		for(k=1;k<=K;k++){//将状态分为两个临时状态，求解K优解的循环要写在背包容量内 
			a[k]=dp[j][k];
			b[k]=dp[j-c][k]+w;
		}
		int x,y,z;
		x=y=z=1;
		a[k]=b[k]=-1;//防止越界 
		while(z<=K && (a[x]!=-1||b[x]!=-1)){//将两个有序队列，从最优解排到次优解的队列合并 
			if(a[x]>b[y]){
				dp[j][z]=a[x++];
			}else{
				dp[j][z]=b[y++];
			}
			z++;//上面的判断就已经确定了第z优解，因此这里要递增，下次确定第z+1优解 
		}
		}
	}
	int ans=0;
	for(j=1;j<=K;j++)
	ans+=dp[V][j];
	printf("%d",ans);
}