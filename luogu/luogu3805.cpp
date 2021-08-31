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
#define Fo(i,a,b) for(int i=(a); i<=(b); i++)
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

const LL maxn = 1.1e7+5;
char str[maxn] , s[maxn<<1];
int f[maxn<<1];

int init() {
	int len = strlen(str)-1 , j=2;
	s[0]='^'; s[1]='$';
	Fo(i,0,len) {
		s[j++] = str[i];
		s[j++] = '$';
	}
	s[j] = '&';
	return j;
}

int Manacher() {
	int len=init()-1 , mid=1 , maxx=1 , ans=-1;
	Fo(i,1,len) {
		if(i<maxx) f[i]=min(maxx-i,f[mid*2-i]);
		else f[i]=1;
		while(s[i-f[i]]==s[i+f[i]]) f[i]++;
		if(maxx<i+f[i]) {
			mid = i;
			maxx = i+f[i];
		}
		ans = max(ans , f[i]-1);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	scanf("%s",str);
	printf("%d",Manacher());
	return 0;
}

