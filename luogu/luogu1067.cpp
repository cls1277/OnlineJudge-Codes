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
int n , x , a[maxn] , flag;

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n;
	Fo(i,1,n+1) cin>>a[i];
	Fo(i,1,n) {
		if(!a[i]) continue;
		if(!flag) {
			if(a[i]>0) {
				if(a[i]!=1) cout<<a[i]<<"x";
				else cout<<"x";
				if(n+1-i!=1) cout<<"^"<<n+1-i;
			} else {
				if(a[i]!=-1) cout<<a[i]<<"x";
				else cout<<"-x";
				if(n+1-i!=1) cout<<"^"<<n+1-i;		
			}
			flag = 1;
		} else {
			if(a[i]>0) {
				if(a[i]!=1) cout<<"+"<<a[i]<<"x";
				else cout<<"+x";
				if(n+1-i!=1) cout<<"^"<<n+1-i;
			} else {
				if(a[i]!=-1) cout<<a[i]<<"x";
				else cout<<"-x";
				if(n+1-i!=1) cout<<"^"<<n+1-i;				
			}
		}
	}
	if(a[n+1]>0&&flag)
		cout<<"+"<<a[n+1];
	else if(a[n+1]) cout<<a[n+1];
	return 0;
}

