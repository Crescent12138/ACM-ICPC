
vector<int> mul(vector<int> a, int x){
    vector<int> res;
    int t = 0;
    for (int i = 0; i < a.size(); ++i) {
        t += x * a[i];
        res.push_back(t % 10);
        t /= 10;
    }
    while (t){
        res.push_back(t % 10);
        t /= 10;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

vector<int> add(vector<int> a, vector<int> b){
    vector<int> res;
    int t = 0;
    for (int i = 0; i < max(a.size(), b.size()); ++i) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        res.push_back(t % 10);
        t /= 10;
    }
    while (t){
        res.push_back(t % 10);
        t /= 10;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

vector<int> vmul(vector<int> a, vector<int> b){
    vector<int> res;

    for (int i = 0; i < b.size(); ++i) {
        res = add(res, mul(a, b[i]));
        a.insert(a.begin(), 0);
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

vector<int> div(vector<int> &a,int b,int &r)//除法 &r用来返回
{
    r=0;
    vector<int> c;
    for(int i=a.size();i>=0;i--)
    {
        r=r*10+a[i];
        c.push_back(r/b);//当前位的
        r%=b;//余数
    }
    
    reverse(c.begin(),c.end());
    //因此与实际商顺序相反，所以翻转数
    
    while(c.size()>1&&c.back()==0)c.pop_back();//清除可能存在的前导零
    
    return c;
}
vector<int> get(){
    string s; cin >> s;
    int len = s.length();
    vector<int> res(len);
    for (int i = 0; i < len; ++i) {
        res[i] = s[len - i - 1] - '0';
    }
    return res;
}
