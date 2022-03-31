//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 305;
LL n, m, a[maxn], f[maxn][maxn];
vector<LL>e[maxn];

void dfs(LL u) {
    for(auto &v:e[u]) {
        dfs(v);
        Ro(i,m,0)
            Fo(j,0,i)
                f[u][i] = max(f[u][i], f[u][i-j]+f[v][j]);
    }
    if(u)
        Ro(i,m,1)
            f[u][i] = f[u][i-1]+a[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n) {
        LL x, y; cin>>x>>y;
        a[i] = y;
        e[x].push_back(i);
    }
    dfs(0);
    cout<<f[0][m];
    return 0;
}