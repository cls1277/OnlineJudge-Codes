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
int T , n , cnt , len , b[2*maxn] , fa[maxn];
struct In {
	int x , y , z;
};
In a[maxn];

bool cmp(In x , In y) {
	return x.z>y.z;
}

int find(int x) {
	if(x!=fa[x])
		return fa[x]=find(fa[x]);
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>T;
	while(T--) {
		bool flag=true;
		cin>>n;
		cnt=0;
		Fo(i,1,n) {
			cin>>a[i].x>>a[i].y>>a[i].z;
			b[++cnt]=a[i].x; b[++cnt]=a[i].y;	
		}
		sort(b+1 , b+cnt+1);
		len = unique(b+1 , b+cnt+1)-b-1;
		Fo(i,1,n) {
			a[i].x=lower_bound(b+1,b+len+1,a[i].x)-b;
			a[i].y=lower_bound(b+1,b+len+1,a[i].y)-b;
		//	cout<<a[i].x<<" "<<a[i].y<<endl;
		}
		Fo(i,1,len) fa[i]=i;
		sort(a+1,a+n+1,cmp);
		Fo(i,1,n) {
			int f1=find(a[i].x) , f2=find(a[i].y);
			if(a[i].z) {
				if(f1!=f2)
					fa[f1]=f2;
			} else {
				if(f1==f2) {
					flag=false;
					//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl;
					break;			
				}
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

