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
#define lowbit(_) _&(-_)
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

LL T , n , k , s , vis[25] , flag;

void dfs(LL cnt , LL sum) {
	if(cnt==k) {
		if(sum==s) {
			cout<<"Yes"<<endl;	
			flag = 1;		
		}
		return ;
	}
	if(flag) return ;
	Fo(i,1,n)
		if(!vis[i]) {
			vis[i] = 1;
			dfs(cnt+1 , sum+i);
			if(flag) return ;
			vis[i] = 0;
		}
}

int main() {
//	freopen("data.txt","r",stdin);
	T=read();
	while(T--) {
		n=read(); k=read(); s=read();
		if(k==1) {
			if(s>n)
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;
			continue;
		}
		if(s>=(1+k)*k/2&&s<=(2*n-k+1)*k/2)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
