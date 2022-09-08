//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 55;
const LL maxm = 51;
LL m, n, a[maxn], p[maxn], cnt;

LL solve(string str) {
    LL t=1, ans=0;
    Ro(i,m-1,0) {
        if(str[i]=='O')
            ans += t;
        t <<= 1;
    }
    return ans;
}

void insert() {
    Fo(i,1,n) {
        LL x = a[i];
        Ro(j,maxm,0) {
            if(x&(1LL<<j)) {
                if(!p[j]) {
                    p[j] = x;
                    cnt++;
                    break;
                } else {
                    x^=p[j];
                }
            }
        }
    }
}

const LL mod = 2008;

LL qpow(LL x, LL y) {
    LL ans = 1;
    while(y) {
        if(y&1)
            ans = ans*x%mod;
        x = x*x%mod;
        y >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>m>>n;
    Fo(i,1,n) {
        string str; cin>>str;
        a[i] = solve(str);
    }
    insert();
    cout<<qpow(2, cnt)%mod;
    return 0;
}