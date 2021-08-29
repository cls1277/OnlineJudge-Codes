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

const LL maxn = 1e6+5;
int n , num=1;
struct Trie {
	int son[27] , flag , fail;
};
Trie tree[maxn];
queue<int>q;

void insert(string s) {
	int len=s.length()-1 , u=1;
	Fo(i,0,len) {
		int v=s[i]-'a';
		if(!tree[u].son[v]) tree[u].son[v]=++num;
		u = tree[u].son[v];
	}
	tree[u].flag++;
	return ;
}

void Fail() {
	Fo(i,0,25) tree[0].son[i]=1;
	q.push(1); tree[1].fail=0;
	while(!q.empty()) {
		int u=q.front(); q.pop();
		Fo(i,0,25) {
			int v=tree[u].son[i] , f=tree[u].fail;
			if(!v) {
				tree[u].son[i] = tree[f].son[i];
				continue;
			}
			tree[v].fail = tree[f].son[i];
			q.push(v);
		}
	}
	return ;
}

int query(string s) {
	int len=s.length()-1 , u=1 , ans=0;
	Fo(i,0,len) {
		int v=s[i]-'a' , k=tree[u].son[v];
		while(k>1&&tree[k].flag!=-1) {
			ans+=tree[k].flag;
			tree[k].flag = -1;
			k = tree[k].fail;
		} 
		u = tree[u].son[v];
	}
	return ans;
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
	Fail();
	string ss; cin>>ss;
	cout<<query(ss);
	return 0;
}

