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
int n , len;
string str , exc;

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

string mul(string x , string y) {
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
		zz[i]+=xx[i]*yy[i];
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

string qpow(string x , int y) {
	if(!y) return "1";
	string temp=qpow(x,y>>1);
	if(y&1) return mul(mul(temp,temp),x);
	return mul(temp,temp);
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cout<<mul("16","1");
	/*exc="0";
	cin>>n>>str;
	len = str.length()-1;
	if(n==16) {
		Fo(i,0,len) {
			exc=add(exc,qpow("16",len-i));
		}
		cout<<exc;
	}*/
	return 0;
}

