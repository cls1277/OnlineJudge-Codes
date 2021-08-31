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
#include<set>
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Ms(a,b) memset((a),(b),sizeof(a))
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

string s;
set<LL>vis;

int main() {
//	freopen("data.txt","r",stdin);
	cin>>s;
	Fo(i,0,s.length()-1) {
		if(s[i]>='0'&&s[i]<='9') {
			LL ans = 0;
			for(int j=0; i+j<=s.length()-1; j++) {
				if(s[i+j]<'0'||s[i+j]>'9') {
					i = i+j;
					vis.insert(ans);
					ans = 0;
					break;
				}
				ans = ans*10 + (s[i+j]-'0');
			} 
			if(ans) {
				vis.insert(ans);
				break;	
			}
		}
	}
	cout<<vis.size(); 
	return 0;
}
