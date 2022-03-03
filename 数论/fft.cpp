#define rep(i,a,b) for(int i=a;i<(int)b;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1);
const int maxn=1e5+9;
typedef complex<double> C;
void fft(C a[],int n,int ty){
	static C w[maxn*4];w[0].real(1);
	for(int i=0,j=0;i<n;i++){
		if(i>j) swap(a[i],a[j]);
		for(int l=n/2;(j^=l)<l;l/=2);
	}
	for(int i=1;i<n;i*=2){
		C wn(cos(pi/i),ty*sin(pi/i));
		for(int j=(i-2)/2;~j;j--)
			w[j*2+1]=(w[j*2]=w[j])*wn;
		for(int j=0;j<n;j+=i*2)
			for(int k=j;k<j+i;k++){
				C x=a[k],y=a[k+i]*w[k-j];
				a[k]=x+y;a[k+i]=x-y;
			}
	}
	if(ty!=1) for(int i=0;i<n;i++) a[i]/=n;
}
ll mod;
void mul(int a[],int n,int b[],int m){
	static C c[maxn*4],d[maxn*4],e[maxn*4];
	int len=1<<int(ceil(log2(n+m)));
	rep(i,0,n) 
		c[i]=C(a[i]>>15,a[i]&0x7fff);
	fill(c+n,c+len,C());
	rep(i,0,m) 
		d[i]=C(b[i]>>15,b[i]&0x7fff);
	fill(d+m,d+len,C());
	fft(c,len,1),fft(d,len,1);
	rep(i,0,len){
		int j=(len-i)&(len-1);
		e[i]=d[i]*C((c[i].real()+c[j].real())/2,(c[i].imag()-c[j].imag())/2);
		d[i]=d[i]*C((c[i].imag()+c[j].imag())/2,(c[j].real()-c[i].real())/2);
	}
	fft(d,len,-1),fft(e,len,-1);
	rep(i,0,len){
		ll x=e[i].real()+0.5,y=e[i].imag()+0.5,
			z=d[i].real()+0.5,w=d[i].imag()+0.5;
		ll t=(x%mod<<30)+((y+z)%mod<<15)+w;
		a[i]=(t%mod+mod)%mod;
	}
}
int a[maxn*4],b[maxn*4],n,m,len;
int main(){
	scanf("%d%d%lld",&n,&m,&mod);
	n++,m++;
	rep(i,0,n) scanf("%d",a+i);
	rep(i,0,m) scanf("%d",b+i);
	mul(a,n,b,m);
	n+=m-1;
	rep(i,0,n) printf("%d ",a[i]);
}
