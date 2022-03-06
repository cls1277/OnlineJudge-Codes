//By cls1277
#ifdef ONLINE_JUDGE
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
#define mk(_,__) make_pair(_,__)
#define pii pair<LL,LL>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

const LL maxn = 1e4+5;

struct Edge {
    LL to, next;
}e[maxn*maxn];

LL n, m, tot, head[maxn], cnt, is[maxn];

void add(LL x, LL y) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    head[x] = tot;
    return ;
}

LL dfn[maxn], low[maxn], idx;
vector<pii>a;

void tarjan(LL u, LL f) {
    low[u] = dfn[u] = ++idx;
    Eo(i,u,e) {
        LL v=e[i].to;
        if(v==f) continue;
        if(!dfn[v]) {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]) {
                a.push_back(mk(min(u,v),max(u,v)));
            }
        }
        low[u]=min(low[u],dfn[v]);
    }
    return ;
}

int main() {
    // ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(scanf("%lld",&n)!=EOF) {
        Ms(dfn,0); Ms(low,0); idx=0; cnt=0; Ms(head,0); tot=0; Ms(is,0);
        a.clear();
        LL x, y, z;
        Fo(i,1,n) {
            scanf("%lld (%lld)",&x,&y);
            Fo(j,1,y) {
                scanf("%lld",&z);
                add(x,z);
                add(z,x);
            }
        }
        Fo(i,0,n-1)
            if(!dfn[i])
                tarjan(i,i);
        printf("%d critical links\n",a.size());
        sort(a.begin(),a.end());
        for(LL i=0; i<a.size(); i++)
            printf("%lld - %lld\n",a[i].first,a[i].second);
        printf("\n");
    }
    return 0;
}