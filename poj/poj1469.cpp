//By cls1277
#ifdef ONLINE_JUDGE
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

const LL maxn = 305;
LL n, m, a[maxn][maxn], b[maxn], ans;
bool vis[maxn];

bool judge(LL x) {
    Fo(i,1,m) {
        if(a[x][i]&&!vis[i]) {
            vis[i] = 1;
            if(!b[i]||judge(b[i])) {
                b[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    // ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL T; T=read();//cin>>T;
    while(T--) {
        n=read(); m=read();
        // cin>>n>>m;
        ans = 0;
        Ms(a,0); Ms(b,0);
        Fo(i,1,n) {
            LL x; x=read();//cin>>x;
            Fo(j,1,x) {
                LL y; y=read();//cin>>y;
                a[i][y] = 1;
            }
        }
        Fo(i,1,n) {
            Ms(vis,0);
            if(judge(i))
                ans++;
        }
        if(ans==n) printf("YES\n");
        else printf("NO\n");
        // if(ans==n) cout<<"YES"<<endl;
        // else cout<<"NO"<<endl;
    }
    return 0;
} 

//dinic跑最大流不能AC，会TLE

// //By cls1277
// #ifdef ONLINE_JUDGE
// #include<iostream>
// #include<cstdio>
// #include<queue>
// #include<cstring>
// #include<string>
// #include<algorithm>
// #include<cmath>
// #include<vector>
// #include<map>
// #else
// #include<bits/stdc++.h>
// #endif
// using namespace std;
// typedef long long LL;
// #define PI acos(-1)
// #define INF 2147483647
// #define eps 1e-7
// #define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
// #define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
// #define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
// #define Ms(a,b) memset((a),(b),sizeof(a))
// #define lowbit(_) _&(-_)
// #define mk(_,__) make_pair(_,__)
// #define pii pair<int,int>
// #define ls x<<1
// #define rs x<<1|1
// #define endl '\n'
// inline LL read() {
//     LL x = 0, f = 1;char c = getchar();
//     while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
//     while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
//     return x * f;
// }

// const LL maxn = 105;
// const LL maxm = 305;

// struct Node {
//     LL to, next, len;
// }e[(maxn*maxm+maxn+maxm)*2];

// LL head[maxn+maxm], tot, dis[maxn+maxm], pre[maxn+maxm], ans, s, t;

// void add(LL x, LL y, LL z) {
//     tot++;
//     e[tot].next = head[x];
//     e[tot].to = y;
//     e[tot].len = z;
//     head[x] = tot;
// }

// bool bfs() {
//     bool vis[maxn+maxm]; Ms(vis,0);
//     vis[s]=1;
//     queue<LL>q;
//     q.push(s);
//     dis[s]=INF;
//     while(!q.empty()) {
//         LL u=q.front();
//         if(u==t) return 1;
//         q.pop();
//         Eo(i,u,e) {
//             LL v=e[i].to;
//             if(e[i].len<=0||vis[v]) continue;
//             vis[v] = 1;
//             q.push(v);
//             pre[v] = i;
//             dis[v] = min(dis[u] , e[i].len);
//         }
//     }
//     return 0;
// }

// void dfs() {
//     LL x=t;
//     while(x!=s) {
//         LL p=pre[x];
//         e[p].len-=dis[t];
//         e[p^1].len+=dis[t];
//         x=e[p^1].to;
//     }
//     ans+=dis[t];
//     return ;
// }

// LL T, n, m;

// int main() {
//     // ios::sync_with_stdio(false);
//     #ifdef DEBUG
//     freopen("data.txt","r",stdin);
//     #endif
//     T=read();
//     // cin>>T;
//     while(T--) {
//         tot=1; ans=0;
//         Ms(head,0);
//         n=read(); m=read();// cin>>n>>m;
//         s=n+m+1,t=n+m+2;
//         Fo(i,1,n) {
//             LL x; x=read();//cin>>x;
//             Fo(j,1,x) {
//                 LL y; y=read(); //cin>>y;
//                 add(i,n+y,1);
//                 add(n+y,i,0);
//             }
//         }
//         Fo(i,1,n) {
//             add(s,i,1);
//             add(i,s,0);
//         }
//         Fo(i,1,m) {
//             add(n+i,t,1);
//             add(t,n+i,0);
//         }
//         while(bfs()) {
//             dfs();
//         }
//         if(ans==n) printf("YES\n");
//         else printf("NO\n");
//     }
//     return 0;
// }