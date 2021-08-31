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

struct Node {
	LL data , id;
	bool operator < (const Node &a) const {
		if(data==a.data)
			return id<a.id;
		return data<a.data;
	}
};
#define MAXN 100005
Node a[MAXN];
LL n , ans;

int main() {
//	freopen("data.txt","r",stdin);
	n=read();
	Fo(i,1,n) {
		a[i].data = read();
		a[i].id = i;
	}
	sort(a+1 , a+n+1);
	Fo(i,1,n)
		ans = max(ans , a[i].id-i);
	cout<<ans+1;
	return 0;
}

