//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = ;

inline LL qpow(LL a, LL b) {
    LL res = 1;
    while(b) {
        if(b&1)
            res = res*a;
        a = a*a;
        b>>=1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n, ans = 0; cin>>n;
        LL m = 1, mm = 1;
        while(mm*2<n) mm*=2, m++;
        if(qpow(2, m)==n) {
            cout<<2*n-1<<endl;
        } else {
            ans = qpow(2, m)+1;
            LL det = n-qpow(2, m-1);
            if(det==1) {
                cout<<ans<<endl;
                continue;
            }
            LL k = 1, kk = 1;
            while(k*2-1<det) k*=2,kk++;
            kk--;
            while(kk) {
                ans += qpow(2, m-1);
                m--; kk--;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}