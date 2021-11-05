ll s[66],a[66];
int n,sz;
void insert(ll x){
    rep(i,0,62)if(x>>i&1){
        if(s[i]) x^=s[i];
        else {
            swap(s[i],x);
            sz++;break;
        }
    }
}