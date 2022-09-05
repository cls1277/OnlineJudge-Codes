//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2e5+5;
LL n, m, k, w, c1, c2;
LL ans1[maxn], ans2[maxn];

struct Node {
    LL ops, weight;
};

vector<Node> a, b;

bool operator < (const Node &x, const Node &y) {
    if(x.ops!=y.ops) return x.ops>y.ops;
    return x.weight<y.weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m>>k;
    Fo(i,1,n) {
        LL x, y; cin>>x>>y;
        if(x<y) {
            a.push_back({x, -1});
            a.push_back({y, 1});
        } else {
            b.push_back({x, 1});
            b.push_back({y, -1});
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(auto it:a) {
        w += it.weight;
        if(w > m*c1) ans1[++c1] = it.ops;
    }
    w = 0;
    for(auto it:b) {
        w += it.weight;
        if(w > m*c2) ans2[++c2] = it.ops;
    }
    LL c = max(c1, c2), ans = 0;
    Fo(i,1,c) {
        ans += (max(ans1[i], ans2[i])-1)*2;
    }
    cout<<ans;
    return 0;
}