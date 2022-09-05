//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e5+5;
const LL maxm = 2e5+5;
LL n, m, ans, fa[maxn];
pair<LL, LL> ed[maxm];
bool vis[maxm];

LL find(LL x) {
    while(x!=fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; scanf("%lld",&t); //cin>>t;
    while(t--) {
        ans = 0;
        unordered_map<LL, LL> mp;
        scanf("%lld%lld",&n,&m); //cin>>n>>m;
        Fo(i,1,n) fa[i] = i;
        Fo(i,1,m) vis[i] = 0;
        Fo(i,1,m) {
            LL x, y; scanf("%lld%lld", &x,&y); //cin>>x>>y;
            LL h = x*1e5+y;
            if(mp[h]||x==y) {
                if(mp[h]) vis[mp[h]] = 1;
                else vis[i] = 1;
            } else mp[h] = i;
            ed[i] = {x, y};
        }
        Ro(i,m,1) {
            LL f1=find(ed[i].first), f2=find(ed[i].second);
            if(f1!=f2) fa[f1] = f2;
            else vis[i] = 1;
        }
        Fo(i,1,m) {
            if(vis[i]) ans++;
        }
        // cout<<ans<<endl;
        printf("%lld\n",ans);
        Fo(i,1,m) {
            if(vis[i]) {
                // cout<<i<<' ';
                printf("%lld ",i);
            }
        }
        // cout<<endl;
        printf("\n");
    }
    return 0;
}
