//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
LL x = 0, f = 1;char c = getchar();
while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
return x * f;
}

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
            // res = res*a%mod;
        // a = a*a%mod;
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
    // if(x==2||x==61) return true;
    LL m=x-1 , k=0;
    while(m%2==0) {
        k++;
        m>>=1;
    }
    Fo(i,0,11) {
        // LL a = rand()%(x-1)+1;
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
    srand(time(NULL));
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL n;
    while(cin>>n) {
        cout<<(miller_rabin(n)==1?"Y":"N")<<endl;
        // cout<<(miller(n)==1?"Y":"N")<<endl;
    }
    return 0;
}