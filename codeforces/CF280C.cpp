//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = 1e5+5;
LL n;
double ans;
unordered_map<LL, vector<LL>>e;

void dfs(LL x, LL f, LL d) {
    ans += 1.0/d;
    for(auto it:e[x]) {
        if(it==f) continue;
        dfs(it, x, d+1);
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n-1) {
        LL x, y; cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0, 1);
    printf("%.20lf",ans);
    return 0;
}