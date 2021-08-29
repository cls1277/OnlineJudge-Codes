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
int a , n , m , x , c , ans;

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>a>>n>>m>>x;
	Fo(i,0,20000) {
		int s1=a , s2=i , s3=0; c=s1;
		Fo(j,3,n-1) {
			int tmp=s2;
			s3=tmp;
			c+=s1+s2-s3;
			s2=s1+s2;
			s1=tmp;
			if(j==x) ans=c;
		}
		if(c==m) {
			cout<<ans;
			return 0;
		}
	}
	return 0;
}

