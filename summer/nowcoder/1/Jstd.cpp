//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef int LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2e5+5;
LL n, fa[maxn], sz[maxn], q[maxn];
bool vis[maxn];

inline LL read(){
    LL x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

LL find(LL x) {
    while(x!=fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

unordered_set<LL> e[maxn], pre[maxn];

// int find(int x){
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; t=read(); //cin>>t;
    Fo(tt,1,t) {
        // cin>>n;
        n = read();
        // vector<LL> sz(n+1, 1);
        // vector<bool> vis(n+1, 0);
        // unordered_map<LL, unordered_set<LL>> e, pre;
        Fo(i,1,n) {
            e[i].clear();
            pre[i].clear();
            vis[i] = 0;
            fa[i] = i;
            sz[i] = 1;
        }
        Fo(i,1,n) {
            // fa[i] = i;
            LL x; x=read(); //cin>>x;
            Fo(j,1,x) {
                LL y; y=read(); //cin>>y;
                e[y].insert(i);
                pre[i].insert(y);
            }
        }
        // queue<LL> q;
        // vector<LL> q(n+1, 0);
        LL _h=0, _t=-1;
        Fo(i,1,n)
            if(pre[i].size()==1) {
                // q.push(i);
                q[++_t] = i;
                vis[i] = 1;
            }
        while(_h<=_t) {
        // while(!q.empty()) {
            // LL u = q.front(); q.pop();
            LL u = q[_h++];
            LL p = *pre[u].begin();
            // for(auto it:pre[u]) {
            //     p = it;
            //     break;
            // }
            LL p1=find(u), p2=find(p);
            if(p1==p2) continue;
            if(sz[p1]>sz[p2]) swap(p1, p2);
            fa[p1] = p2;
            sz[p2] += sz[p1];
            for(auto it:e[p1]) {
                e[p2].insert(it);
                pre[it].erase(p1);
                pre[it].insert(p2);
                if(pre[it].size()==1&&!vis[it]) {
                    vis[it] = 1;
                    // q.push(it);
                    q[++_t] = it;
                }
            }
        }
        LL ans = 1;
        Fo(i,1,n) ans = max(ans, sz[i]);
        // cout<<"Case #"<<tt<<": "<<ans<<endl;
        printf("Case #%lld: %lld\n", tt, ans) ; 
    }
    return 0;
}