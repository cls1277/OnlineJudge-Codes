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

const int maxn = 35;
int n , m , ans , f[maxn][maxn];

int dfs(int x , int y) {
	if(f[x][y]) return f[x][y];
	if(y==m) {
		if(x==1) return 1;
		return 0;
	}
	int tmp;
	tmp=(x==1)?n:(x-1);
	f[tmp][y+1]=dfs(tmp,y+1);
	f[x][y] += f[tmp][y+1];
	tmp=(x==n)?1:(x+1);
	f[tmp][y+1]=dfs(tmp,y+1);
	f[x][y] += f[tmp][y+1];
	return f[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m;
	cout<<dfs(1,0);
	return 0;
}

