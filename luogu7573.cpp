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
#define L 100005
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define _ceil(_,__) (_+(__-1))/__
#define debug(_) cout<<endl<<"d::"<<_<<endl<<endl
#define type(_) typeid(_).name()
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

LL T , n;

int main() {
//	freopen("data.txt","r",stdin);
	T=read();
	Fo(i,1,T) {
		n=read();
        if(n==1) {
            printf("0\n");
            continue;
        }
		if(n%2==0)
			printf("%lld\n",n/2);
		else
			printf("%lld\n",(n+1)/2);
	}
	return 0;
}
