//By cls1277
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
#include<sstream>
#include<set>
#include<cassert>
#include<bitset>
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
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const LL maxn = 105;
int n;
vector<int>g[maxn];
int dfn[maxn] , low[maxn] , idx , scc , inst[maxn];
int ind[maxn] , chd[maxn] , ans1 , ans2;
stack<int>st;

void tarjan(int u) {
	low[u] = dfn[u] = ++idx;
	st.push(u);
	for(int i=0; i<g[u].size(); i++) {
		int v = g[u][i];
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u] , low[v]);
		}
		else if(!inst[v]) {
			low[u] = min(low[u] , dfn[v]);
		}
	}
	if(low[u]==dfn[u]) {
		scc++;
		while(1) {
			int x=st.top();
			st.pop();
			inst[x] = scc;
			if(x==u) break;
		}
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n;
	Fo(i,1,n) {
		int x;
		while(cin>>x&&x) {
			g[i].push_back(x);
		}
	}
	Fo(i,1,n)
		if(!dfn[i])
			tarjan(i);
	Fo(i,1,n)
		for(int j=0; j<g[i].size(); j++) {
			int v = g[i][j];
			if(inst[i]!=inst[v]) {
				chd[inst[i]]++;
				ind[inst[v]]++;
			}
		}
	Fo(i,1,scc) {
		if(!chd[i]) ans1++;
		if(!ind[i]) ans2++;
	}
	cout<<ans2<<endl<<((scc==1)?0:max(ans1,ans2));
	return 0;
}

