#include<bits/stdc++.h>
using namespace std;
struct node{
    int cnt=0;
    bool vis[28*1000]={};
    //第一个数字表示字符串长度，第二个表示个数，第三个表示字符种类
    int trie[28*1000][28];
   void insert(string s){
       int p=0;//索引记号    
       for(auto i:s){
            if(!trie[p][s[i]-'a']){//表示这个点从来没出现过，给他附加上新索引，代表他曾经来过
                trie[p][s[i]-'a']=++cnt;//cnt只跟插入先后有关，并没有实际表达意义，可以理解为一个索引记号
            }
            p=trie[p][s[i]-'a'];//跳转到下一个索引位置呗，跳的到就行了
       }
       vis[p]=1;//访问标记，告诉自己这个索引位置是有值的，比如说cat，索引标记是1->2->3，3标记
   }
   bool search(string s){
       int p=0;
       for(auto i:s){
            if(!trie[p][s[i]-'a']) return 0;   //没有索引记号的原因就是这个地方没有来过，那么就可以直接封杀了     
             p=trie[p][s[i]-'a'];//跳转到下一个索引位置呗，跳的到就行了
       }
       return vis[p];//因为最后一个我们是利用检查值的，比如说存进去cate，但是我们查的是cat，他有跳转值，但是在检查值那里并没有cat这个情况。
   }
};


