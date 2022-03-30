//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef int LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

// const LL maxn = ;
LL m, n, a[205][205], b[1005], f[1005][205][205];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>m>>n;
    Fo(i,1,m)
        Fo(j,1,m)
            cin>>a[i][j];
    Fo(i,1,n) cin>>b[i];
    LL p=3;
    Ms(f, 0x3f);
    f[0][1][2] = 0;
    Fo(i,1,n) {
        Fo(x,1,m)
            Fo(y,1,m) {
                if(x==y || y==p || x==p) continue;
                f[i][x][y] = min(f[i][x][y], f[i-1][x][y]+a[p][b[i]]);
                f[i][p][y] = min(f[i][p][y], f[i-1][x][y]+a[x][b[i]]);
                f[i][x][p] = min(f[i][x][p], f[i-1][x][y]+a[y][b[i]]);
            }
        p = b[i];
    }
    LL ans = INT_MAX;
    Fo(x,1,m)
        Fo(y,1,m) {
            if(x==p || y==p || x==y) continue;
            ans = min(ans, f[n][x][y]);
        }
    cout<<ans;
    return 0;
}