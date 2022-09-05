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
LL n, m, idx, b[maxn];
double mx = -1e18, p[maxn];
struct Node {
    LL w, idx; double p;
} a[maxn];

bool operator < (const Node &a, const Node &b) {
    return a.w<b.w;
}

priority_queue<Node> s;

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
        a[i].p = p[i] = x*1.0/10000;
        if(a[i].w*a[i].p>mx) {
            mx = a[i].w*a[i].p;
            idx = i;
        }
    }
    Fo(i,1,n) {
        if(i!=idx) {
            s.push(a[i]);
        }
    }
    b[0] = 0;
    a[0].p = 1;
    b[1] = idx;
    Fo(i,2,m) {
        b[i] = s.top().idx;
        s.pop();
    }
    double ans = 0;
    Fo(i,1,m) {
        double res = 1;
        Fo(j,0,i-1) res *= a[b[j]].p;
        ans += a[b[i]].w*res;
    }
    cout<<ans;
    return 0;
}