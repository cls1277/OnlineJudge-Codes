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

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if(!b) {
        x=1; y=0;
        return a;
    }
    LL d=exgcd(b, a%b, x, y);
    LL k = x; x = y;
    y = k-a/b*y;
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL a, b;
    cin>>a>>b;
    LL x, y;
    exgcd(a, -180*b, x, y);
    cout<<x<<' '<<y;
    return 0;
}