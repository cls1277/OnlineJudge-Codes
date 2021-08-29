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

//const LL maxn = ;
int n , ans;

string int2str(int x) {
	stringstream ss; string str;
	ss<<x;
	ss>>str;
	return str;
}

int str2int(string x) {
	stringstream ss; int res;
	ss<<x;
	ss>>res;
	return res;
}

void dfs(int x) {
	ans++; string tmp , str;
	str=int2str(x);
	for(int i=1; i<=x*1.0/2; i++) {
		tmp=int2str(i);
		dfs(str2int(tmp+str));
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n;
	dfs(n);
	cout<<ans;
	return 0;
}

