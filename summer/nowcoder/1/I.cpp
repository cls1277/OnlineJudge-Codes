//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL mod = 1e9+7;
LL f[15][140];

LL qpow(LL x, LL y) {
    LL z = 1;
    while(y) {
        if(y&1) z = z*x%mod;
        x = x*x%mod;
        y >>= 1;
    }
    return z%mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    for(int i=1; i<=13; i+=2) {
        Fo(j,1,136) {
            if(i==1) f[i][j] = (1+f[1][j-1]*(j-3)%mod*qpow(j,mod-2)%mod)%mod;
            else f[i][j] = (1+f[i-2][j-1]*3%mod*i%mod*qpow(j,mod-2)%mod+f[i][j-1]*(j-3*i)%mod*qpow(j,mod-2)%mod)%mod;
        }
    }
    LL t; cin>>t;
    Fo(tt, 1, t) {
        string str; cin>>str;
        map<string, LL> s;
        for(int i=0; i<str.length(); i+=2) {
            string ss = "";
            ss += str[i]; ss += str[i+1];
            s[ss]++;
        }
        LL cnt = 0;
        for(auto it:s) {
            if(it.second&1) {
                cnt++;
            }
        }
        cout<<"Case #"<<tt<<": "<<f[cnt][123]<<endl;
    }
    return 0;
}
