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
string str[155];
struct Tree {
	int fail , vis[26] , end;
};
Tree tree[maxn];
int cnt , n;
struct Answer {
	int cnt , pos;
};
Answer ans[maxn];

bool operator < (Answer a , Answer b) {
	if(a.cnt==b.cnt) return a.pos<b.pos;
	return a.cnt>b.cnt;
}

void init() {
	Ms(tree,0);
	cnt=0;
	Ms(ans,0);
	return ;
}

void build(string s , int num) {
	int len = s.length()-1 , now=0;
	Fo(i,0,len) {
		if(!tree[now].vis[s[i]-'a'])
			tree[now].vis[s[i]-'a'] = ++cnt;
		now = tree[now].vis[s[i]-'a'];
	}
	tree[now].end = num;
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
		for(int j=now;j;j=tree[j].fail) ans[tree[j].end].cnt++;
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	while(1) {
		cin>>n;
		if(!n) break;
		init();
		Fo(i,1,n) {
			cin>>str[i];
			ans[i].pos=i;
			build(str[i],i);
		}
		Fail();
		cin>>str[0];
		query(str[0]);
		sort(ans+1,ans+n+1);
		cout<<ans[1].cnt<<endl;
		cout<<str[ans[1].pos]<<endl;
		Fo(i,2,n) {
			if(ans[i].cnt==ans[1].cnt)
				cout<<str[ans[i].pos]<<endl;
			else break;
		}
	} 
	return 0;
}

