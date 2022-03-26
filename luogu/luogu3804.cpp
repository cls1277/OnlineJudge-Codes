//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef int LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 1e6+5;
char s[maxn];//从1开始存，即cin>>(s+1)

struct SAM {
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
        long long ans = 0;
        Fo(i,1,tot) {
            if(sz[i]>1) {
                ans = max(ans, 1ll*sz[i]*maxlen[i]);
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=tot;i++) cnt[i]=sz[i]=0;
    }
}sam;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>(s+1);
    sam.build();
    return 0;
}