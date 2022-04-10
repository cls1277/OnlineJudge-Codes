//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 3831;
LL n, m, a[maxn], f[2][maxn][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n) cin>>a[i];
    Ms(f, -0x3f);
    f[1][0][0] = f[1][1][1] = 0;
    Fo(i,2,n) {
        LL x = i&1, y = x^1;
        Fo(j,0,min(i,m)) {
            f[x][j][0] = max(f[y][j][0], f[y][j][1]);
            if(j-1<0) continue;
            f[x][j][1] = max(f[y][j-1][0], f[y][j-1][1]+a[i]);
        }
    }
    LL ans = max(f[n&1][m][0], f[n&1][m][1]);
    Ms(f, -0x3f);
    f[1][1][1] = a[1];
    Fo(i,2,n) {
        LL x = i&1, y = x^1;
        Fo(j,0,min(i,m)) {
            f[x][j][0] = max(f[y][j][0], f[y][j][1]);
            if(j-1<0) continue;
            f[x][j][1] = max(f[y][j-1][0], f[y][j-1][1]+a[i]);
        }
    }
    ans = max(ans, f[n&1][m][1]);
    cout<<ans;
    return 0;
}