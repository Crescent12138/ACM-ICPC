bitset<maxn> bt;
int main()
{
    int n,a,sum = 0;
    scanf("%d",&n);
    bt[0] = 1;
    rep(i,0,n){
        scanf("%d",&a);
        bt |= bt<<a;
        sum += a;
    }
    rep(j,(sum+1)/2,sum+1) if(bt[j]) return printf("%d",j),0;
    return 0;
}