//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define INF 2147483647
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 205;
LL n, sum[maxn], f[maxn][maxn], a[maxn], ans1, ans2, g[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        cin>>a[i];
        a[i+n] =a[i];
    }
    n<<=1;
    Fo(i,1,n) sum[i]=sum[i-1]+a[i];
    for(LL len=1; len<=n; len++)
        for(LL i=1; i+len<=n; i++) {
            LL j=len+i; g[i][j]=INF;
            for(LL k=i; k<j; k++) {
                f[i][j] = max(f[i][j], f[i][k]+f[k+1][j]+sum[j]-sum[i-1]);
                g[i][j] = min(g[i][j], g[i][k]+g[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    n>>=1; ans2=INF;
    Fo(i,1,n) {
        ans1 = max(ans1, f[i][i+n-1]);
        ans2 = min(ans2, g[i][i+n-1]);
    }
    cout<<ans2<<endl<<ans1;
    return 0;
}