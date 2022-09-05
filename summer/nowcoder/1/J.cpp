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
const LL maxm = 5e5+5;

LL n, sz[maxn], ind[maxn];
LL dfn[maxn], low[maxn], idx, cnt, color[maxn], vis[maxn];
bool ins[maxn];//是否在栈里
stack<LL>st;
vector<LL>ed[maxn], e[maxn], son[maxn];//vector存图
queue<pair<LL, LL>> q;

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
            son[cnt].push_back(temp);
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
    LL t; cin>>t;
    Fo(tt, 1, t) {
        cin>>n;
        idx = 0;
        cnt = 0;
        while(!st.empty()) st.pop();
        Fo(i,1,n) {
            sz[i] = 0;
            low[i] = 0;
            ind[i] = 0;
            ins[i] = false;
            vis[i] = 0;
            dfn[i] = 0;
            ed[i].clear();
            e[i].clear();
            son[i].clear();
        }
        Fo(i,1,n) {
            LL x; cin>>x;
            Fo(j,1,x) {
                LL y; cin>>y;
                ed[y].push_back(i);
            }
        }
        Fo(i,1,n)
            if(!dfn[i])
                tarjan(i);
        Fo(i,1,cnt) {
        	set<LL> s;
        	for(auto u:son[i]) {
         		for(auto v:ed[u]) {
        			if(sz[color[v]]>1||color[u]==color[v]||s.count(color[v])) continue;
        			s.insert(color[v]);
        			e[color[u]].push_back(color[v]);
        			ind[color[v]]++;
				}
			}
		}
        LL ans = 1;
        Fo(i,1,cnt) {
        	if(!ind[i]) {
        		q.push({i, sz[i]});
                vis[i] = i;
        		while(!q.empty()) {
        			pair<LL, LL> u=q.front(); q.pop();
                    ans = max(ans, u.second);
        			for(auto v:e[u.first]) {
        				if(vis[v]&&vis[v]!=i) continue;
        				ind[v]--; vis[v] = i;
        				if(!ind[v]) q.push({v, u.second+1});     					
					}
				}
			}
		}
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
    return 0;
}
