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
int maxx , sum , n;
string name;

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n;
	Fo(i,1,n) {
		string x; int y , z; char r , q; int p; int res=0;
		cin>>x>>y>>z>>r>>q>>p;
		//cout<<x<<endl;
		if(y>80&&p>=1) res+=8000;
		if(y>85&&z>80) res+=4000;
		if(y>90)	res+=2000;
		if(y>85&&q=='Y') res+=1000;
		if(z>80&&r=='Y') res+=850;
		if(res>maxx) {
			name = x;
			maxx = res;
		}
		sum+=res;
	}
	cout<<name<<endl<<maxx<<endl<<sum;
	return 0;
}

