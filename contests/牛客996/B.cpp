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

LL qpow(LL x, LL y, LL mod) {
    LL z = 1;
    while(y) {
        if(y&1)
            z = z*x%mod;
        x = x*x%mod;
        y >>= 1;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL T; cin>>T;
    while(T--) {
        LL p; cin>>p;
        LL n, c=0; cin>>n;
        Fo(i,1,n) {
            LL a, b; cin>>a>>b;
            c = (c+qpow(a, b, p)%p)%p;
        }
        cout<<c<<endl;
    }
    return 0;
}