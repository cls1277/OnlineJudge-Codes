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
LL n, deep[maxn], fa[maxn][25];
map<LL, vector<LL>> e;
pair<LL, LL> dep[maxn];
bool vis[maxn];

void dfs(LL u, LL f) {
    deep[u] = deep[f]+1;
    fa[u][0] = f;
    for(auto v:e[u]) {
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v, u);
    }
}

LL lca(LL x, LL y) {
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=20; i>=0; i--) {
        if(deep[fa[x][i]]>=deep[y]) {
            x = fa[x][i];
        }
        if(x==y) return x;
    }
    for(int i=20; i>=0; i--) {
        if(fa[x][i]!=fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n-1) {
        LL x, y; cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vis[1] = 1;
    dfs(1, 0);
    for(int i=1; i<=20; i++) {
        for(int j=1; j<=n; j++) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
    }
    LL t; cin>>t;
    while(t--) {
        LL m; cin>>m;
        if(m<=2) {
            Fo(i,1,m) {
                LL x; cin>>x;
            }
            cout<<"YES"<<endl;
            continue;
        }
        Fo(i,1,m) {
            LL x; cin>>x;
            dep[i] = {deep[x], x};
        }
        bool flag = 0;
        sort(dep+1, dep+m+1);
        pair<LL, LL> a=dep[m], b;
        Ro(i,m-1,1) {
            if(lca(dep[i].second, a.second)!=dep[i].second) {
                b = dep[i];
                break;
            }
        }
//        cout<<a.second<<' '<<b.second<<endl;
        LL l = lca(a.second, b.second);
        for(int i=1; i<=m-2; i++) {
            LL x = dep[i].second;
            LL c = lca(x, a.second), d = lca(x, b.second);
            if((c==x&&d==l)||(c==l&&d==x)) {
               continue; 
            } else {
                flag = 1;
                break;
            }
        }
        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}



// //By cls1277
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long LL;
// #define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
// #define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
// #define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
// #define Ms(a,b) memset((a),(b),sizeof(a))
// #define endl '\n'

// const LL maxn = 2e5+5;
// map<LL, vector<LL>> e;
// LL n, r[maxn], l[maxn];
// map<LL, bool> vis;

// void dfs(LL x, LL f) {
//     for(auto v:e[x]) {
//         if(v==f||vis[v]) continue;
//         vis[v] = 1;
//         dfs(v, x);
//         r[x] += r[v];
//         if(r[v]) l[x]++;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     #ifdef DEBUG
//     freopen("data.txt","r",stdin);
//     #endif
//     cin>>n;
//     Fo(i,1,n-1) {
//         LL x, y; cin>>x>>y;
//         e[x].push_back(y);
//         e[y].push_back(x);
//     }
//     LL t; cin>>t;
//     while(t--) {
//         vis.clear(); Ms(r, 0); Ms(l, 0);
//         LL m; cin>>m;
//         Fo(i,1,m) {
//             LL x; cin>>x;
//             r[x] = 1;
//         }
//         vis[1] = 1;
//         dfs(1, 1);
//         Fo(i,1,n) cout<<l[i]<<" ";
//         cout<<endl;
//         continue;
//         LL cnt = 0;
//         Fo(i,1,n) {
//             if(r[i]) {
//                 cnt++;
//                 if(cnt>1) {
//                     break;
//                 }
//             }
//         }
//         if(cnt>1) cout<<"NO"<<endl;
//         else cout<<"YES"<<endl;
//     }
//     return 0;
// }
