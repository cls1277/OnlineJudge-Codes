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

struct Tree {
	int son[2],cnt,end;
};
Tree tree[500005];
int n , m , num;

void insert(string s) {
	int len=s.length()-1 , u=0;
	Fo(i,0,len) {
		int v=s[i]-'0';
		if(!tree[u].son[v]) tree[u].son[v]=++num;
		u = tree[u].son[v];
		tree[u].cnt++;
	}
	tree[u].end++;
	return ;
}

int find(string s) { 
	int len=s.length()-1 , u=0 , ans=0;
	Fo(i,0,len) {
		int v=s[i]-'0';
		if(!tree[u].son[v]) return ans;
		u = tree[u].son[v];
		ans+=tree[u].end;
	}
	return ans-tree[u].end+tree[u].cnt;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>m>>n;
	Fo(i,1,m) {
		int x; cin>>x;
		string y="";
		Fo(j,1,x) {
			char z; cin>>z;
			y+=z;
		}
		insert(y);
	}
	Fo(i,1,n) {
		int x; cin>>x;
		string y="";
		Fo(j,1,x) {
			char z; cin>>z;
			y+=z;
		}
		cout<<find(y)<<endl;
	}
	return 0;
}

