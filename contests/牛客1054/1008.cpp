//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 205;
LL a[maxn], n, f[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        cin>>a[i];
        a[i+n] = a[i];
    }
    Fo(len,2,n) {
        Fo(l,1,2*n) {
            LL r = l+len-1;
            if(r>2*n) break;
            Fo(k,l,r-1) {
                f[l][r] = max(f[l][r], f[l][k]+f[k+1][r]+a[l]*a[k+1]*a[r+1]);
            }
        }
    }
    LL ans = 0;
    Fo(l,1,2*n) {
        LL r = l+n-1;
        if(r>2*n) break;
        ans = max(ans, f[l][r]);
    }
    cout<<ans;
    return 0;
}