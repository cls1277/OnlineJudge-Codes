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

string s;

int main() {
//	freopen("data.txt","r",stdin);
	cin>>s;
	Fo(i,0,s.length()-1)
		if(s[i]!='A'&&s[i]!='C'&&s[i]!='M'&&s[i]!='B'&&s[i]!='R'&&s[i]!='I'&&s[i]!='D'&&s[i]!='G'&&s[i]!='E')
			cout<<s[i];
	return 0;
}
