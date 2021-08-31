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
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

LL n , m , ans;

int main() {
//	freopen("data.txt","r",stdin);
	n=read(); m=read();
	Fo(i,1,n) {
		LL minn = INF , maxx = 0 , cnt = 0;
		Fo(j,1,m) {
			LL temp = read();
			minn = min(minn , temp);
			maxx = max(maxx , temp);
			cnt += temp;
		}
		ans = max(ans , cnt-minn-maxx);
	}
	printf("%.2f",ans*1.0/(m-2));
	return 0;
}
