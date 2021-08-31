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

#define MAXN 200005
LL n , m , a[MAXN] , sum1[4*MAXN] , sum2[4*MAXN]; 

void add(LL x , LL y) {
	LL t = x;
	while(x<=n) {
		sum1[x]+=y;
		sum2[x]+=t*y;
		x+=lowbit(x);
	}
}

LL sum(LL x) {
	LL ans = 0 , t = x;
	while(x) {
		ans+=(t+1)*sum1[x]-sum2[x];
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
//	Fo(i,1,n) a[i]=read();
	Fo(i,1,n) {
		LL t = read();
		add(i,t);
		add(i+1,-t);
	}
	Fo(i,1,m) {
		LL k , x , y, z;
		k=read();
		if(k==1) {
			x=read(); y=read(); z=read();
			add(x,z);
			add(y+1,-z);
		}
		if(k==2) {
			x=read();
			add(1,x);
			add(2,-x);
		}
		if(k==3) {
			x=read();
			add(1,-x);
			add(2,x);
		}
		if(k==4) {
			x=read(); y=read();
			query(x,y);
		}
		if(k==5) {
			query(1,1);
		}
	}
	return 0;
}

