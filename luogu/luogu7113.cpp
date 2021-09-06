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
typedef __int128 LL;
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

const int maxn = 1e5+5;
int n , m , sz[maxn] , head[maxn] , tot , ind[maxn];
queue<int>q;
vector<int>ch;

LL gcd(LL x , LL y) {
	return y?gcd(y,x%y):x;
}

LL lcm(LL x , LL y) {
	return x/gcd(x,y)*y;
}

struct Frac {
	LL fz , fm;
	Frac() {
		fz=0 , fm=1;
	}
	Frac operator * (const LL &x) const {
		Frac temp;
		temp.fz=fz; temp.fm=fm*x;
		LL g = gcd(temp.fz , temp.fm);
		temp.fz/=g; temp.fm/=g;
		return temp;
	}
	Frac operator + (const Frac &x) const {
		Frac temp; temp.fm=lcm(fm,x.fm);
		temp.fz = fz*(temp.fm/fm) + x.fz*(temp.fm/x.fm);
		LL g = gcd(temp.fz , temp.fm);
		temp.fz/=g; temp.fm/=g;
		return temp;
	}
};
struct Seg {
	int to , next;
};
Frac ans[maxn];
Seg e[5*maxn];

void add(int x , int y) {
	tot++;
	e[tot].next = head[x];
	e[tot].to = y;
	head[x] = tot;
	ind[y]++;
	return ;
}

void topo() {
	Fo(i,1,n)
		if(!ind[i]) {
			q.push(i);
			ans[i].fz=ans[i].fm=1;
		}
	while(!q.empty()) {
		int u=q.front(); q.pop();
		if(!sz[u]) continue;
		ans[u]=ans[u]*sz[u];
		Eo(i,u,e) {
			int v=e[i].to;
			ans[v]=ans[v]+ans[u];
			ind[v]--;
			if(!ind[v]) q.push(v);
		}
	}
	return ;
}

void print(LL x) {
	if(x>9) print(x/10);
    putchar(x%10+48);
    return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m;
	Fo(i,1,n) {
		cin>>sz[i];
		if(!sz[i]) ch.push_back(i);
		Fo(j,1,sz[i]) {
			int y; cin>>y;
			add(i , y);
		}
	}
	topo();
	for(int i=0; i<ch.size(); i++) {
		print(ans[ch[i]].fz);
		putchar(' ');
		print(ans[ch[i]].fm);
		putchar('\n');
	}
	return 0;
}

