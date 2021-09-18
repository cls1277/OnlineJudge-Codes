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

const LL maxn = 1e12;
string str; 
char b[3]={'B','S','C'};
map<char,LL>used;
map<char,LL>has;
map<char,LL>cost;
LL a;

bool jud(LL x) {
	LL sum=0;
	Fo(i,0,2) {
		int tmp=has[b[i]] , temp=used[b[i]];
		if(has[b[i]]<x*used[b[i]])
			sum+=cost[b[i]]*(x*used[b[i]]-has[b[i]]);
	}
	return a>=sum;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>str;
	for(int i=0; i<str.length(); i++) used[str[i]]++;
	Fo(i,0,2) cin>>has[b[i]];
	Fo(i,0,2) cin>>cost[b[i]];	
	cin>>a;
	LL l=0 , r=maxn , mid;
	while(l<r) {
		mid = (l+r+1)>>1;
		if(jud(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}

