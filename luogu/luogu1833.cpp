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

const LL maxn = 1e6+5;
LL t, n, f[1005];
vector<LL>v[2];
vector<LL>w[2];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL h1, m1, h2, m2;
    scanf("%lld:%lld %lld:%lld %lld",&h1,&m1,&h2,&m2,&n);
    t = h2*60+m2-h1*60-m1;
    Fo(i,1,n) {
        LL x, y, z; cin>>x>>y>>z;
        if(!z) {
            v[1].push_back(y);
            w[1].push_back(x);
        } else if(z==1) {
            v[0].push_back(y);
            w[0].push_back(x);
        } else {
            LL k=1;
            while(z>=k) {
                v[0].push_back(y*k);
                w[0].push_back(x*k);
                z-=k;
                k<<=1;
            }
            if(z) {
                v[0].push_back(y*z);
                w[0].push_back(x*z);
            }
        }
    }
    LL x = v[0].size()-1;
    Fo(i,0,x)
        Ro(j,t,w[0][i])
            f[j] = max(f[j], f[j-w[0][i]]+v[0][i]);
    x = v[1].size()-1;
    Fo(i,0,x)
        Fo(j,w[1][i],t)
            f[j] = max(f[j], f[j-w[1][i]]+v[1][i]);
    cout<<f[t];
    return 0;
}