//By cls1277
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))

const int maxn = 1e3+5;

//根据实际情况决定是否添加val，比如mcmf就需要添加
struct Edge {
    LL to , next , len, val;
}e[maxn<<1];

LL tot, head[maxn];
LL n;//n是点的个数

void add(LL x, LL y, LL z=0) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}

//wt是带权值的lca
LL deep[maxn], fa[maxn][25], wt[maxn][25];
bool vis[maxn];

void dfs(LL u, LL f, LL w) {
    deep[u] = deep[f]+1;
    fa[u][0] = f;
    wt[u][0] = w;
    for(int i=head[u]; i; i=e[i].next) {
        LL v=e[i].to;
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v, u, e[i].len);
    }
}

LL lca(LL x, LL y) {
    LL ans = INT_MAX;
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=20; i>=0; i--) {
        if(deep[fa[x][i]]>=deep[y]) {
            ans = min(ans, wt[x][i]);
            x = fa[x][i];
        }
        if(x==y) return ans;
    }
    for(int i=20; i>=0; i--) {
        if(fa[x][i]!=fa[y][i]) {
            ans = min(ans, wt[x][i]);
            ans = min(ans, wt[y][i]);
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    ans = min(ans, wt[x][0]);
    ans = min(ans, wt[y][0]);
    return ans;
}

void lca_init(LL n) {
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(i,0,INT_MAX);
        }
    }
    for(int i=1; i<=20; i++) {
        for(int j=1; j<=n; j++) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
            wt[j][i] = min(wt[j][i-1], wt[fa[j][i-1]][i-1]);
        }
    }
}

// 无边权的LCA
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

void lca_init() {
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(i,0,INT_MAX);
        }
    }
    for(int i=1; i<=20; i++) {
        for(int j=1; j<=n; j++) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
    }
}

// LCA tarjan做法

// 并查集，将fa改为pa

LL pa[maxn], lca_ans[maxn];
map<LL, vector<pair<LL, LL>>> q;

LL find(LL x) {
    while(x!=pa[x]) {
        x = pa[x] = pa[pa[x]];
    }
    return x;
}

void Union(LL x, LL y) {
    LL fx=find(x), fy=find(y);
    pa[fx] = fy;
}

void lca_tarjan(LL x, LL f) {
    Eo(i, x, e) {
        LL v = e[i].to;
        if(v==f) continue;
        lca_tarjan(v, x);
        Union(v, x);
    }
    vis[x] = 1;
    for(auto it:q[x]) {
        if(vis[it.second]) {
//            cout<<x<<' '<<it.second<<' '<<find(it.second)<<endl;
            lca_ans[it.first] = find(it.second);
        }
    }
}

void lca_tarjan_main() {
    LL m; cin>>m; //m次查询
    Fo(i,1,m) {
        LL a, b; cin>>a>>b;
        q[a].push_back({i, b});
        q[b].push_back({i, a});
    }
    lca_tarjan(s, s); //s为树的根，可以看题目给不给，或者通过入度判断
    Fo(i,1,m) cout<<lca_ans[i]<<endl;
}

// LCA RMQ做法

LL first[maxn];
pair<LL, LL> stb[maxn][25]; //first:deep, second:id
vector<pair<LL, LL>> a; //表

pair<LL, LL> calc(pair<LL, LL> x, pair<LL, LL> y) {
    if(x.first < y.first) return x;
    return y;
}

void lca_rmq(LL x, LL f) {
    first[x] = cnt;
    // a.push_back({deep[x], x}); cnt++;
    bool flag = 0;
    Eo(i, x, e) {
        LL v = e[i].to;
        if(v==f) continue;
        flag = 1;
        deep[v] = deep[x]+1;
        a.push_back({deep[v], v}); cnt++;
        lca_rmq(v, x);
        a.push_back({deep[x], x}); cnt++;
    }
    if(flag) {
        a.push_back({deep[x], x});
        cnt++;
    }
}

void lca_rmq_main() {
    cin>>n>>m>>s;
    Fo(i,2,n) {
        LL x, y; cin>>x>>y;
        add(x, y);
        add(y, x);
    }
    cnt = 1;
    deep[s] = 1;
    a.push_back({1, s});
    lca_rmq(s, s);
    Fo(i,1,cnt) {
        stb[i][0] = a[i-1];
    }
    Fo(j,1,21) {
        Fo(i,1,cnt) {
            stb[i][j] = calc(stb[i][j-1], stb[i+(1<<(j-1))][j-1]);
        }
    }
    Fo(i,1,m) {
        LL a, b; cin>>a>>b;
        LL l=first[a], r=first[b];
        if(l>r) swap(l, r);
        LL k = LL(log(r-l+1)/log(2));
        cout<<calc(stb[l][k], stb[r-(1<<k)+1][k]).second<<endl;
    }
}

// 最大流（最小割）

LL minn, maxx; //最小费用，最大流
LL s, t; //源点，汇点

// EK算法
LL mf_vis[maxn][maxn]; //应对重边的情况
LL dis[maxn], pre[maxn];

bool ek_bfs() {
    Ms(vis, 0);
    queue<LL> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = INT_MAX;
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        if(u==t) return 1;
        Eo(i,u,e) {
            LL v = e[i].to;
            if(vis[v]||e[i].val<=0) continue;
            dis[v] = min(dis[u], e[i].val);
            vis[v] = 1;
            pre[v] = i; // 存的i
            q.push(v);
        }
    }
    return 0;
}

void ek_update() {
    LL x = t;
    while(x!=s) {
        LL i = pre[x];
        e[i].val  -= dis[t];
        e[i^1].val += dis[t];
        x = e[i^1].to;
    }
    maxx += dis[t];
}

void ek_main() {
    cin>>n>>m>>s>>t;
    tot = 1;
    Fo(i,1,m) {
        LL x, y, z; cin>>x>>y>>z;
        if(!mf_vis[x][y]) {
            add(x, y, z);
            mf_vis[x][y] = tot;
            add(y, x, 0);
        } else {
            e[mf_vis[x][y]].val += z;
        }

    }
    while(ek_bfs()) ek_update();
    cout<<maxx;
}

// dinic算法

bool dinic_bfs() {
    Ms(vis, 0);
    queue<LL> q;
    q.push(s);
    vis[s] = 1;
    deep[s]  = 1;
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        if(u==t) return 1;
        Eo(i,u,e) {
            LL v = e[i].to;
            if(vis[v]||e[i].val<=0) continue;
            vis[v] = 1;
            deep[v] = deep[u] + 1;
            q.push(v);
        }
    }
    return 0;
}

LL dinic_dfs(LL x, LL dis) {
    if(x==t) return dis;
    LL rest = dis;
    Eo(i,x,e) {
        LL v = e[i].to;
        if(!e[i].val || deep[v]!=deep[x]+1) continue;
        LL k = dinic_dfs(v, min(rest, e[i].val));
        if(!k) deep[v] = -1;
        e[i].val -= k;
        e[i^1].val += k;
        rest -= k;
    }
    return dis-rest;
}

void dinic_main() {
    cin>>n>>m>>s>>t;
    tot = 1;
    Fo(i,1,m) {
        LL x, y, z; cin>>x>>y>>z;
        if(!mf_vis[x][y]) {
            add(x, y, z);
            mf_vis[x][y] = tot;
            add(y, x, 0);
        } else {
            e[mf_vis[x][y]].val += z;
        }
    }
    while(dinic_bfs()) {
        LL flow;
        while(flow = dinic_dfs(s, INT_MAX)) {
            maxx += flow;
        }
    }
    cout<<maxx;
}

// 最小费用最大流

// EK算法

LL len[maxn]; //费用长度，含义为spfa中的dis数组

// 重载add函数
void add(LL x, LL y, LL z, LL w) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].val = z;
    e[tot].len = w;
    head[x] = tot;
}

bool ek_spfa() {
    Ms(vis, 0); Ms(dis, 0x3f); Ms(len, 0x3f);
    len[s] = 0; dis[s] = INT_MAX; vis[s] = 1;
    queue<LL>q; q.push(s);
    bool flag = 0;
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        if(u==t) flag = 1;
        vis[u] = 0;
        Eo(i,u,e) {
            LL v = e[i].to;
            if(e[i].val>0&&len[v]>len[u]+e[i].len) {
                len[v] = len[u] + e[i].len;
                pre[v] = i;
                dis[v] = min(dis[u], e[i].val);
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return flag;
}

void ek_mcmf_update() {
    LL x = t;
    while(x!=s) {
        LL i = pre[x];
        e[i].val -= dis[t];
        e[i^1].val += dis[t];
        x = e[i^1].to;
    }
    maxx += dis[t];
    minn += dis[t]*len[t];
}

void ek_mcmf_main() {
    cin>>n>>m>>s>>t;
    tot = 1;
    Fo(i,1,m) {
        LL x, y, z, w; cin>>x>>y>>z>>w;
        if(x==y) continue;
        add(x, y, z, w);
        add(y, x, 0, -w);
    }
    while(ek_spfa()) ek_mcmf_update();
    cout<<maxx<<' '<<minn;
}

// dinic算法

bool dinic_spfa() {
    Ms(vis, 0); Ms(len, 0x3f);
    vis[s] = 1; len[s] = 0;
    queue<LL>q; q.push(s);
    bool flag = 0;
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        if(u==t) flag = 1;
        vis[u] = 0;
        Eo(i,u,e) {
            LL v = e[i].to;
            if(e[i].val>0&&len[v]>len[u]+e[i].len) {
                len[v] = len[u] + e[i].len;
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return flag;
}

LL dinic_mcmf_dfs(LL x, LL dis) {
    if(x==t) return dis;
    LL rest = dis;
    vis[x] = 1; //要有vis限制
    Eo(i,x,e) {
        LL v = e[i].to;
        if(vis[v] || !e[i].val || len[v]!=len[x]+e[i].len) continue;
        LL k = dinic_mcmf_dfs(v, min(rest, e[i].val));
        if(!k) len[v] = -1;
        e[i].val -= k;
        e[i^1].val += k;
        rest -= k;
        minn += k*e[i].len;
    }
    vis[x] = 0;
    return dis-rest;
}

void dinic_mcmf_main() {
    cin>>n>>m>>s>>t;
    tot = 1;
    Fo(i,1,m) {
        LL x, y, z, w; cin>>x>>y>>z>>w;
        if(x==y) continue;
        add(x, y, z, w);
        add(y, x, 0, -w);
    }
    while(dinic_spfa()) {
        LL flow;
        while(flow = dinic_mcmf_dfs(s, INT_MAX)) {
            maxx += flow;
        }
    }
    cout<<maxx<<' '<<minn;
}

//二分图匹配

//m一般是边的个数，匈牙利算法中是二分图右侧结点个数
LL line[maxn][maxn], match[maxn], m;

//匈牙利算法
bool xyl(LL x) {
    for(int i=1; i<=m; i++) {
        if(line[x][i]&&!vis[i]) {
            vis[i] = 1;
            if(!match[i]||xyl(match[i])) {
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

//ans是二分图最大匹配数，n是二分图左侧结点个数
void xyl_init(LL n) {
    LL ans=0;
    for(int i=1; i<=n; i++) {
        memset(vis, 0, sizeof(vis));
        if(xyl(i)) ans++;
    }
    cout<<ans;
}

//除此之外，二分图匹配也可以用dinic来做，只需要建一个超级源点和一个超级汇点，同时注意点的序号问题
//https://github.com/cls1277/OnlineJudge-Codes/commit/3a5aa72b1f937c0d6ae84e0eff1b2718fc6a2d7a

LL dfn[maxn], low[maxn], idx, cnt, color[maxn];
bool ins[maxn];//是否在栈里
stack<LL>st;
vector<LL>ed[maxn];//vector存图

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
            st.pop();
        }while(temp!=x);
    }
}

void scc_init(LL n) {
    for(int i=1; i<=n; i++)
        if(!dfn[i])
            tarjan(i);
}

//n是变量个数，2*n是因为添加了非点，可以采用i+n的形式表示!i
void twoSAT_init(LL n) {
    /*
        根据题目要求连边，如
        !a||b -> (a->b)||(!b->!a) 连边
    */
    for(int i=1; i<=2*n; i++)
        if(!dfn[i])
            tarjan(i);
    /*
        判断x和!x是否在一个强连通分量内
        如果在说明无解
        最终答案为color(i)<color(!i)
    */
    for(int i=1; i<=n; i++)
        if(color[i]==color[i+n]) {
            cout<<"IMPOSSIBLE";
            return ;
        }
    for(int i=1; i<=n; i++)
        cout<<(color[i]<color[i+n])<<" ";
}

//割点 is[i]:i是否是割点
bool is[maxn];

void tarjan_points(LL u, LL f) {
    low[u] = dfn[u] = ++idx;
    LL child = 0;
    for(int i=head[i]; i; i=e[i].next) {
        LL v=e[i].to;
        if(v==f) continue;
        if(!dfn[v]) {
            tarjan_points(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]&&u!=f&&!is[u]) {
                //yes
                is[u] = 1;
                cnt++;
            }
            if(u==f) child++;
        }
        low[u]=min(low[u],dfn[v]);
    }
    if(child>1&&u==f&&!is[u]) {
        //yes
        is[u] = 1;
        cnt++;
    }
    return ;
}

//割边
void tarjan_edge(LL u, LL f) {
    low[u] = dfn[u] = ++idx;
    for(int i=head[i]; i; i=e[i].next) {
        LL v=e[i].to;
        if(v==f) continue;
        if(!dfn[v]) {
            tarjan_edge(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]) {
                //u->v的这条边就是割边
            }
        }
        low[u]=min(low[u],dfn[v]);
    }
    return ;
}

//缩点
/*
    代码与之前类似，就不单独再写了
    还是tarjan求强连通分量的思路
    求解过程中，cnt是强连通分量的序号
    就可以在do-while的时候顺便更新缩点的新的权值
    https://github.com/cls1277/OnlineJudge-Codes/commit/017c50e9fe2cab35889996bae32ec8e0b2beb2d4
*/

struct Que {
	LL len , num;
};

bool operator < (Que a , Que b) {
	return a.len > b.len;
}

void dij(LL s) {
    for(int i=1; i<=n; i++) dis[i]=INT_MAX;
	dis[s] = 0;
	priority_queue<Que>q;
	q.push({0,s});
	while(!q.empty()) {
		Que u=q.top();
		q.pop();
		if(u.len!=dis[u.num]) continue;
		for(int i=head[u.num]; i;i=e[i].next) {
			LL v=e[i].to;
			if(dis[v]>dis[u.num]+e[i].val) {
				dis[v] = dis[u.num]+e[i].val;
				q.push({dis[v], v});
			}
		}
	}
}

void spfa(LL s) {
	for(int i=1; i<=n; i++) dis[i]=INT_MAX;
	queue<LL>q;
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while(!q.empty()) {
		LL u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i=head[u]; i; i=e[i].next) {
			LL v = e[i].to;
			if(dis[v]>dis[u]+e[i].val) {
				dis[v] = dis[u]+e[i].val;
				if(!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			} 
		} 
	}
}

//sum[]存强连通分量的值
LL ind[maxn], sum[maxn];

LL topo() {
    LL ans = 0;
    struct Node {
        LL id, sum;
    };
    queue<Node>q;
    for(int i=1; i<=cnt; i++)
        if(!ind[i])
            q.push({i,sum[i]});
    while(!q.empty()) {
        Node u=q.front(); q.pop();
        ans = max(ans, u.sum);
        for(LL i=0; i<ed[u.id].size(); i++) {
            LL v=ed[u.id][i];
            ind[v]--;
            if(!ind[v]) 
                q.push({v,u.sum+sum[v]});
        }
    }
    return ans;
}

void prim() {
    struct Node {
        LL to , next , val;
        bool operator < (const Node &a) const {
            return val>a.val;
        } 
    };
    Node e[maxn<<1];
    priority_queue<Node>q;
    LL ans = 0;
	dis[1] = 0; cnt = 0;
    memset(vis, 0, sizeof(vis));
	q.push(Node{1 , 1 , 0});
	while(!q.empty()&&cnt<n) {
		Node u = q.top();
		q.pop();
		if(vis[u.to]) continue;
		vis[u.to] = 1;
		ans+=u.val;
		cnt++;
		for(int i=head[u.to]; i; i=e[i].next)
			if(dis[e[i].to]>e[i].val) {
				dis[e[i].to] = e[i].val;
				q.push(Node{e[i].to , e[i].to , e[i].val});
			}
	}
}