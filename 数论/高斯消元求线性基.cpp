typedef bitset<maxn> bi;
typedef bi mat[maxn];
int n;
int gause(mat a){
    int l=0,c=0;
    for(;c<n;l++,c++){
        int p=l;
        for(int i=l;i<n;i++) if(a[i][c]) p=i;
        swap(a[l],a[p]);
        if(a[l][c]==0) {l--;continue;}
        for(int i=0;i<n;i++)
            if(i!=l&&a[i][c]) a[i]^=a[l];
    }
    return n-l;
}