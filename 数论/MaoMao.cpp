#include <iostream>
#include <cassert>
#include<iostream>
#include<vector>
#include<math.h>
#include<utility>
#include<algorithm>
//#include<>
#include<map>
#include<random>
#include<bits/stdc++.h>
#ifdef  __WIN32__
#include"debug/log_4.hpp"
using namespace ssss;
#endif
namespace MaoMao{
    const int mod = 998244353;
    typedef long long ll;

    typedef __int128 lll;
    /***
     * 快速幂取模
     * @param x 底数
     * @param n 指数
     * @param m 模数 默认 998244353
     * @return
     */
    ll qpow(ll x,ll n,ll m = mod){
        x %= m;
        assert(0 <= n && 1 <= m && x <= m && 0 <= x);
        ll ans = 1%m;
        while(n){
            if(n&1)ans = (lll)ans * x % m;
            n >>= 1;
            x = (lll)x * x % m;
        }
        return ans;
    }
    typedef std::pair<ll,ll> pll;
    /***
     * 拓展欧几里得_迭代版本
     * @param a
     * @param b
     * @return x 和 y
     */
    pll ex_gcd(ll a, ll b){
        assert(a >= 0 && b >= 0);
        a = a % b;
        if (a == 0) return {b,0};
        auto s = b, t = a;
        ll m0 = 0, m1 = 1;
        while(t) {
            m0 -= s / t * m1;
            s %= t;
            std::swap(s, t);
            std::swap(m0, m1);
        }
        if (m0 < 0) m0 += b / s;
        return {s, m0};
    }
    /***
     * 拓展欧几里得_递归版本
     * @param a
     * @param b
     * @param x 直接返回x
     * @param y 直接返回y
     * @return
     */
    ll ex_gcd2(ll a,ll b,ll &x,ll &y){
        if(!b) {x=1,y=0;return a;}
        ll d=ex_gcd2(b,a%b,y,x);
        y-=a/b*x;
        return d;
    }
    ll inv_mod(ll x, ll m) {
        assert(1 <= m);
        auto [z0,z1] = ex_gcd(x, m);
        assert(z0 == 1);
        return z1;
    }
    /***
     * 分解质因数——简易版，用于数据范围在1e12以内
     * @param num 数字
     * @return 质因数列表从小到大排序
     */
    std::vector<pll> divide_pri(ll num){
        std::vector<pll>ans;
        for(ll i = 2 ; i*i <= num;i++){
            int cnt = 0;
            while(num%i==0){
                num/=i;
                cnt++;
            }
            cnt != 0 ?(ans.emplace_back(i,cnt),0):0;
        }
        num != 1 ?(ans.emplace_back(num,1),0):0;
        return ans;
    }
    /***
     * 数论分块 \sum_{i = l} ^ r [ n / i ]
     * @param n 分块总数
     * @param l 左边界
     * @param r 右边界
     * @param m 取模数
     * @return 左闭右闭结果
     */
    ll math_theory_block(ll n ,ll l, ll r,ll m = mod ){
        ll ans = 0 ,rx;
        for( ; l <= r ;l = rx + 1){
            rx = std::min(n / (n / l),r);
            ans += n / l * (rx - l + 1) ;
//            ans %= m; 不需要取模就去掉这行即可
        }
        return ans;
    }
    /***
     * 单个数字的欧拉函数 简易版
     * @param n 数字
     * @return phi(n)
     */
    ll euler_phi(ll n){
        ll m = sqrtl(n+0.5);
        ll ans = n;
        for(ll i = 2 ; i <= m ; i++){
            if(n % i == 0){
                ans = ans / i * (i - 1);
                while(n % i == 0)n /= i;
            }
            if(n > 1) ans = ans / n * (n - 1);
            return ans;
        }
    }
    /***
     * 欧拉筛+欧拉函数
     */
    class phi_base{
    public:
        std::vector<int>phi;
        std::vector<int>pri;
        std::vector<bool>vis;
        phi_base(int n){
            phi.resize(n+5);
            vis.resize(n+5);
            phi[1] = 1;
            for(int i = 2 ; i < n + 5 ;  i++){
                if(!vis[i]) pri.emplace_back(i);
                phi[i] = i - 1;
                for(auto j:pri){
                    if(1ll * j * i >= n + 5)break;
                    vis[j * i] = true;
                    phi[j * i] = phi[j] * phi[i];
                    if(i % j == 0){
                        phi[i * j] = phi[i] * j;
                        break;
                    }
                }
            }
        }
    };
    /***
     * pollard rho 板子
     */
    std::mt19937 rd((ll)(new int));
    typedef __int128_t lll;
    const ll test[]={2,325,9375,28178,450775,9780504,1795265022};
    /***
     * 素性测试
     * @param n 判断数字素性
     * @return
     */
    int miller_robin(ll n){
        if (n<2||n%6%4!=1) return (n|1)==3;
        ll q=__builtin_ctzll(n-1),m=(n-1)>>q;
        for(ll a:test){
            if(a>=n) break;
            ll x=qpow(a,m,n),x1,i=q;
            for(;i--&&x!=1;x=x1){
                x1=(lll)x*x%n;
                if(x1==1&&x!=1&&x!=n-1) return 0;
            }
            if(x!=1) return 0;
        }
        return 1;
    }
    // 答案封装口
    std::map<ll,ll> ans;
    ll pollard_rho(ll x){
        ll s=0,t=0,c=rd()%(x-1)+1,d=1;
        for(ll val,step,g=1;d==1;g<<=1,s=t){
            val=1;
            for(step=1;d==1&&step<=g;step++){
                t=((lll)t*t+c)%x;
                val=(lll)val*abs(t-s)%x;
                if(step%100==0) d=std::__gcd(val,x);
            }
            d=std::__gcd(val,x);
        }
        return d;
    }
    /***
     * pho 调度接口
     * @param n 需要分解质因数的数字
     */
    void fac(ll n){
        if(n<2) return;
        if(miller_robin(n)){
            ans[n]++;return;
        }
        ll p=n;
        while(p>=n) p=pollard_rho(n);
        fac(n/p),fac(p);
    }


    struct Data {
        Data() { f = g = h = 0; }

        ll f, g, h;
    };  // 三个函数打包
    ll i2 = 499122177, i6 = 166374059;
    /***
     * 类欧几里得算法
     * 详情见oi-wiki https://oi-wiki.org/math/number-theory/euclidean/
     * @param n
     * @param a
     * @param b
     * @param c
     * @param P 模数
     * @return
     */
    Data like_Euclid(ll n, ll a, ll b, ll c,ll P = mod) {
        ll ac = a / c, bc = b / c, m = (a * n + b) / c, n1 = n + 1, n21 = n * 2 + 1;
        Data d;
        if (a == 0) {  // 迭代到最底层
            d.f = bc * n1 % P;
            d.g = bc * n % P * n1 % P * i2 % P;
            d.h = bc * bc % P * n1 % P;
            return d;
        }
        if (a >= c || b >= c) {  // 取模
            d.f = n * n1 % P * i2 % P * ac % P + bc * n1 % P;
            d.g = ac * n % P * n1 % P * n21 % P * i6 % P + bc * n % P * n1 % P * i2 % P;
            d.h = ac * ac % P * n % P * n1 % P * n21 % P * i6 % P +
                    bc * bc % P * n1 % P + ac * bc % P * n % P * n1 % P;
            d.f %= P, d.g %= P, d.h %= P;
            Data e = like_Euclid(n, a % c, b % c, c);  // 迭代
            d.h += e.h + 2 * bc % P * e.f % P + 2 * ac % P * e.g % P;
            d.g += e.g, d.f += e.f;
            d.f %= P, d.g %= P, d.h %= P;
            return d;
        }
        Data e = like_Euclid(m - 1, c, c - b - 1, a);
        d.f = n * m % P - e.f, d.f = (d.f % P + P) % P;
        d.g = m * n % P * n1 % P - e.h - e.f, d.g = (d.g * i2 % P + P) % P;
        d.h = n * m % P * (m + 1) % P - 2 * e.g - 2 * e.f - d.f;
        d.h = (d.h % P + P) % P;
        return d;
    }
    /***
     * BSGS 最小的 x 复杂度在sqrt(p)*log(sqrt(p)) 中
     * @param a
     * @param b
     * @param Mod 取模数
     * @return a^x == b (mod p)
     */
    ll log_Mod(ll a,ll b,ll Mod = mod) {
        std::map<ll,ll> mp;
        ll m=sqrtl(Mod+0.5),p=1,x=1;
        if(b==1) return 0;
        for(int i=0;i<m;i++) mp[b*p%Mod]=i,p=(p*a)%Mod;
        for(ll i=m;i<=Mod;i+=m){
            x=(x*p)%Mod;
            if(mp.count(x)) return i-mp[x];
        }
        return -1;
    }

}
int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);
    int n ,b,p;
    std::cin >> p>>b>>n ;
    MaoMao::ll ans = MaoMao::log_Mod(b,n,p);
    if(ans == -1){
        std::cout<<"no solution\n";
    }else{
        std::cout<<ans<<"\n";
    }

}