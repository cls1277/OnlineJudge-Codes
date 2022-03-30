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

// const LL maxn = ;
LL n, m, k, a[16][16], f[20][256][16][16][2][2], sum[16][16];
struct Pre {
    LL i, j, l, r, x, y;
};
Pre pre[20][256][16][16][2][2];

void print(Pre t) {
    if(t.i==0) return ;
    Pre temp = pre[t.i][t.j][t.l][t.r][t.x][t.y];
    print(temp);
    Fo(i,t.l,t.r) cout<<t.i<<" "<<i<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>k;
    Fo(i,1,n)
        Fo(j,1,m) {
            cin>>a[i][j];
            sum[i][j] = sum[i][j-1]+a[i][j];
        }
    Fo(i,1,n) f[i][0][0][0][1][0] = 0;
    Fo(i,1,n)
        Fo(j,0,k)
            Fo(l,1,m)
                Fo(r,l,m) {
                    if(j-(r-l+1)<0) break;
                    LL res = sum[i][r] - sum[i][l-1], temp = 0;
                    if(j==r-l+1) {
                        f[i][j][l][r][1][0] = res+f[i-1][0][0][0][1][0];
                        pre[i][j][l][r][1][0] = {i-1, 0, 0, 0, 1, 0};
                    }
                    else {
                        temp = 0;
                        Fo(p,l,r)
                            Fo(q,p,r)
                                if(f[i-1][j-(r-l+1)][p][q][1][0]>temp) {
                                    temp = f[i-1][j-(r-l+1)][p][q][1][0];
                                    pre[i][j][l][r][1][0] = {i-1, j-(r-l+1), p, q, 1, 0};
                                }
                        f[i][j][l][r][1][0] = temp+res;
                    }
                    temp = 0;
                    Fo(p,l,r)
                        Fo(q,r,m)
                            Fo(x,0,1)
                                if(f[i-1][j-(r-l+1)][p][q][1][x]>temp) {
                                    temp = f[i-1][j-(r-l+1)][p][q][1][x];
                                    pre[i][j][l][r][1][1] = {i-1, j-(r-l+1), p, q, 1, x};
                                }
                    f[i][j][l][r][1][1] = temp+res;
                    temp = 0;
                    Fo(p,1,l)
                        Fo(q,l,r)
                            Fo(x,0,1)
                                if(f[i-1][j-(r-l+1)][p][q][x][0]>temp) {
                                    temp = f[i-1][j-(r-l+1)][p][q][x][0];
                                    pre[i][j][l][r][0][0] = {i-1, j-(r-l+1), p, q, x, 0};
                                }
                    f[i][j][l][r][0][0] = temp+res;
                    temp = 0;
                    Fo(p,1,l)
                        Fo(q,r,m)
                            Fo(x,0,1)
                                Fo(y,0,1)
                                    if(f[i-1][j-(r-l+1)][p][q][x][y]>temp) {
                                        temp = f[i-1][j-(r-l+1)][p][q][x][y];
                                        pre[i][j][l][r][0][1] = {i-1, j-(r-l+1), p, q, x, y};
                                    }
                    f[i][j][l][r][0][1] = temp+res;
                }
    LL ans = 0; Pre t;
    Fo(l,1,m)
        Fo(r,1,m)
            Fo(x,0,1)
                Fo(y,0,1)
                    if(f[n][k][l][r][x][y]>ans) {
                        ans = f[n][k][l][r][x][y];
                        t = {n, k, l, r, x, y};
                    }
    cout<<"Oil : "<<ans<<endl;
    print(t);
    return 0;
}