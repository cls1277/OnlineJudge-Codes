//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 25;
const LL mod = 1e9+7;
LL n, s, a[maxn], inv[maxn], ans;

void inv_init(LL n , LL mod) {
    inv[1] = 1;
    for(LL i=2; i<=n; i++)
        inv[i] = (mod-mod/i)%mod*inv[mod%i]%mod;
}

LL C(LL x, LL y) {
    if(x<0||y<0||x<y) return 0;
    if(x%mod==0||y==0) return 1;
    LL res = 1;
    Fo(i,x-y+1,x) res = (res*(i%mod))%mod;
    Fo(i,1,y) res = (res*(inv[i]%mod))%mod;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    inv_init(20, mod);
    cin>>n>>s;
    ans = C(n+s-1, n-1);
    Fo(i,1,n) cin>>a[i];
    LL len = (1LL<<n)-1;
    Fo(i,1,len) {
        LL cnt=0, x=n+s;
        Fo(j,0,n-1) {
            if(i&(1<<j)) {
                cnt ++;
                x -= a[j+1]; 
            }
        }
        x -= (cnt+1);
        LL p = (cnt&1)?(-1):1;
        ans = ((ans + p*C(x, n-1)%mod)%mod+mod)%mod;
    } 
    cout<<(ans%mod+mod)%mod;
    return 0;
}