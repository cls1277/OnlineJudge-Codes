//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e5+5;
LL n, q, M[15];
struct Node {
    LL a, b, c;
}aa[15][maxn];

const LL mod = 998244353;

inline LL binpow(LL a, LL q) {
    a %= mod;
    q %= mod;
    LL res = 1;
    while (q) {
        if (q&1) {
            res = (res * a) % mod;
        }
        q >>= 1;
        a = (a * a) % mod;
    }
    return res % mod;
}

LL solve(LL a, LL b, LL c) {
    LL res = 0;
    Fo(i,1,n) {
        bool flag = 0;
        Fo(j,1,M[i]) {
            if(a>=aa[i][j].a&&b>=aa[i][j].b&&c>=aa[i][j].c) {
                flag = 1;
                break;
            }
        }
        if(flag) res++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>q;
    Fo(i,1,n) {
        LL m; cin>>m;
        Fo(j,1,m) {
            cin>>aa[i][j].a>>aa[i][j].b>>aa[i][j].c;
        }
        M[i] = m;
    }
    LL seed; cin>>seed;
    mt19937 rng(seed);
    uniform_int_distribution<> u(1, 400);
    LL lastans = 0;
    LL ans = 0;
    LL fa = binpow(seed, q);
    LL seed_ = binpow(seed, mod-2);
    // cout<<seed<<' '<<q<<endl;
    // cout<<fa<<' '<<seed_<<endl;
    for (LL i = 1; i <= q; i++) {
        LL IQ = (u(rng)^lastans)%400+1;
        LL EQ = (u(rng)^lastans)%400+1;
        LL AQ = (u(rng)^lastans)%400+1;
        lastans = solve(IQ, EQ, AQ);
        // cout<<lastans<<' ';
        fa = (fa * seed_) % mod;
        ans = (ans + lastans * fa) % mod;
    }
    // cout<<endl;
    // printf("%lld\n", ans);
    cout<<ans;
    return 0;
}