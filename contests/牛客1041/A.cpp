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
LL n, a[6], f[35][18][12][10][8];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(cin>>n&&n) {
        Ms(f,0); Ms(a,0);
        Fo(i,1,n) cin>>a[i];
        f[0][0][0][0][0] = 1;
        Fo(i,0,a[5])
            Fo(j,0,a[4])
                Fo(k,0,a[3])
                    Fo(l,0,a[2])
                        Fo(m,0,a[1]) {
                            f[m+1][l][k][j][i]+=f[m][l][k][j][i];
                            if(m>l) f[m][l+1][k][j][i]+=f[m][l][k][j][i];
                            if(l>k) f[m][l][k+1][j][i]+=f[m][l][k][j][i];
                            if(k>j) f[m][l][k][j+1][i]+=f[m][l][k][j][i];
                            if(j>i) f[m][l][k][j][i+1]+=f[m][l][k][j][i];
                        }
        cout<<f[a[1]][a[2]][a[3]][a[4]][a[5]]<<endl;
    }
    return 0;
}