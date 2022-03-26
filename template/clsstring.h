//By cls1277
#include<iostream>
#include<unordered_map>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>

using std::cin;
using std::unordered_map;
using std::string;
using std::queue;
using std::max;
using std::min;
using std::vector;

typedef long long LL;

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

char s[maxn];//从1开始存，即cin>>(s+1)

/*

解题可能用到的变量的含义：

right：一个结点代表的字符串集合中最长的字符串在原字符串哪里出现过
maxlen：每个结点代表的字符串集合中最长的字符串的长度
np：实际插入的点
nq：虚空的点（调整后加入的点）
fa：fail数组
ch：字典树
sz：right集合的大小，也就是这个结点代表的字符串出现的次数
tot：点的个数，包括虚点和实点

*/

struct SAM {
    //开的数组比较多，适度开long long，容易MLE，一般int就够了
    int ch[maxn<<1][26], fa[maxn<<1], maxlen[maxn<<1], sz[maxn<<1], k[maxn<<1], cnt[maxn<<1];
    vector<int>right[maxn<<1];
    int last, tot;
    void init() {
        last = tot = 1;
        memset(ch[1], 0, sizeof(ch[1]));
    }
    void insert(int c, int pos) {
        int p=last, np=++tot;
        last=np; maxlen[np]=maxlen[p]+1;
        memset(ch[tot], 0, sizeof(ch[tot]));
        for(;p&&!ch[p][c]; p=fa[p]) ch[p][c]=np;
        if(!p) fa[np]=1;
        else {
            int q=ch[p][c];
            if(maxlen[p]+1==maxlen[q]) fa[np]=q;
            else {
                int nq=++tot; maxlen[nq]=maxlen[p]+1;
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                fa[nq] = fa[q]; fa[q] = fa[np] = nq;
                for(; ch[p][c]==q; p=fa[p]) ch[p][c]=nq;
                //更新nq信息
            }
        }
        //更新np
        sz[np] = 1;
        right[np].push_back(pos);
    }
    void build() {
        init();
        int n=strlen(s+1);
        for(int i=1; i<=n; i++) insert(s[i]-'a',i);

        for(int i=1; i<=tot; i++) cnt[maxlen[i]]++;
        for(int i=1; i<=tot; i++) cnt[i]+=cnt[i-1];
        for(int i=1; i<=tot; i++) k[cnt[maxlen[i]]--]=i;

        for(int i=tot; i>=1; i--) {
            int id = k[i];
            sz[fa[id]] += sz[id];
            for(auto &j:right[id]) right[fa[id]].push_back(j);
        }

        //在这里求答案

        for(int i=1;i<=tot;i++) cnt[i]=sz[i]=0;
    }
}sam;

/*

SA 后缀数组

数组含义解释：

height：后缀排序后，第i个字符串和第i-1个字符串公共前缀的长度
rak：rank数组，以第i个字符为后缀开始的字符串 在后缀排序后排第几？
sa：排名第i的数组 是以第几个字符串为后缀开始的？

*/

int wa[maxn], wb[maxn], wv[maxn], wss[maxn], rak[maxn], height[maxn], cal[maxn], n, sa[maxn];

int cmp(int *r, int a, int b, int l) {
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int *r, int *sa, int n, int M) {
    int i, j, p, *x=wa, *y=wb, *t;
    for(i=0; i<M; i++) wss[i]=0; 
    for(i=0; i<n; i++) wss[x[i]=r[i]]++; 
    for(i=1; i<M; i++) wss[i]+=wss[i-1]; 
    for(i=n-1; i>=0; i--) sa[--wss[x[i]]]=i; 
    for(j=1, p=1; p<n; j*=2, M=p) {
        for(p=0, i=n-j; i<n; i++) y[p++]=i; 
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j; 
        for(i=0; i<n; i++) wv[i]=x[y[i]]; 
        for(i=0; i<M; i++) wss[i]=0; 
        for(i=0; i<n; i++) wss[wv[i]]++; 
        for(i=1; i<M; i++) wss[i]+=wss[i-1]; 
        for(i=n-1; i>=0; i--) sa[--wss[wv[i]]]=y[i]; 
        for(t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i<n; i++) x[sa[i]]=cmp(y, sa[i-1], sa[i], j)?p-1:p++; 
    }
}
void calheight(int *r, int *sa, int n) {
     int i, j, k=0; 
     for(i=1; i<=n; i++) rak[sa[i]]=i; 
     for(i=0; i<n; height[rak[i++]]=k)
     for(k?k--:0, j=sa[rak[i]-1]; r[i+k]==r[j+k]; k++); 
     for(int i=n; i; i--) rak[i]=rak[i-1], sa[i]++; 
}

void da_init() {
    while(cin>>(s+1)) {
        n=strlen(s+1); 
        for(int i=1; i<=n; i++) cal[i]=s[i]; //第i位置的字符大小，不能是0
        cal[n+1]=0;  //n+1处位置一定等于0
        da(cal+1, sa, n+1, 200); //200是字符集大小
        calheight(cal+1, sa, n); // sa height rank 都是1-n的
        //到这里height sa rak数组都计算出来了
    }
}

/*

这里的maxn是平时的maxn的3倍，用N代替
下面的define是为了防止和上面da算法中数组重名

*/

#define wa _wa
#define ws _ws
#define wb _wb
#define wv _wv
#define sa _sa
#define rak _rak
#define height _height
#define cal _cal
#define n _n
#define calheight _calheight

#define F(x) ((x) / 3 + ((x) % 3 == 1 ? 0 : tb))
#define G(x) ((x) < tb ? (x) * 3 + 1 : ((x) - tb) * 3 + 2)
const int N = 3*(1e6+5);
int wa[N], wb[N], ws[N], wv[N], sa[N];
int rak[N], height[N], cal[N], n;

int c0(int *r, int a, int b) {
    return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}

int c12(int k, int *r, int a, int b) {
    if (k == 2) return r[a] < r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
    return r[a] < r[b] || r[a] == r[b] && wv[a + 1] < wv[b + 1];
}

void Rsort(int *r, int *a, int *b, int n, int m) {
    for(int i = 0; i < n; i++) wv[i] = r[a[i]];
    for(int i = 0; i < m; i++) ws[i] = 0;
    for(int i = 0; i < n; i++) ws[wv[i]]++;
    for(int i = 1; i < m; i++) ws[i] += ws[i - 1];
    for(int i = n - 1; i >= 0; i--) b[--ws[wv[i]]] = a[i];
}

void dc3(int *r, int *sa, int n, int m) {
    int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
    r[n] = r[n + 1] = 0;
    for(i = 0; i < n; i++) if (i % 3 != 0) wa[tbc++] = i;
    Rsort(r + 2, wa, wb, tbc, m);
    Rsort(r + 1, wb, wa, tbc, m);
    Rsort(r, wa, wb, tbc, m);
    for(p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
        rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
    if (p < tbc) dc3(rn, san, tbc, p);
    else for(i = 0; i < tbc; i++) san[rn[i]] = i;
    for(i = 0; i < tbc; i++) if (san[i] < tb) wb[ta++] = san[i] * 3;
    if (n % 3 == 1) wb[ta++] = n - 1;
    Rsort(r, wb, wa, ta, m);
    for(i = 0; i < tbc; i++) wv[wb[i] = G(san[i])] = i;
    for(i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for(; i < ta; p++) sa[p] = wa[i++];
    for(; j < tbc; p++) sa[p] = wb[j++];
    //for(int i=n;i;i--) rak[i]=rak[i-1];
    //for(int i=n;i;i--) sa[i]++;
}

void calheight(int *r, int *sa, int n) {
    int i, j, k = 0;
    for(i = 1; i <= n; i++) rak[sa[i]] = i;
    for(i = 0; i < n; height[rak[i++]] = k)
        for(k ? k-- : 0, j = sa[rak[i] - 1]; r[i + k] == r[j + k]; k++);
    for(int i=n;i;i--) rak[i]=rak[i-1];
    for(int i=n;i;i--) sa[i]++;
}

void dc3_init() {
    while (cin>>(s+1)) {
        n=strlen(s+1);
        for(int i=1; i<=n; i++) cal[i]=s[i]; //第i位置的字符大小，不能是0
        cal[n+1]=0;  //n+1处位置一定等于0
        da(cal+1, sa, n+1, 200); //200是字符集大小
        calheight(cal+1, sa, n); // sa height rank 都是1-n的
        //到这里height sa rak数组都计算出来了
    }
}