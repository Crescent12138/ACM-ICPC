 for(int i=1;i<=n;i++)a[i]=read();
    ll p=1e9+7;
    s[0] = 1;
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] * a[i] % p;
    sv[n] = qpow(s[n], p - 2);
    // 当然这里也可以用 exgcd 来求逆元,视个人喜好而定.
    for (int i = n; i >= 1; --i) sv[i - 1] = sv[i] * a[i] % p;
    for (int i = 1; i <= n; ++i) inv[i] = sv[i] * s[i - 1] % p;