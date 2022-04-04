//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e5+5;

LL n, m, a[maxn], b[maxn], d[maxn], sz[maxn], ind[maxn];
LL dfn[maxn], low[maxn], idx, cnt, color[maxn];
bool ins[maxn];//是否在栈里
stack<LL>st;
vector<LL>ed[maxn], e[maxn];//vector存图
pair<LL, LL>c[300005];

void tarjan(LL x) {
    dfn[x] = low[x] = ++idx;
    st.push(x); ins[x] = 1;
    for(LL i=0; i<ed[x].size(); i++) {
        LL v=ed[x][i];
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
            //这次循环弹出来的所有temp一定是同一个强连通分量里的
            temp = st.top();
            ins[temp] = 0;
            color[temp] = cnt;
            sz[cnt]++;
            b[cnt] = max(b[cnt], a[temp]);
            st.pop();
        }while(temp!=x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n>>m;
    Fo(i,1,n) cin>>a[i];
    Fo(i,1,m) {
        LL x, y; cin>>x>>y;
        ed[y].push_back(x);
        c[i] = {x, y};
    }
    Fo(i,1,n)
        if(!dfn[i])
            tarjan(i);
    Fo(i,1,m) {
        LL x=c[i].first, y=c[i].second;
        if(color[x]==color[y]) continue;
        e[color[y]].push_back(color[x]);
        ind[color[x]]++;
    }
    LL ans = 0;
    queue<LL>q;
    Fo(i,1,cnt) {
        if(!ind[i])
            q.push(i);
        d[i] = b[i];
    }
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        ans += d[u]*sz[u];
        for(auto v:e[u]) {
            ind[v]--;
            d[v] = max({d[v], d[u], b[u]});
            if(!ind[v]) q.push(v);
        }
    }
    cout<<ans;
    return 0;
}