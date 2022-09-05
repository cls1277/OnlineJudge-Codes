//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL n, m, ans=INT_MAX; cin>>n>>m;
    vector<vector<LL>> f(2, vector<LL>(m+1, -INT_MAX));
    Fo(i,1,n) {
        LL l; cin>>l;
	    f[(i-1)&1][1] = i;
	    Fo(j,1,m) f[i&1][j] = f[(i-1)&1][j];
//      f[i&1][1] = i;
//      Fo(j,2,m) f[i&1][j] = f[(i-1)&1][j];
        Fo(j,1,l) {
            LL x, y; cin>>x>>y;
            f[i&1][y] = max(f[i&1][y], f[(i-1)&1][x]);
            if(y==m&&f[i&1][m]!=-INT_MAX) ans = min(ans, i-f[i&1][m]+1);
        }
    }
    cout<<(ans==INT_MAX?-1:ans);
    return 0;
}
