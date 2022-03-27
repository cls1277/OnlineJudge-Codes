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
#define INF 2147483647

const LL maxn = 105;
LL n, m, v[maxn], t[maxn], f[2][maxn][5300], pre;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n) cin>>v[i]>>t[i];
    pre = 1;
    Fo(j,0,m)
        Fo(k,0,5200) {
            if(k==2600) f[0][j][k]=0;
            else f[0][j][k]=-INF;
        }
    Fo(i,1,n) {
        Fo(j,0,m) {
            Fo(k,0,5200) {
                f[pre][j][k] = f[1-pre][j][k];
                if(k-t[i]>=0) f[pre][j][k] = max(f[pre][j][k], f[1-pre][j][k-t[i]]+v[i]);
                if(k+t[i]<=5200) f[pre][j][k] = max(f[pre][j][k], f[1-pre][j][k+t[i]]+v[i]);
                if(j>=1&&k-2*t[i]>=0) f[pre][j][k] = max(f[pre][j][k], f[1-pre][j-1][k-2*t[i]]+v[i]);
                if(j>=1&&k+2*t[i]<=5200) f[pre][j][k] = max(f[pre][j][k], f[1-pre][j-1][k+2*t[i]]+v[i]);
                // pre = 1-pre;
            }
        }
        pre = 1-pre;
    }
    cout<<f[n%2][m][2600];
    return 0;
}