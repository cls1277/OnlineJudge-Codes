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
LL n, a[maxn], s[maxn], inv[maxn];

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

void dfs(LL x, LL cnt, LL p) {
    if(x==n) {
        s[cnt] = (s[cnt]+p)%mod;
        return ;
    }
    Fo(i,1,a[x]) dfs(x+i, cnt+1, p*inv[x]%mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n-1) {
        cin>>a[i];
        inv[i] = qpow(a[i], mod-2)%mod;
    }
    dfs(1, 0, 1);
    LL ans = 0;
    Fo(i,1,n) {
    	// cout<<s[i]<<' ';
    	ans = (ans+s[i]*s[i]%mod)%mod;	
	}
	// cout<<endl;
    cout<<ans<<endl;
    return 0;
}
