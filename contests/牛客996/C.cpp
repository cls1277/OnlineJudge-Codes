//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = ;

LL mul(LL a, LL b, LL p) {
    LL ans = 0;
    while(b) {
        if(b&1) ans = (ans+a)%p;
        a = a*2%p;
        b>>=1;
    }
    return ans;
}

inline ULL qmul(ULL a, ULL b, const ULL mod){
    LL c=(LL)(a)*b-(LL)((ULL)((LD)(a)*b/mod)*mod);
    return c<0? c+mod:(c<mod? c:c-mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL x, y, z; cin>>x>>y>>z;
    cout<<qmul(x, y, z);
    return 0;
}