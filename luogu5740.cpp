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

string s , st;
LL a , b , c;
LL n;

int main() {
//	freopen("data.txt","r",stdin);
	n=read();
	cin>>s>>a>>b>>c;
	Fo(i,2,n) {
		LL at ,bt , ct;
		cin>>st>>at>>bt>>ct;
		if(at+bt+ct>a+b+c) {
			s = st;
			a = at;
			b = bt;
			c = ct;
		}
	}
	cout<<s<<" "<<a<<" "<<b<<" "<<c;
	return 0;
}
