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

const LL maxn = 1e5+5;
int nxt[maxn] , len2 , len , T;
string str2;

void Next() {
    LL p1 = 0 , p2 = -1;
    nxt[0] = -1;
    while(p1<len2) {
        if(p2==-1 || str2[p1]==str2[p2])
            nxt[++p1] = ++p2;
        else    p2 = nxt[p2];
    }
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>T;
	while(T--) {
		Ms(nxt,0);
		cin>>str2;
		len2 = str2.length();
		Next();
		len = len2-nxt[len2];
		if(!nxt[len2]) cout<<len2<<endl;
		else if(len2%len==0) cout<<"0"<<endl;
		else cout<<len-len2%len<<endl;
	}
	return 0;
}

