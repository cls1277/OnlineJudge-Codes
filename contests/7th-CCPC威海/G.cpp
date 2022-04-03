//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5e4+5;
const LL mod = 998244353;
LL n, a[maxn], m;
unordered_map<LL, LL>cnt;

inline LL qpow(LL c, LL b) {
    LL res = 1;
    while(b) {
        if(b&1)
            res = res*c%mod;
        c = c*c%mod;
        b>>=1;
    }
    return res;
}

LL frac[maxn], invf[maxn], ans, inv[maxn];
vector<LL>c;

void inv2(LL mx , LL mod) {
    inv[1] = 1;
    for(LL i=2; i<=mx; i++)
        inv[i] = (mod-mod/i)%mod*inv[mod%i]%mod;
}

void inv3(LL mx , LL mod) {
    frac[0] = 1;
    for(LL i=1; i<=mx; i++)
        frac[i] = frac[i-1]*i%mod;
    invf[mx] = qpow(frac[mx],mod-2)%mod;
    for(LL i=mx-1; i>=0; i--)
        invf[i] = invf[i+1]*(i+1)%mod;
}

LL C(LL x, LL y) {
    return frac[x]*invf[y]%mod*invf[x-y]%mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    inv2(50000, mod);
    inv3(50000, mod);
    cin>>n>>m;
    LL mx = 0;
    Fo(i,1,n) {
        cin>>a[i];
        mx = max(mx, a[i]);
        if(!cnt[a[i]]) c.push_back(a[i]);
        cnt[a[i]]++;
    }
    Fo(i,1,mx-1) cout<<'0'<<endl;
    ans = 1;
    Fo(i,1,n) ans = ans*C(mx, a[i])%mod;
    cout<<ans<<endl;
    Fo(i,mx+1,m) {
        ans = ans*qpow(i, n)%mod;
        for(auto it:c) ans = ans*qpow(inv[i-it],cnt[it])%mod;
        cout<<ans<<endl;
    }
    return 0;
}