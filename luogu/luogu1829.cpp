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

const LL maxn = 1e7+5;
const LL mod = 20101009;
LL n, m;
bool vis[maxn]; LL cnt=0, pri[maxn], mu[maxn];

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

void getmu(LL maxx, LL mu[]) {
    memset(vis, 0, sizeof(vis));
    mu[1] = 1;
    for(LL i=2; i<=maxx; i++) {
        if(!vis[i]) {
            mu[i] = -1;
            pri[cnt++] = i;
        }
        for(LL j=0; j<cnt; j++) {
            if(i*pri[j]>maxx) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j])
                mu[i*pri[j]] = -mu[i];             
            else {
                mu[i*pri[j]] = 0;
                break;
            }
        }
    }
}

LL f(LL x, LL y) {
    return x*(x+1)%mod*y%mod*(y+1)%mod*qpow(4, mod-2, mod)%mod;
}

LL sum(LL x, LL y) {
    LL res = 0;
    for(LL i=1,j; i<=min(x, y); i=j+1) {
        j = min(x/(x/i), y/(y/i));
        res = (res+(mu[j]-mu[i-1]+mod)%mod*f(x/i, y/i)%mod)%mod;
    }
    return res;
}

LL sol(LL x, LL y) {
    LL res = 0;
    for(LL i=1,j; i<=min(x, y); i=j+1) {
        j = min(x/(x/i), y/(y/i));
        res = (res+sum(x/i, y/i)*(j-i+1)%mod*(i+j)%mod*qpow(2, mod-2, mod)%mod)%mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    if(n>m) swap(n, m);
    getmu(m, mu);
    Fo(i,1,m) mu[i]=(mu[i-1]+mu[i]*i%mod*i%mod)%mod;
    cout<<sol(n, m);
    return 0;
}