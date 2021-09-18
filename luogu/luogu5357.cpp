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

const LL maxn = 2e5+5;
string str[maxn];
struct Tree {
	int fail , vis[26] , end , ans;
};
Tree tree[maxn];
int cnt , n , Map[maxn] , ans[maxn] , in[maxn];

void build(string s , int num) {
	int len = s.length()-1 , now=0;
	Fo(i,0,len) {
		if(!tree[now].vis[s[i]-'a'])
			tree[now].vis[s[i]-'a'] = ++cnt;
		now = tree[now].vis[s[i]-'a'];
	}
	if(!tree[now].end)
		tree[now].end = num;
	Map[num] = tree[now].end;
	return ;
}

void Fail() {
	queue<int>q;
	Fo(i,0,25)
		if(tree[0].vis[i]) {
			tree[tree[0].vis[i]].fail = 0;
			q.push(tree[0].vis[i]);
		}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		Fo(i,0,25) {
			if(tree[u].vis[i]) {
				tree[tree[u].vis[i]].fail = tree[tree[u].fail].vis[i];
				in[tree[tree[u].vis[i]].fail]++;
				q.push(tree[u].vis[i]);
			} else tree[u].vis[i] = tree[tree[u].fail].vis[i];
		}
	}
	return ;
}

void query(string s) {
	int len = s.length()-1 , now=0;
	Fo(i,0,len) {
		now = tree[now].vis[s[i]-'a'];
		tree[now].ans++;
	}
	return ;
}

void topo() {
	queue<int>q;
	Fo(i,1,cnt)
		if(!in[i])
			q.push(i);
	while(!q.empty()) {
		int u=q.front(); q.pop(); ans[tree[u].end] = tree[u].ans;
		int v = tree[u].fail; in[v]--;
		tree[v].ans+=tree[u].ans;
		if(!in[v]) q.push(v);
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
		cin>>str[i];
		build(str[i],i);
	}
	Fail();
	cin>>str[0];
	query(str[0]);
	topo();
	Fo(i,1,n) cout<<ans[Map[i]]<<endl;
	return 0;
}

