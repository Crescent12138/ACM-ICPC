#include<map>
using namespace std;
#define ll long long 
ll BSGS(ll y,ll z,ll p) {
    map<ll,ll> ma;
    ll m=sqrt(p),tmp=0;
    if(y%p==0&&z==0) return 1;
    if(y%p==0&&z!=0) return -1;
    for(int i=0;i<=m;i++) {
        if(!i) {tmp=z%p;ma[tmp]=i;continue;}
        tmp=(tmp*y)%p;
        ma[tmp]=i;
    }
    tmp=1;ll t= power(y,m,p);//快速幂
    for(int i=1;i*i<=p;i++) {
        tmp=(tmp*t)%p;
        if(ma[tmp])  {
            ll ans=i*m-ma[tmp];
            return ans;
        }
    }
    return -1;
}
