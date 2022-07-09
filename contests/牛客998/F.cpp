//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL mod = 9901;
LL a, b;
vector<pair<LL, LL>>c;

LL qpow(LL x, LL y) {
    LL z = 1;
    while(y) {
        if(y&1) z = z*x%mod;
        x = x*x%mod;
        y >>= 1;
    }
    return z;
}

LL qsum(LL x, LL y) {
    if(!y) return 1;
    if(y&1) return (1+qpow(x, (y+1)>>1))%mod*qsum(x, (y-1)>>1)%mod;
    else return ((1+qpow(x, y>>1))%mod*qsum(x, y/2-1)%mod+qpow(x, y)%mod)%mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>a>>b;
    for(int i=2; i<=a; i++) {
        if(a%i==0) {
            int cnt = 0;
            while(a%i==0) {
                cnt++;
                a /= i;
                if(a==1) break;
            }
            c.push_back({i, cnt});
        }
    }
    LL ans = (a!=0);
    for(auto it:c) {
        ans = (ans*qsum(it.first, b*it.second)%mod)%mod;
        // cout<<it.first<<' '<<it.second<<endl;
    }
    cout<<ans;
    return 0;
}