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
typedef unsigned long long LL;
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

const LL maxn = 45;
LL n , k , ans;
char num[maxn];

void dfs(LL x , LL c , LL mul) {
	if(c==k) {
		LL sum=0;
		Fo(i,x+1,n) {
			sum*=10;
			sum+=(num[i]-'0');
		}
		ans=max(ans,mul*sum);
		return ;
	}
	Fo(i,x+1,n-k+c) {
		LL sum=0;
		Fo(j,x+1,i) {
			sum*=10;
			sum+=(num[j]-'0');
		}
		dfs(i,c+1,sum*mul);
	}
	return ;
}

int main() {
	//ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>k;
	scanf("%s",num+1);
	dfs(0,0,1);
	cout<<ans;
	return 0;
}

