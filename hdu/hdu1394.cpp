//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5005;
#define lowbit(_) _&(-_)
LL c[maxn], n, a[maxn];

void update(LL x , LL y) {
	while(x<=n) {
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(cin>>n) {
        Fo(i,1,n) cin>>a[i];
        LL res = 0; Ms(c, 0);
        Fo(i,1,n) {
            update(a[i]+1, 1);
            res += i-sum(a[i]+1);
        }
        LL ans = res;
        Fo(i,1,n) {
            res += (n-a[i]-1)-a[i];
            ans = min(ans, res);
        }
        cout<<ans<<endl;
    }
    return 0;
}