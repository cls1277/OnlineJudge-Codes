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

const LL maxn = 105;
int n , m;
char a[maxn][maxn];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n>>m;
	Fo(i,1,n)
		Fo(j,1,m)
			cin>>a[i][j];
	Fo(i,1,n) {
		Fo(j,1,m) {
			int ans=0;
			if(a[i][j]=='*') {
				cout<<"*";
				continue;
			}
			Fo(k,0,7) {
				int tx=i+dx[k] , ty=j+dy[k];
				if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]=='*')
					ans++;
			}
			cout<<ans;
		}
		cout<<endl;
	}
	return 0;
}

