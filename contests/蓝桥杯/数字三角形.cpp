//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 105;
LL n, a[maxn][maxn], f[maxn][maxn], ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n)
        Fo(j,1,i)
            cin>>a[i][j];
    f[1][1] = a[1][1];
    Fo(i,2,n)
        Fo(j,1,i)
            f[i][j] = max(f[i-1][j], f[i-1][j-1])+a[i][j];
    if(n%2==0) ans = max(f[n][n/2], f[n][n/2+1]);
    else ans = f[n][n/2+1];
    cout<<ans;
    return 0;
}