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

const int maxn = 105;
int n; 

struct Num {
	int len , a[maxn];
	Num() {
		memset(a,0,sizeof(a));
		len = 1;
	}
	Num operator = (const char *x) {
		len = strlen(x);
		for(int i=0; i<len; i++) a[i]=x[len-i-1]-'0';
		return *this;
	}
	Num operator = (const int num) {
		char x[maxn];
		sprintf(x,"%d",num);
		*this=a;
		return *this;
	}
	Num(const char *x) {
		*this = x;
	}
	Num operator + (const Num &x) {
		Num y;
		y.len=max(len,x.len)+1;
		for(int i=0; i<y.len; i++) {
			y.a[i]=a[i]+x.a[i]+
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n;
	
	return 0;
}

