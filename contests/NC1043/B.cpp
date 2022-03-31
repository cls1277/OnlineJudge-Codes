//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 110;
LL n, a[maxn], f[maxn][maxn][2];
char b[maxn];

LL op(LL c, LL d, char e) {
    if(e=='x') return c*d;
    return c+d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        cin>>b[i]>>a[i];
        a[i+n] = a[i];
        b[i+n] = b[i];
    }
    Fo(i,1,2*n)
        Fo(j,1,2*n) {
            f[i][j][1] = -INT_MAX;
            f[i][j][0] = INT_MAX;
        }
    Fo(len,1,n)
        Fo(l,1,2*n) {
            LL r = l+len-1;
            if(r>2*n) break;
            if(l==r) f[l][r][0] = f[l][r][1] = a[l];
            else {
                LL mn=INT_MAX, mx=-INT_MAX;
                Fo(k,l,r-1)    
                    Fo(x,0,1)
                        Fo(y,0,1) {
                            mn = min(mn, op(f[l][k][x], f[k+1][r][y], b[k+1]));
                            mx = max(mx, op(f[l][k][x], f[k+1][r][y], b[k+1]));
                        }
                f[l][r][1] = mx;
                f[l][r][0] = mn;
            }
        }
    LL ans = -INT_MAX;
    Fo(i,1,n) ans = max(ans, f[i][i+n-1][1]);
    cout<<ans<<endl;
    Fo(i,1,n)
        if(f[i][i+n-1][1]==ans)
            cout<<i<<" ";
    return 0;
}