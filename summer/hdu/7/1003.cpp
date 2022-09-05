//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5e5+5;
const LL mod = 998244353;
LL n;

struct Edge {
    LL to, next;
}e[maxn<<1];
LL tot, head[maxn], sz[maxn], g[maxn];

void add(LL x, LL y) {
    tot++;
    e[tot] = {y, head[x]};
    head[x] = tot;
}

void dfs(LL x, LL f) {
    Eo(i,x,e) {
        LL v = e[i].to;
        if(v==f) continue;
        sz[x]++;
        dfs(v, x);
    }
}

LL frac[maxn], inv[maxn];

inline LL qpow(LL a, LL b, LL mod) {
    LL res = 1;
    while(b) {
        if(b&1)
            res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}

LL C(LL x, LL y) {
    if(x<y) return 0;
    return frac[x]*inv[y]%mod*inv[x-y]%mod;
}

void dfs1(LL x, LL f) {
    // if(sz[x]<3) return ;
    unordered_map<LL, LL> a;
    LL mx = 1, cnt = 0;
    Eo(i,x,e) {
        LL v = e[i].to;
        if(v==f) continue;
        a[sz[v]]++;
        if(sz[v]) cnt++;
        mx = max(mx, sz[v]);
        dfs1(v, x);
    }
    if(a[1]<2||mx==1) return ;
    for(auto it:a) {
        if(it.first>1) {
            g[x] = (g[x]+C(it.first, 2)*C(cnt-1, 2)%mod*it.second%mod)%mod;
        }
    }
}

LL ans;

void dfs2(LL x, LL f) {
    Eo(i,x,e) {
        LL v = e[i].to;
        if(v==f) continue;
        ans = (ans+g[v])%mod;
        dfs2(v, x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n;
        tot = ans = 0;
        Fo(i,1,n) {
            head[i] = 0;
            sz[i] = 0;
            g[i] = 0;
        }
        frac[0] = 1;
        for(LL i=1; i<=n; i++)
            frac[i] = frac[i-1]*i%mod;
        inv[n] = qpow(frac[n],mod-2,mod);
        for(LL i=n-1; i>=0; i--)
            inv[i] = inv[i+1]*(i+1)%mod;
        Fo(i,1,n-1) {
            LL x, y; cin>>x>>y;
            add(x, y);
            add(y, x);
        }
        dfs(1, 0);
        Fo(i,1,n) cout<<sz[i]<<' ';
        dfs1(1, 0);
        cout<<endl;
        Fo(i,1,n) cout<<g[i]<<' ';
        dfs2(1, 0);
        cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}