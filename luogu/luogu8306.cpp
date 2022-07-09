//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e3+5;
int n, q, num;

const char base = 'a';

struct Trie {
    int son[26], fail, cnt, end;
    Trie() {
        memset(son, 0, sizeof(son));
        cnt = end = 0;
    }
}trie[maxn];

void trie_insert(string s) {
    int u = 0;
    for(int i=0; i<s.length(); i++) {
        int v = s[i]-base;
        if(!trie[u].son[v]) trie[u].son[v] = ++num;
        u = trie[u].son[v];
        trie[u].cnt++;
    }
    trie[u].end++;
}

//ans的更新和返回部分，需要根据题目自己写
int trie_find(string s) {
    int ans=0, u=0;
    for(int i=0; i<s.length(); i++) {
        int v = s[i]-base;
        if(!trie[u].son[v])  return ans;
        u = trie[u].son[v];
        //ans += trie[u].end;
    }
    // return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    int T; cin>>T;
    while(T--) {
        cin>>n>>q;
        Fo(i,1,n) {
            string str; cin>>str;
            trie_insert(str);
        }
        Fo(i,1,q) {
            
        }
    }
    return 0;
}