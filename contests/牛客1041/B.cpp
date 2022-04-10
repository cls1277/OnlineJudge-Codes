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

const LL maxn = 3e3+5;
LL n, a[maxn], b[maxn], f[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) cin>>a[i];
    Fo(i,1,n) cin>>b[i];
    Fo(i,1,n) {
        LL mx = 0;
        if(b[0]<a[i]) mx = f[i-1][0];
        Fo(j,1,n) {
            if(a[i]==b[j]) f[i][j] = mx+1;
            else f[i][j] = f[i-1][j];
            if(b[j]<a[i]) mx = max(mx, f[i-1][j]);
        }
    }
    LL ans=0;
    Fo(i,1,n) ans = max(ans, f[n][i]);
    cout<<ans;
    return 0;
}