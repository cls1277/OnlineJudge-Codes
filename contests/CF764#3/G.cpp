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
#include<stack>
#include<set>
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

const LL maxn = 2e5+5;
LL n, m, fa[maxn];
tuple<LL,LL,LL>e[maxn];
bool vis[maxn];

LL find(LL x) {
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}

// LL find(LL x) {
//     if(x!=fa[x])
//         fa[x] = find(fa[x]);
//     return fa[x];
// }

LL ans;

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        ans = 0;
        Ms(vis,0);
        cin>>n>>m;
        Fo(i,1,m) {
            LL x, y, z; cin>>x>>y>>z;
            e[i] = make_tuple(x,y,z);
        }
        Ro(i,31,0) {
            Fo(j,1,n) fa[j]=j;
            Fo(j,1,m) {
                if(vis[j]) continue;
                LL w = get<2>(e[j]);
                if((w>>i)&1) continue;
                LL fx=find(get<0>(e[j])), fy=find(get<1>(e[j]));
                if(fx!=fy) fa[fx]=fy;
            }
            LL sum=0;
            Fo(j,1,n)
                if(fa[j]==j) sum++;
            if(sum==1) {
                Fo(j,1,m) {
                    LL w=get<2>(e[j]);
                    if((w>>i)&1)
                        vis[j] = 1;
                }
            } else ans+=(1<<i);
        }
        cout<<ans<<endl;
    }
    return 0;
}