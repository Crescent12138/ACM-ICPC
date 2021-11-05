#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
const int maxn = 3e5 + 10;
int n, m,cnt;
int d[maxn];
int head[maxn];
struct Edge {
	int to, w, nex;
}edge[maxn];
struct LA {
	int num, dis;
	bool operator <( const LA a )const {
		return this->dis > a.dis;
	}
};
void add ( int u, int v, int w ) {
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].nex = head[u];
	head[u] = cnt;
}
void read (int &ans) {
	int x = 0, f = 1;
	char c = getchar ();
	while ( c < '0' || c>'9' ) { if ( c == '-' ) f = -1; c = getchar (); }
	while ( c >= '0' && c <= '9' ) x = x * 10 + c - '0', c = getchar ();
	ans= x * f;
}
void write ( int x ) {
	if ( x < 0 ) putchar ( '-' ), x = -x;
	if ( x > 9 ) write ( x / 10 );
	putchar ( x % 10 + '0' );
}
int u, v, w;
LA now;

void dij () {
	priority_queue<LA> q;
	now.num = 1;
	now.dis = 0;
	q.push ( now );
	d[1] = 0;
	while ( !q.empty () ) {
		now = q.top (); q.pop ();
		if ( now.dis > d[now.num] )
			continue;
		for ( register int i = head[now.num]; i != 0; i = edge[i].nex ) {
			if ( d[edge[i].to] > d[now.num] + edge[i].w ) {
				d[edge[i].to] = d[now.num] + edge[i].w;
				LA pp = { edge[i].to,d[edge[i].to] };
				q.push ( pp );
			}
		}
	}

}
void solve ()
{
	read ( n ); read ( m );
	for ( int i = 1; i <= m; i++ ) {
		read ( u ), read ( v ), read ( w );
		add ( u, v, w );
	}
	memset ( d, 0x3f, sizeof d );
	dij ();
	write ( d[n] );
	printf ( "\n" );
}
int main ()
{
	solve ();
}
