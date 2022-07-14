//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e6+5;
#define lowbit(_) _&(-_)
LL c[maxn], n;

void update(LL x , LL y) {
	while(x<=n) {
		c[x]+=y;
		x+=lowbit(x);
	}
}

void rangeUpdate(LL l, LL r, LL x) {
    update(l, x);
    update(r+1, -x);
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
    while(cin>>n&&n) {
        Ms(c, 0);
        Fo(i,1,n) {
            LL l, r; cin>>l>>r;
            rangeUpdate(l, r, 1);
        }
        Fo(i,1,n) {
            if(i!=n) cout<<sum(i)<<' ';
            else cout<<sum(n);
        }
        cout<<endl;
    }
    return 0;
}