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

const LL maxn = 1e3+5;
LL n, a[maxn], b[maxn], f[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) cin>>a[i];
    Fo(i,1,n) cin>>b[i];
    Fo(i,1,n) f[i][0]=f[0][i]=0;
    Fo(i,1,n)
        Fo(j,1,n) {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if(a[i]==b[j]) f[i][j] = max(f[i][j], f[i-1][j-1]+1);
        }
    cout<<f[n][n];
    return 0;
}