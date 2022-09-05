//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1030;
bitset<maxn> f[maxn], g[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n, m; cin>>n>>m;
        Fo(i,0,1023) f[i].reset();
        f[0][0] = 1;
        Fo(i,1,n) {
            LL x, y; cin>>x>>y;
            Fo(j,0,1023) g[j]=f[j]<<x;
            Fo(j,0,1023) f[j]|=g[j^y];
        }
        LL ans = -1;
        Ro(i,1023,0) {
            if(f[i][m]) {
                ans = i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}