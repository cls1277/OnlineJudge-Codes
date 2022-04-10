//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = ;
LL f[41][41][41][41], n, m, a[351], b[4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n) cin>>a[i];
    Fo(i,1,m) {
        LL x; cin>>x;
        b[x-1]++;
    }
    Fo(i,0,b[0])
        Fo(j,0,b[1])
            Fo(k,0,b[2])
                Fo(l,0,b[3]) {
                    if(i-1>=0) f[i][j][k][l] = max(f[i][j][k][l], f[i-1][j][k][l]+a[1+i-1+2*j+3*k+4*l]);
                    if(j-1>=0) f[i][j][k][l] = max(f[i][j][k][l], f[i][j-1][k][l]+a[1+i+2*j-2+3*k+4*l]);
                    if(k-1>=0) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k-1][l]+a[1+i+2*j+3*k-3+4*l]);
                    if(l-1>=0) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l-1]+a[1+i+2*j+3*k+4*l-4]);
                }
    cout<<f[b[0]][b[1]][b[2]][b[3]]+a[n];
    return 0;
}