//By cls1277
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<set>
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
LL n;
vector<pair<LL,LL>>a;
map<LL, bool>vis;
LL dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};

#define pii pair<LL, LL>

pii bfs(pii u) {
    queue<pii>q;
    Fo(i,0,3) {
        LL tx=u.first+dx[i], ty=u.second+dy[i];
        LL m = tx*100000+dy;
        if(!vis[m]) return {tx, ty};
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        LL x, y; cin>>x>>y;
        a.push_back({x, y});
        vis[x*100000+y] = 1;
    }
    for(pii it:a) {
        pii res = bfs(it);
        cout<<res.first<<" "<<res.second<<endl;
    }
    return 0;
}
