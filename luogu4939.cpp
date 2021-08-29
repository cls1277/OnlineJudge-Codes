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

LL n , m , c[4*10000005];

void add(LL x , LL y) {
	while(x<=n) {
		c[x]+=y;
		x+=lowbit(x);
	}
}

void query(LL x) {
	LL ans = 0;
	while(x) {
		ans+=c[x];
		x-=lowbit(x);
	}
	cout<<ans<<endl;
} 

int main() {
//	freopen("data.txt","r",stdin);
	n=read(); m=read();
	Fo(i,1,m) {
		LL k , a , b;
		k=read();
		if(k==0) {
			a=read(); b=read();
			add(a , 1);
			add(b+1 , -1);
		} else {
			a=read();
			query(a);
		}
	}
	return 0;
}

