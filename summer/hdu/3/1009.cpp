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
LL n, k;
struct Node {
    LL l, r;
};
Node a[maxn];
bool vis[maxn];

bool operator < (const Node &x, const Node &y) {
    if(x.r!=y.r) return x.r<y.r;
    return x.l<y.l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n>>k;
        LL ans = 0; Ms(vis, 0);
        Fo(i,1,n) cin>>a[i].l>>a[i].r;
        sort(a+1, a+n+1);
        Fo(i,1,n) {
            if(vis[i]) continue;
            LL j = i+1, c = 1;
            vis[i] = 1;
            while(j<=n&&c<k) {
                if(a[j].l<=a[i].r&&!vis[j]) {
                    vis[j] = 1;
                    c++;
                }
                j++;
            }
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
