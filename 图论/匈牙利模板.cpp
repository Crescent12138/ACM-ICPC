const int N = 10001;
vector<int> G[105];
int pre[105];
bool used[105];

//匈牙利算法
bool dfs(int k)
{
    for (int i = 0; i < G[k].size(); ++i)
    {
        if (used[G[k][i]] == 0)
        {
            used[G[k][i]] = 1;
            if (pre[G[k][i]] == 0 || dfs(pre[G[k][i]]))
            {
                pre[G[k][i]] = k;
                return true;
            }
        }
        else
            continue;
    }
    return false;
}

void solve() {
    //匹配规则
    memset(pre, 0, sizeof(pre));
    int count = 0;
    for (int i = 1; i <= N; ++i)
    {
        memset(used, 0, sizeof(used));
        if (dfs(i))
            count++;
    }
}