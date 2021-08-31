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

LL n , cnt[30]; 
string s;
/*M 12
C 2
O 14
I 8*/

int main() {
//	freopen("data.txt","r",stdin);
	n=read();
	Fo(i,1,n) {
		cin>>s;
		cnt[s[0]-'A']++;
	}
	printf("%lld",cnt[12]*cnt[2]*cnt[14]+cnt[12]*cnt[2]*cnt[8]+cnt[2]*cnt[14]*cnt[8]+cnt[12]*cnt[14]*cnt[8]);
	return 0;
}
