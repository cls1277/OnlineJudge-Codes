//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//const LL maxn = ;

const LL mod = 998244353;

inline LL binpow(LL a, LL q = mod - 2) {
    LL res = 1;
    while (q) {
        if (q & 1) res = res * a % mod;
        a = a * a % mod;
        q >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL A, B, t;
    cin >> A;
    for (int i = 0; i < 7; i++) {
        cin >> t;
    }
    cin >> B;
    for (int i = 0; i < 7; i++) {
        cin >> t;
    }
    if(A%10==0) A /= 10;
    else A = A/10+1;
    if(B%10==0) B /= 10;
    else B = B/10+1;
    LL ad=0, two = 4;
    Fo(i,3,A) {
        two = ((two<<1)-1)%mod;
        ad = (ad+two)%mod;
    } 
    LL s = binpow(2, A)-1, t = 4;
    Fo(i,1,B) {
        s = (s+ad+)
    }
    return 0;
}