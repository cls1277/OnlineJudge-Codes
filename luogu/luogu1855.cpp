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

const LL maxn = 105;
LL n, m, t, a[maxn], b[maxn], f[205][205];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>t;
    Fo(i,1,n) cin>>a[i]>>b[i];
    Fo(i,1,n)
        Ro(j, m, a[i])
            Ro(k, t, b[i])
                f[j][k] = max(f[j][k], f[j-a[i]][k-b[i]]+1);
    cout<<f[m][t];
    return 0;
}