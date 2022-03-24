//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define INF 2147483647
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

// const LL maxn = ;
const LL mod = 1e9+7;
LL n;

LL getphi(LL x) {
    LL temp = x;
    for(int i=2; i<=sqrt(x); i++) {
        if(x%i) continue;
        temp = temp-temp/i;
        while(x%i==0) x/=i;
    }
    if(x!=1) temp=temp-temp/x;
    return temp%mod;
}

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

//旋转染色polya
LL polya_rotate() {
    LL res = 0;
    for(LL i=1; i<=sqrt(n); i++) {
        if(n%i) continue;
        res = (res+qpow(n, i, mod)*getphi(n/i)%mod)%mod;
        if(i*i!=n) res=(res+qpow(n, n/i, mod)*getphi(i)%mod)%mod;
    }
    return res*qpow(n, mod-2, mod)%mod;
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
        cout<<polya_rotate()<<endl;
    }
    return 0;
}