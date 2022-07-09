//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 21;
int n, w[maxn][maxn], f[1<<maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,0,n-1) {
        Fo(j,0,n-1) {
            cin>>w[i][j];
        }
    }
    Ms(f, 0x3f);
    f[1][0] = 0;
    Fo(i,1,(1<<n)-1) {
        Fo(j,0,n-1) {
            if(!((i>>j)&1)) continue;
            Fo(k,0,n-1) {
                //i xor (1<<j) 将i的第j位从1变为0
                if(!(((i^(1<<j))>>k) & 1)) continue;
                f[i][j] = min(f[i][j], f[i^(1<<j)][k]+w[k][j]);
            } 
        }
    }
    cout<<f[(1<<n)-1][n-1];
    return 0;
}