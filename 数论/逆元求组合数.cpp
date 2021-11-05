#define LL long long 
const int MOD=1e9+7;
int inv(int a)
{
    //return fpow(a, MOD-2, MOD);
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inv(MOD % a) % MOD;
}
LL C(LL n, LL m)
{
    if (m < 0)
        return 0;
    if (n < m)
        return 0;
    if (m > n - m)
        m = n - m;
    LL up = 1, down = 1;
    for (LL i = 0; i < m; i++)
    {
        up = up * (n - i) % MOD;
        down = down * (i + 1) % MOD;
    }
    return up * inv(down) % MOD;
}