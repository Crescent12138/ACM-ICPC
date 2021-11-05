#define maxn 1001
#define M 5015
int next1[maxn];
//char str[maxn], mo[maxn];
int ans;
int n, m;
void getnext(char *mo,int len)//mo表示子串,len是mo的长度
{
    next1[0]=-1;
    int i = 0, j = -1;
    while (i < len) {
        if (j == -1 || mo[i] == mo[j])
            next1[++i] = ++j;
        else
            j = next1[j];
    }
}
int kmp(char *str,char *mo,int len1,int len2)//形参str表示母串，mo表示子串,len1是母串长度，len2是子串长度
{
    int i = 0, j = 0;
    while (i < len1) {
        if (j == -1 || str[i] == mo[j])
            i++, j++;
        else
            j = next1[j];
        if (j == len2)
            return i - len2 + 1;
    }
    return -1;
}
void getnext(string s)
{
    nxt[0]=-1;
    int i = 0, j = -1;
    while (i < s.size()) {
        if (j == -1 || s[i] == s[j])
            nxt[++i] = ++j;
        else
            j = nxt[j];
    }
}
