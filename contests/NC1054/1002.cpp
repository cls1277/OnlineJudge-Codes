//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 105;
LL n, m, f[maxn][maxn], a[maxn][maxn], b[maxn];
pair<LL, LL>pre[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n)
        Fo(j,1,m) {
            cin>>a[i][j];
            f[i][j] = -INT_MAX;
        }
    // Ms(f, -0x3f);
    // Fo(i,1,m) f[0][i] = 0;
    Fo(i,1,n) {
        Fo(j,i,m-(n-i)) {
            Fo(k,i-1,j-1) {
                if(f[i-1][k]+a[i][j]>f[i][j]) {
                    f[i][j] = f[i-1][k]+a[i][j];
                    pre[i][j] = {i-1, k};
                }
            }
        }
    }
    LL ans = -INT_MAX, idx = 0;
    Fo(i,1,m) {
        if(f[n][i]>ans) {
            ans = f[n][i];
            idx = i;
        }
    }
    cout<<ans<<endl;
    LL s=n, t=idx;
    while(s) {
        LL temp = s;
        b[s] = t;
        s = pre[s][t].first;
        t = pre[temp][t].second;
    }
    Fo(i,1,n) cout<<b[i]<<' ';
    return 0;
}