//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5005;
LL a[maxn][maxn], s[maxn][maxn], n, R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>R;
    Fo(i,1,n) {
        int x, y, v; cin>>x>>y>>v;
        a[++x][++y] = v;
    }
    Fo(i,1,5000) {
        Fo(j,1,5000) {
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
    if(R>=n) {
        cout<<s[n][n];
    } else {
        LL ans = 0;
        Fo(i,R,5000) {
            Fo(j,R,5000) {
                ans = max(ans,  s[i][j]+s[i-R][j-R]-s[i][j-R]-s[i-R][j]);
            }
        }
        cout<<ans;
    }
    return 0;
}