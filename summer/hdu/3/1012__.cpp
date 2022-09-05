#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int inf1=2147483647;
const ll INF=1e18;
const ll mod = 998244353;
// #define IO freopen("data.txt","r",stdin)//,freopen("out.out","w",stdout)
#define CLOSE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int maxn=3e5+5;
int P[maxn],Q[maxn],S[2*maxn];
int posp[maxn],posq[maxn];

inline ll read() {
	ll x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

int main(){
    // IO;
    #ifdef DEBUG
    // freopen("data.txt","r",stdin);
    freopen("1012.in","r",stdin);
    freopen("out.out","w",stdout);
    #endif
    // CLOSE;
    int T;T=read();//cin>>T;
    while(T--){
        unordered_map<ll, int>m;
        int n; scanf("%lld",&n); //n=read(); //cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%lld",&P[i]); //P[i]=read(); //cin>>P[i];
        }
        for(int i=1;i<=n;i++){
            scanf("%lld",&Q[i]); //Q[i]=read(); //cin>>Q[i];
        }
        for(int i=1;i<=2*n;i++){
            scanf("%lld",&S[i]); //S[i]=read(); //cin>>S[i];
        }
        for(int i=1;i<=n;i++){
            posp[P[i]]=i;
            posq[Q[i]]=i;
        }
        m[1*1e5]=(Q[1]==S[1]);
        m[1*1e5+1]=(P[1]==S[1]);
        for(int i=2;i<=2*n;i++){
        	if(posp[S[i]]<=i)
				m[i*1e5+posp[S[i]]]=(m[i*1e5+posp[S[i]]]+m[(i-1)*1e5+posp[S[i]]-1])%mod;
			if(posq[S[i]]<=i)
				m[i*1e5+i-posq[S[i]]]=(m[i*1e5+i-posq[S[i]]]+m[(i-1)*1e5+i-(posq[S[i]]-1)-1])%mod;
        }
        printf("%lld\n",m[2*n*1e5+n]);
    }
    return 0;
}
