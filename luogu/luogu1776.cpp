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

const LL maxn = 1e5+5;
LL n, m, v[maxn], w[maxn], idx, f[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n) {
        LL x, y, z; cin>>x>>y>>z;
        LL k=1;
        while(z>=k) {
            idx++;
            v[idx] = x*k;
            w[idx] = y*k;
            z-=k;
            k<<=1;
        }
        if(z) {
            idx++;
            v[idx] = x*z;
            w[idx] = y*z;
        }
    }
    Fo(i,1,idx)
        Ro(j,m,w[i])
            f[j]=max(f[j], f[j-w[i]]+v[i]);
    cout<<f[m];
    return 0;
}