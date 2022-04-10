//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 6005;
LL a[maxn], n, root, f[maxn][2];
bool exi[maxn];
vector<LL>e[maxn];

void dfs(LL u) {
    f[u][1] = a[u];
    for(auto &v:e[u]) {
        dfs(v);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) cin>>a[i];
    Fo(i,1,n-1) {
        LL x, y; cin>>x>>y;
        exi[x] = 1;
        e[y].push_back(x);
    }
    Fo(i,1,n)
        if(!exi[i]) {
            root = i;
            break;
        }
    dfs(root);
    cout<<max(f[root][1], f[root][0]);
    return 0;
}