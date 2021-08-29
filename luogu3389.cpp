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
#define eps 1e-9
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

const LL maxn = 105;
LL n;
double a[maxn][maxn];

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n;
	Fo(i,1,n)
		Fo(j,1,n+1)
			cin>>a[i][j];
	Fo(i,1,n) {
		LL maxx = i;
		Fo(j,i+1,n)
			if(fabs(a[j][i])>fabs(a[maxx][i]))
				maxx = j;
		if(fabs(a[maxx][i])<eps) {
			cout<<"No Solution";
			return 0;
		}
		Fo(j,1,n+1) swap(a[maxx][j],a[i][j]);
		Fo(j,1,n) {
			if(i==j) continue;
			double tmp = a[j][i]/a[i][i];
			Fo(k,i+1,n+1) a[j][k]-=a[i][k]*tmp;
		}
	}
	Fo(i,1,n) printf("%.2lf\n",a[i][n+1]/a[i][i]);
	return 0;
}

