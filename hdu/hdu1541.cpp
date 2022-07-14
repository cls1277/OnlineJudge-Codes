//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'
#define lowbit(_) _&(-_)
const LL maxn = 32005;
LL c[maxn], n;

void update(LL x , LL y) {
	while(x<=32000) {
		c[x]+=y;
		x+=lowbit(x);
	}
}

LL sum(LL x) {
	if(x<=0) return 0;
	LL ans = 0;
	while(x) {
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

LL ans[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
	while(cin>>n) {
		Ms(ans, 0); Ms(c, 0);
		Fo(i,1,n) {
			LL x, y; cin>>x>>y;
			x++;
			// cout<<c[8]<<' '<<sum(x)<<endl;
			ans[sum(x)]++;
			update(x, 1);
		}
		Fo(i,0,n-1) cout<<ans[i]<<endl;
	}
    return 0;
}