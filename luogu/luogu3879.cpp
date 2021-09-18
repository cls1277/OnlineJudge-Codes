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
	int son[26];
	bool flag;
};
Tree tree[105][50005];
int n , m , num;

void insert(int x , string s) {
	int len=s.length()-1 , u=0;
	Fo(i,0,len) {
		int v=s[i]-'a';
		if(!tree[x][u].son[v]) tree[x][u].son[v]=++num;
		u = tree[x][u].son[v];
	}
	tree[x][u].flag=true;
	return ;
}

int find(int x , string s) { 
	int len=s.length()-1 , u=0;
	Fo(i,0,len) {
		int v=s[i]-'a';
		if(!tree[x][u].son[v]) return 0;
		u = tree[x][u].son[v];
	}
	if(!tree[x][u].flag) return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n;
	Fo(i,1,n) {
		int x; cin>>x;
		Fo(j,1,x) {
			string y;
			cin>>y;
			insert(i,y);
		}
	}
	cin>>m;
	Fo(i,1,m) {
		string str; cin>>str;
		Fo(j,1,n)
			if(find(j,str))
				cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}

