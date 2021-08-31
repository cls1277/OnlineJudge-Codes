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

const LL maxn = 5e5+5;
int n , num , m;
struct Trie {
	int son[27];
	bool flag , rep;
};
Trie tree[maxn];

void insert(string s) {
	int len=s.length()-1 , u=0;
	Fo(i,0,len) {
		int v=s[i]-'a';
		if(!tree[u].son[v]) tree[u].son[v]=++num;
		u = tree[u].son[v]; 
	}
	tree[u].flag = true;
	return ;
}

int find(string s) {
	int len=s.length()-1 , u=0;
	Fo(i,0,len) {
		int v=s[i]-'a';
		if(!tree[u].son[v]) return 3;
		u = tree[u].son[v];
	}
	if(!tree[u].flag) return 3;
	if(!tree[u].rep) {
		tree[u].rep = true;
		return 1;
	}
	return 2;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n;
	Fo(i,1,n) {
		string str; cin>>str;
		insert(str);
	}
	cin>>m;
	Fo(i,1,m) {
		string str; cin>>str;
		int op = find(str);
		if(op==1) cout<<"OK"<<endl;
		if(op==2) cout<<"REPEAT"<<endl;
		if(op==3) cout<<"WRONG"<<endl;
	}
	return 0;
}

