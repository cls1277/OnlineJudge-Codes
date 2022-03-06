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
#define pii pair<LL,LL>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

const LL maxn = 1e4+5;
// const LL maxm = 1e5+5;

LL n, m;
vector<LL>e[maxn];
vector<pii>b;
LL dfn[maxn], low[maxn], idx, cnt, res[maxn], ans, a[maxn], color[maxn], sum[maxn];
bool ins[maxn];
stack<LL>s;

void tarjan(LL x) {
    dfn[x] = low[x] = ++idx;
    s.push(x); ins[x] = 1;
    for(LL i=0; i<e[x].size(); i++) {
        LL v=e[x][i];
        if(!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x],low[v]);
        } else if(ins[v]) {
            low[x] = min(low[x],dfn[v]);
        }
    }
    if(dfn[x]==low[x]) {
        cnt++; LL temp;
        do {
            temp = s.top();
            ins[temp] = 0;
            s.pop();
            color[temp] = cnt;
            sum[cnt] += a[temp];
        }while(temp!=x);
    }
}

LL ind[maxn];

LL topo() {
    LL ans = 0;
    struct Node {
        LL id, sum;
        Node(){}
        Node(LL i, LL s) {
            id=i , sum=s;
        }
    };
    queue<Node>q;
    Fo(i,1,cnt)
        if(!ind[i])
            q.push(Node(i,sum[i]));
    while(!q.empty()) {
        Node u=q.front(); q.pop();
        ans = max(ans, u.sum);
        for(LL i=0; i<e[u.id].size(); i++) {
            LL v=e[u.id][i];
            ind[v]--;
            if(!ind[v]) 
                q.push(Node(v,u.sum+sum[v]));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n) cin>>a[i];
    Fo(i,1,m) {
        LL x,y; cin>>x>>y;
        e[x].push_back(y);
        b.push_back(mk(x,y));
    }
    Fo(i,1,n)
        if(!dfn[i])
            tarjan(i);
    Fo(i,1,n) e[i].clear();
    // cout<<color[1]<<" "<<color[2]<<"*"<<endl;
    for(int i=0; i<b.size(); i++) {
        LL u=b[i].first, v=b[i].second;
        // cout<<u<<" "<<v<<endl;
        if(color[u]!=color[v]) {
            e[color[u]].push_back(color[v]);
            ind[color[v]]++;
        }
    }
    // cout<<sum[1]<<endl;
    cout<<topo();
    return 0;
}