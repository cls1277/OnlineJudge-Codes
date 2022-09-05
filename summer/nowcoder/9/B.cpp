//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 8e3+5;
const LL mod = 998244353;
//LL n, a[maxn], s[maxn];
//struct Node {
//	LL a, b, c;
//};
//vector<pair<LL, LL>> b[maxn][maxn];
//vector<Node> vv;
//
inline LL qpow(LL a, LL b) {
    LL res = 1;
    while(b) {
        if(b&1)
            res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}
//
//void dfs(LL x, LL cnt, LL p, vector<Node> v) {
//	if(b[x][cnt].size()) {
//		for(auto it:b[x][cnt]) {
//			s[it.first] = (s[it.first]+it.second*p%mod)%mod;
//		}
//		return ;
//	}
//    if(x==n) {
//        s[cnt] = (s[cnt]+p)%mod;
//        for(auto it:v) {
//        	b[it.a][it.b].push_back({cnt, p*qpow(it.c, mod-2)%mod});
//		}
//        return ;
//    }
//    Fo(i,1,a[x]) {
//    	v.push_back({x+i, cnt+1, p});
//    	dfs(x+i, cnt+1, p*qpow(a[x], mod-2)%mod, v);
//		v.pop_back();
//	}
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cout<<77*qpow(576, mod-2)%mod; 
//    cin>>n;
//    Fo(i,1,n-1) cin>>a[i];
//    dfs(1, 0, 1, vv);
//    for(auto it:b[2][1]) {
//    	cout<<it.first<<' '<<it.second<<endl;
//	}
//	return 0;
//    LL ans = 0;
//    Fo(i,1,n) {
//    	// cout<<s[i]<<' ';
//    	ans = (ans+s[i]*s[i]%mod)%mod;	
//	}
//	cout<<endl;
//    cout<<ans<<endl;
    return 0;
}
