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

const LL maxn = 2e3+5;
LL n, a[maxn], p[maxn], fa[maxn];
vector<LL>e[maxn];
pair<LL, LL>b[maxn];

void dfs(LL u) {
    p[u] = a[u];
    for(auto &v:e[u]) {
        dfs(v);
        p[u]+=a[v];
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
        LL res = 0;
        cin>>n;
        Fo(i,1,n) e[i].clear();
        Fo(i,2,n) {
            LL x; cin>>x;
            e[x].push_back(i);
            fa[i] = x;
        }
        Fo(i,1,n) cin>>a[i];
        Fo(i,0,n) {
            res = 0;
            Ms(p,0);
            dfs(1);
            LL idx = 0;
            Fo(j,1,n) {
                if(!a[j]) continue;
                res += p[j];
                if(a[fa[j]]) b[++idx] = {p[j]+a[j], j};
                else b[++idx] = {p[j], j};
            }
            sort(b+1, b+idx+1);
            cout<<res<<" ";
            a[b[idx].second] = 0;
        }
        cout<<endl;
    }
    return 0;
}