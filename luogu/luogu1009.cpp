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

const LL maxn = 1005;
int n;
string str;

string add(string x , string y) {
	int len1=x.length()-1 , len2=y.length()-1 , len3=max(len1,len2);
	int xx[maxn] , yy[maxn] , zz[maxn]; string ans="";
	Ms(zz , 0);
	if(len1==len3) {
		Ro(i,len3,0) xx[len3-i]=x[i]-'0';
		Ro(i,len3,0) {
			if(i>=len3-len2) yy[len3-i]=y[len2-len3+i]-'0';
			else yy[len3-i]=0;
		}
	} else {
		Ro(i,len3,0) yy[len3-i]=y[i]-'0';
		Ro(i,len3,0) {
			if(i>=len3-len1) xx[len3-i]=x[len1-len3+i]-'0';
			else xx[len3-i]=0;
		}		
	}
	Fo(i,0,len3) {
		zz[i]+=xx[i]+yy[i];
		zz[i+1]+=zz[i]/10;
		zz[i]%=10;
	}
	len3++;
	zz[len3+1]+=zz[len3]/10;
	zz[len3]%=10;
	len3++;
	while(len3&&!zz[len3]) len3--;
	Ro(i,len3,0) ans+=zz[i]+'0';
	return ans;
}

string mul(string x , int y) {
	int len=x.length()-1 , xx[maxn] , yy[maxn];
	string ans="";
	Ms(yy , 0);
	Ro(i,len,0) xx[len-i]=x[i]-'0';
	Fo(i,0,len) {
		yy[i]+=xx[i]*y;
		yy[i+1]+=yy[i]/10;
		yy[i]%=10;
	}
	len++;
	yy[len+1]+=yy[len]/10;
	yy[len]%=10;
	len++;
	while(len&&!yy[len]) len--;
	Ro(i,len,0) ans+=yy[i]+'0';
	return ans;
}

string fac(int x) {
	string ans="1";
	Fo(i,2,x)
		ans=mul(ans,i);//,cout<<i<<":"<<ans<<endl;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n;
	str="1";
	//cout<<fac(n);
	Fo(i,2,n) {
		str = add(str,fac(i));
		//cout<<i<<":"<<str<<endl;	
	}
	cout<<str;
	return 0;
}

