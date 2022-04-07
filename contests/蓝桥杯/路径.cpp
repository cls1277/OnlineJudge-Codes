//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2025;
vector<pair<LL, LL>>e[maxn<<1];
LL n, dis[maxn];

struct Que {
    LL id, len;
};

bool operator < (const Que &a, const Que&b) {
    return a.len>b.len;
}

LL gcd(LL x, LL y) {
    return y?gcd(y, x%y):x;
}

LL lcm(LL x, LL y) {
    return x*y/gcd(x, y);
}

void dij(LL x) {
    Ms(dis, 0x3f);
    dis[x] = 0;
    priority_queue<Que>q;
    q.push({x, 0});
    while(!q.empty()) {
        Que u=q.top(); q.pop();
        if(u.len!=dis[u.id]) continue;
        for(auto it:e[u.id]) {
            LL v=it.first, l=it.second;
            if(dis[v]>dis[u.id]+l) {
                dis[v] = dis[u.id]+l;
                q.push({v, dis[v]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    n = 2021;
    Fo(i,1,n)
        Fo(j,i+1,n) {
            if(abs(i-j)>21) continue;
            LL l = lcm(i, j);
            e[i].push_back({j, l});
            e[j].push_back({i, l});
        }
    dij(1);
    cout<<dis[2021];
    return 0;
}