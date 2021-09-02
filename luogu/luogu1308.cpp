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

const LL maxn = 1e6+5;
string op , ch; 
int ans1 , ans2 , n , len , sum=-1;

void exc(string &a) {
	for(int i=0; i<a.length(); i++)
		if(a[i]>='A'&&a[i]<='Z')
			a[i]=a[i]-'A'+'a';
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	getline(cin,op);
	ans2=-1;
	exc(op);
	getline(cin,ch);
	len=ch.length()-1;
	Fo(i,0,len) {
		if(ch[i]!=' ') {
			Fo(j,i,len) {
				if(ch[j]==' '||j==len) {
					string temp=ch.substr(i,j-i);
					exc(temp);
					if(op==temp) {
						ans1++;
						if(ans2==-1) ans2=i;
					}
					i=j;
					//cout<<temp<<endl;
					break;
				}
			}
		}
	}
	if(!ans1) cout<<"-1";
	else cout<<ans1<<" "<<ans2;
	return 0;
}

