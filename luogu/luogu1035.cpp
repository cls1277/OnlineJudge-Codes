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

//const LL maxn = ;

LL gcd(LL x , LL y) {
	return y?gcd(y,x%y):x;
}

struct Frac {
	LL fz , fm;
	Frac(){};
	Frac(LL zz , LL mm) {
		fz=zz , fm=mm;
	}
}; 
Frac a , b;

Frac operator + (Frac a , Frac b) {
	LL tmp1 = a.fz*b.fm+a.fm*b.fz;
	LL tmp2 = a.fm*b.fm;
	LL tmp3 = gcd(tmp1 , tmp2);
	tmp1/=tmp3; tmp2/=tmp3;
	return Frac(tmp1,tmp2);
}

bool operator > (Frac a , Frac b) {
	return a.fz*b.fm>a.fm*b.fz;
}

LL n , num=0;
double s=0;

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n;
	while(s<=n) {
		num++;
		s+=1.0/num;
	}
	cout<<num;
	/*a=Frac(0,1); b=Frac(n,1);
	while(1) {
		a=a+Frac(1,num);
		if(a>b) {
			cout<<num;
			return 0;
		}
		num++;
	}*/
	return 0;
}

