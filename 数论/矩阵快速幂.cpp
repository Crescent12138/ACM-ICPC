#include<bits/stdc++.h>
using namespace std;
#define ll long long 
//ll dp[5];
ll const mod=1e9+7;
//ll h1[200005],h2[200005];
ll s[4][4];
ll tmp[4][4];
ll n,m;
void mul(ll s[4][4],ll t[4][4]){
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                tmp[i][j]=(tmp[i][j]+s[i][k]*t[k][j]%mod)%mod;
            }
        }
    }
    //for(int )
}
ll ss[4][4]={};
void qpow(){
    
    ss[0][0]=ss[1][1]=1;
    while(n){
        if(n&1){
            mul(ss,s);
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    ss[i][j]=tmp[i][j];
                }
            }
        }
        mul(s,s);
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    s[i][j]=tmp[i][j];
                }
            }
        n>>=1;
    }
}
ll a,b;
int main(){
    cin>>n>>a>>b;
    n--;
    s[0][0]=a;
    s[0][1]=b;
    s[1][0]=1;
    qpow();
    cout<<ss[0][0];
}