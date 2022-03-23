//By cls1277
#include<unordered_map>
#include<cstring>
#include<queue>
#include<cmath>
using std::unordered_map;
using std::string;
using std::queue;
using std::max;
using std::min;

unordered_map<string, int>mp;

int hash(string s, int t) {
    mp[s] = t;
}

int gethash(string s) {
    return mp[s];
}

const int maxn = 1e3+5;
const char base = 'a';
int num = 0;
//不同题目的Trie内的成员不同
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

void nxt(string s, int t[]) {
    int p1=0, p2=-1;
    t[0] = -1;
    while(p1<s.length()) {
        if(p2==-1 || s[p1]==s[p1])
            t[++p1] = ++p2;
        else p2 = t[p2];
    }
}

void KMP(string s1, string s2) {
    int x[s2.length()+5], p1=0, p2=0;
    nxt(s2, x);
    while(p1<s1.length()) {
        if(p2==-1 || s1[p1]==s2[p2]) {
            p1++;
            p2++;
        } else p2 = x[p2];
        if(p2 == s2.length()) {
            //s2在s1中出现的位置是:p1-s2.length()+1
            p2 = x[p2];
        }
    }
}

int mpp[maxn];

void trie_insert(string s, int id) {
    int u = 0;
    for(int i=0; i<s.length(); i++) {
        int v = s[i]-base;
        if(!trie[u].son[v]) trie[u].son[v] = ++num;
        u = trie[u].son[v];
    }
    trie[u].end = id;
    mpp[id] = trie[u].end;
}

void aca_fail() {
    queue<int>q;
    for(int i=0; i<26; i++)
        if(trie[0].son[i]) {
            trie[trie[0].son[i]].fail = 0;
            q.push(trie[0].son[i]);
        }
    while(!q.empty()) {
        int u=q.front(); q.pop();
        for(int i=0; i<26; i++)
            if(trie[u].son[i]) {
                trie[trie[u].son[i]].fail = trie[trie[u].fail].son[i];
                q.push(trie[u].son[i]);
            } else trie[u].son[i] = trie[trie[u].fail].son[i];
    }
}

void aca_query(string s, int ans[]) {
    int u = 0;
    for(int i=0; i<s.length(); i++) {
        int v = s[i]-base;
        u = trie[u].son[v];
        for(int j=u; j; j=trie[j].fail)
            ans[mpp[trie[j].end]]++;
            //根据题意修改ans的更新方式
    }
}

void ACA(string s) {
    int ans[maxn];
    memset(ans, 0, sizeof(ans));
    memset(trie, 0, sizeof(trie));
    aca_fail();
    aca_query(s, ans);
    //根据题目要求输出答案，此处为输出ans[mpp[i]]
}

//建议改成char数组，length改成strlen
//所以f和s的长度 等于 2*str的长度
int manacher(string str) {
    int f[maxn<<1];
    memset(f, 0, sizeof(f));
    string s = str+str;
    s[0]='^', s[1]='$'; int j=2;
    for(int i=0; i<str.length(); i++) {
        s[j++] = str[i];
        s[j++] = '$';
    }
    s[j] = '&';
    int mid=1, maxx=1, ans=-1;
    for(int i=1; i<j; i++) {
        if(i<maxx) f[i] = min(maxx-i, f[mid*2-i]);
        else f[i] = 1;
        while(s[i-f[i]]==s[i+f[i]]) f[i]++;
        if(maxx<i+f[i]) {
            mid = i;
            maxx = i+f[i];
        }
        ans = max(ans, f[i]-1);
    }
    return ans;
    //最长回文串长度
}

//sa 和 sam 实在是不想写ovo