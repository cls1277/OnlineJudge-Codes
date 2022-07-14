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

const LL maxn = 2e5+5;
LL n, c[maxn];

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

template<typename typC> struct bit
{
	vector<typC> a;
	int n;
	bit(){}
	bit(int nn):n(nn),a(nn+1){}
	template<typename T> bit(int nn,T *b):n(nn),a(nn+1)
	{
		for (int i=1;i<=n;i++) a[i]=b[i];
		for (int i=1;i<=n;i++) if (i+(i&-i)<=n) a[i+(i&-i)]+=a[i];
	}
	void add(int x,typC y)
	{
		//cerr<<"add "<<x<<" by "<<y<<endl;
		assert(1<=x&&x<=n);
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y; 
	}
	typC sum(int x)
	{
		if (x<=0) return 0;
		//cerr<<"sum "<<x;
		// assert(0<=x&&x<=n);
		typC r=a[x];
		while (x^=x&-x) r+=a[x];
		//cerr<<"= "<<r<<endl;
		return r;
	}
	typC sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        Ms(c, 0);
        cin>>n;
//        bit<int> s(n);
        LL ans = 0;
        Fo(i,1,n) {
            LL x; cin>>x;
            if(i<=x) continue;
            ans += sum(x-1);
            update(i, 1);
//			ans += s.sum(x-1);
//			s.add(i, 1); 
        }
        cout<<ans<<endl;
    }
    return 0;
}
