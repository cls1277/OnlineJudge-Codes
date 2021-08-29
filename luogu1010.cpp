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
const int two[15]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
int n , vis[17000];

void dfs(int x) {
	if(x==0) {
		cout<<x;
		return ;
	}
	Ro(i,14,0) {
		if(x<two[i]) continue;
		if(i==1) {
			cout<<"2";
			x-=two[i];
			if(x) cout<<"+";
			continue;
		}
		cout<<"2(";
		dfs(i);
		x-=two[i];
		cout<<")";
		if(x) cout<<"+";
	}
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	Fo(i,0,14) vis[two[i]]=i;
	cin>>n;
	dfs(n);
	return 0;
}

