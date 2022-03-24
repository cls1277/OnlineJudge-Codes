//By cls1277
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<set>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

// const LL maxn = ;

LL gcd(LL x, LL y) {
    return y?gcd(y, x%y):x;
}

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
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL n, m, ans=0;
    while(cin>>m>>n&&n&&m) {
        ans = 0;
        Fo(i,1,n) ans+=qpow(m, gcd(i, n));
        if(n&1) ans+=n*qpow(m, (n+1)/2);
        else {
            ans+=n/2*qpow(m, n/2);
            ans+=n/2*qpow(m, n/2+1);
        }
        ans/=2*n;
        cout<<ans<<endl;
    }
    return 0;
}