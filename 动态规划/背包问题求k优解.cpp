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
	for(i=0;i<=V;i++){//�е���ĿҪ��Ҫǡ����������������ֵ����˳���dp[0][0]��������Ҫ��ֵΪ������ 
		for(j=0;j<=K;j++){
			dp[i][j]=MIN;
		}
	}
	dp[0][1]=0;
	a[0]=b[0]=0;
	for(i=1;i<=N;i++){
		scanf("%d%d",&c,&w);
		for(j=V;j>=c;j--){
		for(k=1;k<=K;k++){//��״̬��Ϊ������ʱ״̬�����K�Ž��ѭ��Ҫд�ڱ��������� 
			a[k]=dp[j][k];
			b[k]=dp[j-c][k]+w;
		}
		int x,y,z;
		x=y=z=1;
		a[k]=b[k]=-1;//��ֹԽ�� 
		while(z<=K && (a[x]!=-1||b[x]!=-1)){//������������У������Ž��ŵ����Ž�Ķ��кϲ� 
			if(a[x]>b[y]){
				dp[j][z]=a[x++];
			}else{
				dp[j][z]=b[y++];
			}
			z++;//������жϾ��Ѿ�ȷ���˵�z�Ž⣬�������Ҫ�������´�ȷ����z+1�Ž� 
		}
		}
	}
	int ans=0;
	for(j=1;j<=K;j++)
	ans+=dp[V][j];
	printf("%d",ans);
}