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

LL s , v , ans;

int main() {
//	freopen("data.txt","r",stdin);
	s=read(); v=read();
	ans = ceil(s*1.0/v)+10;
	if(ans/60>7) {
		if(60-ans%60>=10)
			cout<<24-ans/60+7<<":"<<60-ans%60;
		else
			cout<<24-ans/60+7<<":0"<<60-ans%60;
	} else {
		if(60-ans%60>=10)
			cout<<"0"<<7-ans/60<<":"<<60-ans%60;
		else
			cout<<"0"<<7-ans/60<<":0"<<60-ans%60;		
	}
	return 0;
}
