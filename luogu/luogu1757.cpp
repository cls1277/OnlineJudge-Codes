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

const LL maxn = 1e3+5;
LL n, m, a[maxn], b[maxn], g, f[maxn];
vector<LL>c[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>m>>n;
    Fo(i,1,n) {
        cin>>a[i]>>b[i];
        LL x; cin>>x;
        c[x].push_back(i);
        g = max(g, x);
    }
    Fo(i, 1, g)
        Ro(j, m, 0)
            for(auto &it:c[i])
                if(j>=a[it])
                    f[j] = max(f[j], f[j-a[it]]+b[it]);
    cout<<f[m];
    return 0;
}