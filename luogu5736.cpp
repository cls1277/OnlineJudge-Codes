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

#define MAXN 100005
LL vis[MAXN];
void prime() {
	LL pri[MAXN] , index = 0;
	Ms(vis,0); Ms(pri,0);
	Fo(i,2,100000) {
		if(!vis[i]) pri[++index] = i;
		for(int j=1; j<=index&&pri[j]*i<=100000; j++) {
			vis[pri[j]*i] = 1;
			if(i%pri[j]==0) break;
		}
	}
}

LL n;

int main() {
	//freopen("data.txt","r",stdin);
	prime();
	n=read();
	vis[1] = 1;
	Fo(i,1,n) {
		LL temp = read();
		if(!vis[temp])
			cout<<temp<<" ";
	}
	return 0;
}
