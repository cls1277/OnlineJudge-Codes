//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 305;
LL n, sum[maxn], f[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Ms(f, 0x3f);
    Fo(i,1,n) {
        LL x; cin>>x;
        sum[i] = sum[i-1]+x;
        f[i][i] = 0;
    }
    Fo(len,2,n)
        Fo(l,1,n) {
            if(l+len-1>n) break;
            LL r = l+len-1;
            Fo(k,l,r) f[l][r] = min(f[l][r], f[l][k]+f[k+1][r]);
            f[l][r] += sum[r]-sum[l-1];
        }
    cout<<f[1][n];
    return 0;
}