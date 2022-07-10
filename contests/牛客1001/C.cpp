//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e5+5;
LL n, m, T, row[maxn], col[maxn], g[maxn], c[maxn];

LL solve(LL x, LL a[]) {
    Fo(i,1,x) g[i] = g[i-1]+a[i];
    if(g[x]%x) return -1;
    LL avg = g[x]/x;
    Fo(i,1,x) c[i] = (i-1)*avg-g[i-1];
    sort(c+1, c+x+1);
    LL ans = 0;
    Fo(i,1,n) ans += abs(c[(x+1)/2]-c[i]);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>T;
    Fo(i,1,T) {
        LL x, y; cin>>x>>y;
        row[x]++; col[y]++;
    }
    LL r=solve(n, row), c=solve(m, col);
    if(r==-1&&c==-1) cout<<"impossible";
    else if(r==-1) {
        cout<<"column "<<c;
    } else if(c==-1) {
        cout<<"row "<<r;
    } else {
        cout<<"both "<<r+c;
    }
    return 0;
}