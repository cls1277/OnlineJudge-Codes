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
string str;
int m1 , m2 , d1 , d2 , ans;
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
	//ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>str;
	m1=str[0]-'0'; m2=str[1]-'0'; d1=str[3]-'0'; d2=str[4]-'0';
	if(d1*10+d2>31&&m1*10+m2<=12) {
		if(m1*10+m2==0) {
			cout<<"2";
			return 0;
		}
		ans=1;
	}
	else if(d1*10+d2<=31&&m1*10+m2<=12) {
		if(m1*10+m2==0) {
			cout<<"1";
			return 0;
		}
		if(d[m1*10+m2]<=d1*10+d2||!(d1*10+d2)) ans=1;
		else ans=0;
	}
	else if(d1*10+d2>31&&m1*10+m2>12) 
		ans=2;
	else {
		ans=INF;
		if(m1==1) {
			if(d[10]<d1*10+d2) ans=min(ans,2);
			else ans=min(ans,1);
			if(d[11]<d1*10+d2) ans=min(ans,2);
			else ans=min(ans,1);
			if(d[12]<d1*10+d2) ans=min(ans,2);
			else ans=min(ans,1);
		} else {
			int month=10+m2;
			if(month>=1&&month<=12) {
				if(d[month]<d1*10+d2) ans=min(ans,2);
				else ans=min(ans,1);				
			}
			month=m2;
			if(month>=1&&month<=12) {
				if(d[month]<d1*10+d2) ans=min(ans,2);
				else ans=min(ans,1);
			}
		}
		if(d1*10+d2==0) ans++;
	}
	cout<<ans;
	return 0;
}

