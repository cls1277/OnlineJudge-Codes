//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 55;
LL n, m, a[maxn][maxn], f[maxn<<1][maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n)
        Fo(j,1,m)
            cin>>a[i][j];
    Fo(i,1,n+m-2)
        Fo(j,1,n)
            Fo(k,1,n) {
                LL t1=i+2-j, t2=i+2-k;
                if(t1<1||t2<1) continue;
                LL res = max({f[i-1][j-1][k-1], f[i-1][j-1][k], f[i-1][j][k-1], f[i-1][j][k]});
                if(j==k&&t1==t2) f[i][j][k] = max(f[i][j][k], res+a[j][t1]);
                else f[i][j][k] = max(f[i][j][k], res+a[j][t1]+a[k][t2]);
            }
    cout<<f[n+m-2][n][n];
    return 0;
}