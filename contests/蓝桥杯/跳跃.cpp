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
LL a[maxn][maxn], n, m, f[maxn][maxn];

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
    Ms(f, -0x3f);
    f[1][1] = a[1][1];
    Fo(i,1,n)
        Fo(j,1,m) {
            Ro(k,i-1,i-3) { 
                if(k<1) break;
                f[i][j] = max(f[i][j], f[k][j]+a[k][j]);
            }
            Ro(k,j-1,j-3) {
                if(k<1) break;
                f[i][j] = max(f[i][j], f[i][k]+a[i][k]);
            }
        }
    cout<<f[n][m];
    return 0;
}