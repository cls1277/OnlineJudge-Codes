//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 2e3+5;
LL n, a[maxn], f[maxn][maxn];
LL l[maxn], cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        cin>>a[i];
        l[i] = a[i];
    }
    sort(l+1, l+n+1);
    Fo(i,1,n) {
        LL mn = INT_MAX;
        Fo(j,1,n) {
            mn = min(mn, f[i-1][j]);
            f[i][j] = mn+abs(a[i]-l[j]);
        }
    }
    LL ans=INT_MAX;
    Fo(i,1,n) ans=min(ans, f[n][i]);
    cout<<ans<<endl;
    return 0;
}