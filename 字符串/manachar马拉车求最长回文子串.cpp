#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
const int maxn=110000+9;
char s[maxn*2];
int p[maxn*2];
int manacher(){
	int len=strlen(s);
	memset(p,0,8*len+40);
	for (int i=len;i>=0;i--){
		s[i*2+2]=s[i];
		s[i*2+1]=2;
	}
	s[0]=1;
	len=len*2+2;
	for (int i=2,id=0,mx=0;i<len;i++){
		if (i<mx)
			p[i]=min(p[2*id-i],mx-i);
		else p[i]=1;
		while (s[i-p[i]]==s[i+p[i]])
			p[i]++;
		if (i+p[i]>mx)
			mx=i+p[i],id=i;
	}
	return *max_element(p+2,p+len)-1;
}
 //int main(){
//	while (scanf("%s",s)==1) printf("%d\n",manacher());
//}
