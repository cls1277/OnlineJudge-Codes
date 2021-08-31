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
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

#define MAXN 100005
LL n , m , sum1[MAXN] , sum2[MAXN];

LL add(LL x , LL y) {
	LL p=x;
	while(x<=n) {
		sum1[x]+=y;
		sum2[x]+=p*y;
		x+=lowbit(x);
	}
}

LL sum(LL x) {
	LL p = x , ans = 0;
	while(x) {
		ans+=sum1[x]*(p+1)-sum2[x];
		x-=lowbit(x);
	}
	return ans;
}

void query(LL l , LL r) {
	printf("%lld\n",sum(r)-sum(l-1));
}

int main() {
//	freopen("data.txt","r",stdin);
	n=read(); m=read();
	Fo(i,1,m) {	
		char k;
		LL x , y;
		cin>>k; x=read(); y=read();
		if(k=='x') {
			add(x,y);
			add(x+1,-y);
		} else {
			query(x,y);
		}
	}
	return 0;
}

