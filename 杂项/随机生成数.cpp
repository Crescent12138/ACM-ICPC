///here is jmr's codes
///if you want to copy,please call me 29856325137
///thanks
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<random>
using namespace std;
#define ll long long
double eps = 1e-6;
const int maxn = 1e5 + 5;
int n, m;
default_random_engine e(233);
uniform_int_distribution<unsigned long long  > u(1e9 + 7, 9e9 + 7);
int main() {
	ofstream readin, written;
	//srand(time(NULL));
	written.open("1.txt");
	m = 83;
	while (m--) {
		written << u(e) << "\n";
	}


}