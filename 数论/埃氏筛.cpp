#include <iostream>
#include <cstring>
#define maxn 1000005
using namespace std;

int a[maxn];//存放素数的数组a
int b[maxn];//数字对应表

main()
{
    int n;
    while( cin >> n )//输入查找上限
    {
        memset( a, 0 ,sizeof(a) );
        memset( b, 1 ,sizeof(b) );//下标对应数字为素数则为1，否则为0，全部初始化为1
        int t = 0;//记录素数个数的变量
        b[0] = 0; b[1] = 0;// 0、1不是素数
        for( int i(0); i <= n; i++ )// 遍历不大于n的所有数
        {
            if ( b[i] )//如果这个数为素数
            {
                a[t++] = i;
                for( int j = 2*i; j <= n; j += i )// 此时i为找到的一个素数，所有 i的倍数都不是素数
                    b[j] = 0;
            }
        }
        //for( int i(0); i < t; i++ )
        //    cout << a[i] <<"\t";
        //cout << endl << "小于" << n << "的数中，共有" << t << "个素数" <<endl;
    }
}