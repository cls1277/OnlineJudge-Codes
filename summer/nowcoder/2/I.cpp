//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e4+5;
LL n, k, d;
double x[maxn][55], y[maxn][55], z[maxn][55], ans[maxn][55];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>k>>d;
    Fo(i,1,n) {
        double len = 0;
        Fo(j,1,k) {
            cin>>x[i][j];
            len += x[i][j]*x[i][j];
        }
        len = sqrt(len);
        Fo(j,1,k) x[i][j] /= len;
    }
    Fo(i,1,n)
        Fo(j,1,d)
            cin>>y[i][j];
    Fo(i,1,n)
        Fo(j,1,k)
            Fo(l,1,d)
                z[j][l] += x[i][j]*y[i][l];
    Fo(i,1,n)
        Fo(j,1,d)
            Fo(l,1,k)
                ans[i][j] += x[i][l]*z[l][j];
    Fo(i,1,n) {
        Fo(j,1,d)
            cout<<fixed<<setprecision(8)<<ans[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}