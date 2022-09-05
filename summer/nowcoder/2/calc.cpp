//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 100;
LL res[maxn];
const LL mod = 998244353;

LL check(LL a, LL b, LL c) {
    return (a==1)&&(b==8)&&(c==19);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL n;
    Fo(i,0,25)  {
        Fo(j,0,25) {
            Fo(k,0,25) {
                Fo(l,0,25) {
                    Fo(m,0,25) {
                        Fo(p,0,25) {
                            Fo(q,0,25) {
                                Fo(o,0,25) {
                                    // Fo(u,0,25) {
                                        LL ans = 0;
                                        ans += check(i, j, k);
                                        ans += check(j, k, l);
                                        ans += check(k, l, m);
                                        ans += check(l, m, p);
                                        ans += check(m, p, q);
                                        ans += check(p, q, o);
                                        // ans += check(q, o, u);
                                        if(!ans) res[0] = (res[0]+1)%mod;
                                    // }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<res[0];
    // Fo(i,0,6) cout<<res[i]<<' ';
    return 0;
}