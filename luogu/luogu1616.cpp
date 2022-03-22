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

const LL maxn = 1e7+5;
LL t, m, a[10005], b[10005], f[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>t>>m;
    Fo(i,1,m) cin>>a[i]>>b[i];
    Fo(i,1,m)
        Fo(j,a[i],t)
            f[j]=max(f[j], f[j-a[i]]+b[i]);
    cout<<f[t];
    return 0;
}