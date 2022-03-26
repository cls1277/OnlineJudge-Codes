//By cls1277 , learn from ECNU
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>

using std::cout;
using std::swap;
using std::memset;
using std::queue;
using std::min;
using std::max;
using std::stack;
using std::vector;
using std::priority_queue;

typedef long long LL;
#define INF 2147483647

const int maxn = 1e3+5;

//根据实际情况决定是否添加val，比如mcmf就需要添加
struct Edge {
    LL to , next , len, val;
}e[maxn<<1];

LL tot, head[maxn];
LL n;//n是点的个数

void add(LL x, LL y, LL z) {
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
    LL ans = INF;
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=20; i; i--) {
        if(deep[fa[x][i]]>=deep[y]) {
            ans = min(ans, wt[x][i]);
            x = fa[x][i];
        }
        if(x==y) return ans;
    }
    for(int i=20; i; i--) {
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
            dfs(i,0,INF);
        }
    }
    for(int i=1; i<=20; i++) {
        for(int j=1; j<=n; j++) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
            wt[j][i] = min(wt[j][i-1], wt[fa[j][i-1]][i-1]);
        }
    }
}

LL dis[maxn], pre[maxn];

bool dinic_bfs(LL n) {
    bool vis[maxn]; memset(vis, 0, sizeof(vis));
    vis[1]=1;
    queue<LL>q;
    q.push(1);
    dis[1]=INF;
    while(!q.empty()) {
        LL u=q.front();
        if(u==n) return 1;
        q.pop();
        for(int i=head[u]; i; i=e[i].next) {
            LL v=e[i].to;
            if(e[i].len<=0||vis[v]) continue;
            vis[v] = 1;
            q.push(v);
            pre[v] = i;
            dis[v] = min(dis[u] , e[i].len);
        }
    }
    return 0;
}

void dinic_dfs(LL n, LL &ans) {
    LL x=n;
    while(x!=1) {
        LL p=pre[x];
        e[p].len-=dis[n];
        e[p^1].len+=dis[n];
        x=e[p^1].to;
    }
    ans+=dis[n];
    return ;
}

//tot一定要等于1
void dinic_init(LL n) {
    LL ans = 0;
    tot = 1;
    /*
        //给点x和点y之间加一条流量为z的边：
        add(x, y, z);
        add(y, x, 0);
    */
   while(dinic_bfs(n)) {
       dinic_dfs(n, ans);
   }
}

//val是花费数组，mc最小费用，mf最大流量
//s源点，t汇点
LL mc, mf, val[maxn], s, t;

bool mcmf_spfa() {
    bool flag=false;
    bool vis[maxn];
    memset(vis, 0, sizeof(vis));
    memset(val, 0xfffffff, sizeof(val));
    val[s]=0;
    vis[s]=1; dis[s]=INF;
    queue<LL>q;
    q.push(s);
    while(!q.empty()) {
        LL u=q.front();
        q.pop();
        if(u==t) flag=true;
        vis[u] = 0;
        for(int i=head[u]; i; i=e[i].next) {
            LL v=e[i].to;
            if(e[i].len>0&&val[v]>val[u]+e[i].val) {
                val[v] = val[u]+e[i].val;
                pre[v] = i;
                dis[v] = min(dis[u], e[i].len);
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return flag;
}

void mcmf_dfs() {
    LL x=t;
    while(x!=s) {
        LL p=pre[x];
        e[p].len-=dis[t];
        e[p^1].len+=dis[t];
        x=e[p^1].to;
    }
    mf += dis[t];
    mc += dis[t]*val[t];
    return ;
}

void mcmf_init() {
    /*
        //给点x和点y之间加一条流量为z花费为v的边：
        add(x, y, z, v);
        add(y, x, 0, -v);
    */
   while(mcmf_spfa()) {
       mcmf_dfs();
   }
}

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
    for(int i=1; i<=n; i++) dis[i]=INF;
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
	for(int i=1; i<=n; i++) dis[i]=INF;
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