//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define INF 2147483647
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

// const LL maxn = ;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
inline ull qmul(ull a,ull b,const ull mod){
    ll c=(ll)(a)*b-(ll)((ull)((ld)(a)*b/mod)*mod);
    return c<0? c+mod:(c<mod? c:c-mod);
}

LL qpow(LL a , LL b , LL mod) {
    LL res = 1;
    while(b) {
        if(b&1)
            res = qmul(res,a,mod);
        a = qmul(a,a,mod);
        b>>=1;
    }
    return res;
}

bool miller_rabin(LL x) {
    if(x==2) return true;
    if(x<2||x%2==0) return false;
    LL A[12]={2,3,5,7,11,13,17,19,23,29,31,37};
    Fo(i,0,11)
        if(x==A[i])
            return true;
    LL m=x-1 , k=0;
    while(m%2==0) {
        k++;
        m>>=1;
    }
    Fo(i,0,11) {
        LL y = qpow(A[i],m,x) , z;
        z = y;
        Fo(j,1,k) {
            y = qmul(y,y,x);
            if(y==1&&z!=1&&z!=x-1)
                return false;
            z = y;
        }
        if(y!=1)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL a,b; cin>>a>>b;
        LL x=0;
        while(a%b==0) {
            x++;
            a/=b;
        }
        if(x==1) {
            cout<<"NO"<<endl;
            continue;
        }
        if()
    }
    return 0;
}