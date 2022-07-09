//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 15;
LL n=12, d[maxn], f[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    d[1] = 1;
    Fo(i,2,n) {
        d[i] = 2*d[i-1]+1;
    }
    f[1] = 1;
    Fo(i,2,n) {
        LL minn = INT_MAX;
        Fo(j,1,i-1) {
            minn = min(minn, 2*f[j]+d[i-j]);
        }
        f[i] = minn;
    }
    Fo(i,1,12) cout<<f[i]<<endl;
    return 0;
}