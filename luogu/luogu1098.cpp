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
int p1 , p2 , p3 , len;
string str;

bool jud(char x , char y) {
	if(x>='a'&&x<='z'&&y>='a'&&y<='z')
		return true;
	else if(x>='0'&&x<='9'&&y>='0'&&y<='9')
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>p1>>p2>>p3>>str;
	len=str.length()-1;
	Fo(i,0,len) {
		if(str[i]=='-'&&i>0&&i<len&&jud(str[i-1],str[i+1])) {
			if(str[i-1]>=str[i+1]) cout<<"-";
			else if(str[i+1]-str[i-1]==1) continue;
			else if(p3==2) {
				for(char a=str[i+1]-1; a>=str[i-1]+1; a--) {
					for(int b=1; b<=p2; b++) {
						if(p1==3) {
							cout<<"*";
							continue;	
						}
						if(a>='0'&&a<='9') cout<<a;
						else if(p1==1) cout<<a;
						else if(p1==2) cout<<(char)(a-'a'+'A');
					}
				}
			} else  {
				for(char a=str[i-1]+1; a<=str[i+1]-1; a++) {
					for(int b=1; b<=p2; b++) {
						if(p1==3) {
							cout<<"*";
							continue;	
						}
						if(a>='0'&&a<='9') cout<<a;
						else if(p1==1) cout<<a;
						else if(p1==2) cout<<(char)(a-'a'+'A');
					}
				}				
			}
		} else cout<<str[i];
	}
	return 0;
}

