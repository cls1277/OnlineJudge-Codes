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

const LL maxn = 1005;
pair<int,int>a[maxn];
bitset<maxn>vis[maxn];
int n , d , fa[maxn] , p , q , ok[maxn];
char op;

int find(int x) {
	if(fa[x]!=x)
		fa[x] = find(fa[x]);
	return fa[x];
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>d;
	Fo(i,1,n) cin>>a[i].first>>a[i].second;
	Fo(i,1,n)
		Fo(j,i+1,n)
			if((a[i].first-a[j].first)*(a[i].first-a[j].first)+(a[i].second-a[j].second)*(a[i].second-a[j].second)<=d*d)
				vis[i][j] = vis[j][i] = 1;
	Fo(i,1,n) fa[i]=i;
	while(cin>>op) {
		if(op=='O') {
			cin>>p;
			if(ok[p]) continue;
			ok[p] = 1;
			Fo(i,1,n) {
				if(i==p||(!vis[p][i])||(!ok[i])) continue;
				int f1=find(p) , f2=find(i);
				if(f1!=f2) fa[f1]=f2;
			}
		} else {
			cin>>p>>q;
			int f1=find(p) , f2=find(q);
			if(f1!=f2) cout<<"FAIL"<<endl;
			else cout<<"SUCCESS"<<endl;
		}
	}
	return 0;
}

