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
LL n, m;

struct Node {
    LL w, idx; double p;
} a[maxn], b[maxn];

bool operator < (const Node &a, const Node &b) {
    return a.w*a.p>b.w*b.p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n) cin>>a[i].w;
    Fo(i,1,n) {
        LL x; cin>>x;
        a[i].idx = i;
        a[i].p = x*1.0/10000;
    }
    sort(a+1, a+n+1);
    double ans = 0;
    Ro(i,m,1) b[i] = a[m-i+1];
    b[0].p = 1;
    Fo(i,1,m) {
        double res = 1;
        Fo(j,0,i-1) res *= b[j].p;
        ans += b[i].w*res;
    }
    cout<<ans;
    return 0;
}