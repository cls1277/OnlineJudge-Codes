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

LL T; 

int main() {
//	freopen("data.txt","r",stdin);
	T=read();
	while(T--) {
		LL x , y , k;
		x=read(); y=read(); k=read();
		if(x==0||y==0) {
			if((x==0&&y!=0&&k%y==0)||(x!=0&&y==0&&k%x==0))
				cout<<"1"<<endl;
			else
				cout<<"0"<<endl;
		}
		else
		//	printf("%lld\n",min(floor(k/x),floor(k/y)));
			cout<<min(k/x,k/y)<<endl;
	}
	return 0;
}
