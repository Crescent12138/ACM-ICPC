#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define ll long long
#define ull unsigned long long
ull hash1[200005],hash2[200005];
//ull hash3[200005],hash4[200005];
string s;
//const int mod = 1e9+7;
ull p[200005];
ull mod=122420729;
ull mmd=163227661;
ll qpow(ll a, ll b, ll m) {
	if (b == 0) return 1;
	if (b & 1) return a * qpow(a, b - 1, m) % m;
	else {
		ll num = qpow(a, b / 2, m);
		return num * num % m;
	}
}

ll len=0;
unordered_set<ll>st;
ull gethash1(int l,int r){
    return (hash1[r]-hash1[l-1]*p[r-l+1]%mod+mod)%mod;
}
ull gethash2(int l,int r){
    return (hash2[l]-hash2[r+1]*p[r-l+1]%mod+mod)%mod;
}
vector<int >ve;
int main(){
<<<<<<< HEAD
    cin>>s; 
=======
    cin>>s;
>>>>>>> 278fb314a3da4713da79a94cc121bd19c9560df9
    len=s.length();
    for(int i=0;i<len;i++){
        hash1[i+1]=(hash1[i]*2333+s[i]-'a'+1)%mod;
        hash2[len-i]=(hash2[len-i+1]*2333+s[len-i-1]-'a'+1)%mod;
        // cout<<i<<" "<<hash1[i]<<"\n";
    }
    for(int i=0;i<=len;i++){
        p[i]=qpow(2333,i,mod);
    }
    int mx=0;
    for(int i=2;i<=len;i++){
        int t=0;
        for(int j=i,k=1;j<=len;j+=i,k+=i){
            ull ss=gethash1(k,j);
            ull se=gethash2(k,j);
            //for(int q=k-1;q<j;q++)cout<<s[q];
            // cout<<"\n";
            // cout<<ss<<" "<<se<<"\n";
            // cout<<"-----------------";
            if(!st.count(ss)&&!st.count(se)){
                st.insert(ss);
                st.insert(se);
                t++;
            }
        }
        if(mx<t){
            mx=t;
            ve.clear();
            ve.push_back(i);
        }
       else if(mx==t){
           ve.push_back(i);
       }
        st.clear();
    }
    cout<<mx<<"\n";
    //int n=ve.size();
  for(auto i:ve)
      cout<<i<<" ";
  
}