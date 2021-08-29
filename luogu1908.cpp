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

#define MAXN 500005
struct Node {
	LL data , id;
	bool operator < (const Node &a) {
		if(data==a.data)
			return id<a.id; 
		return data<a.data;
	}
};
LL n , b[MAXN] , ans , c[4*MAXN];
Node a[MAXN]; 

/*bool cmp(Node t , Node tt) {
	if(t.data==tt.data)
		return t.id<tt.id;
	return t.data<tt.data;
}*/

void add(LL x , LL y) {
	while(x<=n) {
		c[x]+=y;
		x+=lowbit(x);
	}
}

LL sum(LL x) {
	LL cnt = 0;
	while(x) {
		cnt+=c[x];
		x-=lowbit(x);
	}
	return cnt;
}

int main() {
//	freopen("data.txt","r",stdin);
	n=read();
	Fo(i,1,n) {
		a[i].data=read();
		a[i].id = i;
	}
	sort(a+1 , a+n+1);
	Fo(i,1,n)
		b[a[i].id] = i;
	Fo(i,1,n) {
		add(b[i],1);
		ans+=i-sum(b[i]);
	}
	printf("%lld",ans);
	return 0;
}

