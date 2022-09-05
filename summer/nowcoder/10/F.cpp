//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 105;
LL n, m, s, t;
bool vis[maxn], flag[maxn];
vector<LL> e[maxn];

void dfs(LL x, LL fa) {
    for(auto it:e[x]) {
        if(vis[it]) {
            if(it!=fa) flag[it] = 1;
            continue;
        }
        vis[it] = 1;
        dfs(it, x);
    }
}

bool bfs(LL x) {
    queue<LL> q; q.push(x);
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        if(u==s) return true;
        for(auto v:e[u]) {
            if(!flag[v]) continue;
            q.push(v);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL T; cin>>T;
    while(T--) {
        cin>>n>>m>>s>>t;
        Fo(i,1,n) {
            vis[i] = 0;
            flag[i] = 0;
            e[i].clear();
        }
        Fo(i,1,m) {
            LL x, y; cin>>x>>y;
            e[y].push_back(x);
            e[x].push_back(y);
        }
        dfs(t, t);
        // Fo(i,1,n) cout<<flag[i]<<' ';
        if(bfs(t)) cout<<"Join Player"<<endl;
        else cout<<"Cut Player"<<endl;
    }
    return 0;
}