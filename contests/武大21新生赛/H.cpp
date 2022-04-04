//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = ;

inline LL qpow(LL a, LL b) {
    LL res = 1;
    while(b) {
        if(b&1)
            res = res*a;
        a = a*a;
        b>>=1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL n; cin>>n;
    LL ans, k=n/3, m=n%3;
    ans = qpow(k+1, m)*qpow(k, 3-m);
    cout<<ans;
    return 0;
    
}