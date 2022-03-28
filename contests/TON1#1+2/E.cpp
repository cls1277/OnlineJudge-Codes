//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 1e5+5;
LL n;
vector<LL>e[maxn], d[maxn];
LL deep[maxn], sz[maxn], g, exi[maxn];

void dfs(LL u, LL f) {
    for(auto &v:e[u]) {
        if(v==f) continue;
        deep[v] = deep[u]+1;
        g = max(g, deep[v]);
        d[deep[v]].push_back(v);
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n;
        Fo(i,1,n) e[i].clear();
        Fo(i,1,n-1) {
            LL x, y; cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
        deep[1] = 1; g = 1;
        // sz[1] = 1;
        Fo(i,1,n) sz[i]=1;
        dfs(1, 0);
        // Fo(i,1,n) cout<<sz[i]<<" ";
        // cout<<endl;
        // Fo(i,1,n) cout<<deep[i]<<" ";
        Fo(i,1,g) {
            LL mx = 0;
            for(auto &it:d[i]) mx = max(mx, sz[it]);
            for(auto &it:d[i]) sz[it] = mx-sz[it]+1;
        }
        Fo(i,1,n) cout<<sz[i]<<" ";
        cout<<endl;
        Fo(i,1,g) d[i].clear();
        g = 0;
    }
    return 0;
}