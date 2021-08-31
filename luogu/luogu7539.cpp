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

LL a[10] , flag1;

int main() {
//	freopen("data.txt","r",stdin);
	Fo(i,1,8)
		a[i]=read();
	if(a[2]>a[1])
		flag1 = 1;
	if(flag1) {
		Fo(i,3,8)
			if(a[i]<a[i-1]) {
				cout<<"mixed";
				return 0;
			}
		cout<<"ascending";
	} else {
		Fo(i,3,8)
			if(a[i]>a[i-1]) {
				cout<<"mixed";
				return 0;
			}
		cout<<"descending";		
	}
	return 0;
}
