#include<bits/stdc++.h>
using namespace std;
struct trie {
	int nex[100005][26], cnt;
	bool exist[100000];
	//s是字符串，l是s的长度
	void insert(char* s, int l) {
		int p = 0;
		for (int i = 0; i < l; i++) {
			int c = s[i] - 'a';
			if (!nex[p][c])nex[p][c] = ++cnt;
			p = nex[p][c];
		}
		//代表他是否出现过
		exist[p] = 1;

	}
	bool find(char* s, int l) {
		int p = 0;
		for (int i = 0; i < l; i++) {
			int c = s[i] - 'a';
			if (!nex[p][c])return 0;
			p = nex[p][c];
		}
		return exist[p];
	}
};
int main(){}