//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//const LL maxn = ;
// LL f[100005][35];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n, m; cin>>n>>m;
        vector<LL> a(n+5);
        Fo(i,1,n) cin>>a[i];
        vector<vector<LL>> f(n+5, vector<LL>(35, -1e18));// long long 用INT_MAX不行
        // Fo(i,0,n)
        //     Fo(j,0,30)
        //         f[i][j] = -1e18;
        f[0][0] = 0;
        LL ans = 0;
        Fo(i,1,n) {
            Fo(j,0,30) {
                if(!j) f[i][j] = max(f[i][j], f[i-1][j]+a[i]-m);
                else f[i][j] = max(f[i-1][j]+(a[i]>>j)-m, f[i-1][j-1]+(a[i]>>j));
                ans = max(ans, f[i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
