//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2e5+5;
LL f[maxn], sum[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL n; cin>>n;
    LL ans = -INT_MAX;
    Fo(i,1,n) {
        LL x; cin>>x;
        sum[i] = max(sum[i-1]+x, x);
        ans = max(ans, sum[i]);
    }
    cout<<ans;
    // Fo(i,1,n) {
    //     f[i] = -INT_MAX;
    //     LL x; cin>>x;
    //     sum[i] = sum[i-1]+x;
    // }
    // LL ans = -INT_MAX;
    // Fo(len,1,n)
    //     Fo(l,1,n) { 
    //         LL r = l+len-1;
    //         if(r>n) break;
    //         f[len] = max(f[len], sum[r]-sum[l-1]);
    //         ans = max(f[len], ans);
    //     }
    // cout<<ans;
    return 0;
}