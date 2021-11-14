#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read()
{
    ll x=0,ch=getchar(),j=1;
    while(!isdigit(ch))
    {
        if(ch=='-') j=-1;
        ch=-getchar();
    }
    while(isdigit(ch))
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*j;

}
int num[1000005];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        cin>>n;
        cin>>s;
        int num_0 = 0,num_1 = 0;
        for(int i = 0 ;i < s.size() ; i++)  {
            if(s[i] == '1') {
                num[num_1] = num_0;
                num_1 ++;
                num_0 = 0;
            }else{
                num_0 ++;
            }
        }
        num[num_1] = num_0;
        int f= 1;
        for(int i = 0 ;i <= num_1; i++) {
            if(num[i] != 0) {
                f = 0;
                break;
            }
        }
        if (f){
            cout<<0<<"\n";
            continue;
        }
        if( num[0] >= (num[1] + 1) / 2) num[0] --;
        else num[1] --;
        if(num[num_1] >= num[num_1 - 1] + 1) num[num_1] --;
        else num[num_1 - 1] --;
        for(int i = 1;i< num_1 - 1;i ++) {
            if(num[i] >num[i + 1])num[i] --;
            else if(num[i] < num[i + 1])num[i + 1] --;
            else if(num[i] == num[i + 1] && num[i] == 0)continue;
            else num[i]--;
        }
        int ans = 0;
        ans = max(num[0],num[num_1]);
        for(int i = 1 ;i<num_1 ;i ++) {
            ans = max(ans , (num[i] + 1) / 2);
        }
        cout<<ans + 1<<"\n";
    }

}