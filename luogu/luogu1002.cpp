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

const int maxn = 25;
pair<int,int>s,t;
int ans;

#define mk(_,__) make_pair(_,__)
bool jud(pair<int,int> r) {
	if(r==s) return true;
	int x=r.first , y=r.second;
	if((mk(x+1,y+2)==s)||(mk(x+1,y-2)==s)||(mk(x+2,y+1)==s)||(mk(x+2,y-1)==s)||(mk(x-1,y+2)==s)||(mk(x-1,y-2)==s)||(mk(x-2,y+1)==s)||(mk(x-2,y-1)==s))
		return true;
	return false;
}
#undef mk(_,__)

void dfs(pair<int,int> x) {
	if(x==t) {
		ans++;
		return ;
	}
	//cout<<x.first<<" "<<x.second<<endl;
	if(x.first+1<=t.first&&!jud(make_pair(x.first+1,x.second)))
		dfs(make_pair(x.first+1,x.second));
	if(x.second+1<=t.second&&!jud(make_pair(x.first,x.second+1)))
		dfs(make_pair(x.first,x.second+1));
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>t.first>>t.second>>s.first>>s.second;
	dfs(make_pair(0,0));
	cout<<ans;
	return 0;
}

