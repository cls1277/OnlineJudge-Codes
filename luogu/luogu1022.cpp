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

const LL maxn = 10005;
int len , flag , b , c;
char a[maxn] , d;

int main() {
	//ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	scanf("%s",a+1);
	len=strlen(a+1);
	a[0] = '+'; a[len+1]='+';
	//cout<<len;
	Fo(i,1,len+1) {
		if(a[i]>='a'&&a[i]<='z') {
			d = a[i];
			Ro(j,i-1,0)
				if(a[j]=='+'||a[j]=='-'||a[j]=='=') {
					int num=0;
					Fo(k,j+1,i-1) num=num*10+(a[k]-'0');
					if(!num) num=1; 
					if(a[j]=='-') num=-num;
					if(!flag) b+=num;
					else b-=num;
					break;
				}
		}
		if((a[i]=='+'||a[i]=='-'||a[i]=='=')&&(a[i-1]>'z'||a[i-1]<'a')) {
			Ro(j,i-1,0) {
				if(a[j]=='+'||a[j]=='-'||a[j]=='=') {
					int num=0;
					Fo(k,j+1,i-1) num=num*10+(a[k]-'0');
					if(a[j]=='-') num=-num;
					if(!flag) c-=num;
					else c+=num;
					break;					
				}
			}
		}
		if(a[i]=='=') flag = 1;
	}
	//cout<<c<<" "<<b<<endl;
	printf("%c=%.3lf",d,c?c*1.0/b:(0.000));
	return 0;
}

