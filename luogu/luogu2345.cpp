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

#define MAXN 20005
struct Node {
	LL x , v;
	bool operator < (const Node &a) const {
		return v<a.v;
	}
};
Node a[MAXN];
LL n , ans;
LL c1[4*MAXN] , c2[4*MAXN];

void add1(LL x) {
	while(x<=20000) {
		c1[x]++;
		x+=lowbit(x);
	}
}

LL sum1(LL x) {
	LL cnt = 0;
	while(x) {
		cnt+=c1[x];
		x-=lowbit(x);
	}
	return cnt;
}

void add2(LL x , LL y) {
	while(x<=20000) {
		c2[x]+=y;
		x+=lowbit(x);
	}
}

LL sum2(LL x) {
	LL cnt = 0;
	while(x) {
		cnt+=c2[x];
		x-=lowbit(x);
	}
	return cnt;
}

int main() {
//	freopen("data.txt","r",stdin);
	n=read();
	Fo(i,1,n) {
		a[i].v=read();
		a[i].x=read();
	}
	sort(a+1,a+n+1);
	Fo(i,1,n) {
		LL t = a[i].x;
		ans+=a[i].v*(sum1(t-1)*t-sum2(t-1)-(sum1(20000)-sum1(t))*t+sum2(20000)-sum2(t));
	//	cout<<ans<<endl;
		add1(t);
		add2(t,t);
	} 
	printf("%lld",ans);
	return 0;
}

