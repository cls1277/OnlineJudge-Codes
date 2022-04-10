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
const LL mod = 1e9;
char s[maxn];LL n, f[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>(s+1); n=strlen(s+1);
    Fo(i,1,n) f[i][i] = 1;
    Fo(len,1,n)
        Fo(l,1,n) {
            LL r = l+len;
            if(r>n) break;
            if(s[l]!=s[r]) f[l][r] = 0;
            else {
                Fo(k,l,r)
                    if(s[l]==s[k]&&l+1<=n&&k-1>=1)
                        f[l][r] = (f[l][r] + f[l+1][k-1]*f[k][r]%mod)%mod;
            }
        }
    cout<<f[1][n];
    return 0;
}