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

const LL maxn = 2e4+5;
LL n,k;

struct Node {
    LL to, next, len;
    Node(){}
    Node(LL t, LL n, LL l) {
        to=t, next=n, len=l;
    }
}e[maxn<<1];

LL tot, head[maxn], ans;

void add(LL x, LL y, LL z) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
    return ;
}

LL sz[maxn], maxp[maxn], sum, root, save[maxn], dis[maxn];
bool vis[maxn];

void getroot(LL x, LL f) {
    sz[x]=1; maxp[x]=0;
    Eo(i,x,e) {
        LL v=e[i].to;
        if(f==v||vis[v]) continue;
        getroot(v, x);
        sz[x] += sz[v];
        maxp[x] = max(maxp[x], sz[v]);
    }
    maxp[x] = max(maxp[x], sum-maxp[x]);
    if(maxp[x]<maxp[root]) root=x;
    return ;
}

void getdis(LL x, LL f) {
    save[++save[0]] = dis[x];
    Eo(i,x,e) {
        LL v=e[i].to;
        if(v==f||vis[v]) continue;
        dis[v] = dis[x] + e[i].len;
        getdis(v, x);
    }
    return ;
}

LL calc(LL x) {
    save[0]=0;
    getdis(x, 0);
    sort(save+1, save+save[0]+1);
    // Fo(i,1,save[0])
        // cout<<save[i]<<" ";
    LL res=0, l=1, r=save[0];
    while(l<r) {
        while(l<r&&save[l]+save[r]>k) r--;
        res+=r-l;
        l++;
    }
    // Fo(i,1,save[0]) {
    //     Fo(j,i+1,save[0]) {
    //         if(dis[i]+dis[j]<=k)
    //             res++;
    //     }
    // }
    return res;
}

void solve(LL x) {
    vis[x] = 1;
    ans+=calc(x);
    Eo(i,x,e) {
        LL v=e[i].to;
        if(vis[v]) continue;
        ans-=calc(v);
        sum = sz[v];
        root = 0;
        maxp[root] = n;
        getroot(v, x);
        solve(root);
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(cin>>n>>k&&n&&k) {
        ans=0; tot=0;
        Ms(e,0); Ms(maxp,0); Ms(sz,0); Ms(head,0); Ms(vis,0); Ms(save,0); Ms(dis,0);
        Fo(i,1,n-1) {
            LL x,y,z; cin>>x>>y>>z;
            add(x, y, z);
            add(y, x, z);
        }
        root = 0;
        maxp[root]=sum=n;
        getroot(1,0);
        solve(root);
        // cout<<save[0]<<"*"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}