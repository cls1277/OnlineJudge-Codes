//By cls1277
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<cctype>
using namespace std;
typedef long long LL;
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
const LL p = 9901;

LL qpow(LL a, LL b, LL mod) {
    LL res=1;
    while(b) {
        if(b&1)
            res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}

LL sol(LL a, LL b) {
    if((a-1)%p==0) return (b+1)%p;
    LL x=qpow(a,b+1,p);
    x=(x+9900)%p;
    LL y=qpow(a-1,p-2,p);
    return x*y%p;
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL x,y,ans=1; cin>>x>>y;
    double temp=x;
    Fo(i,2,sqrt(temp)) {
        if(x%i) continue;
        LL cnt=0;
        while(x%i==0) {
            x/=i;
            cnt++;
        }
        ans=ans*sol(i,y*cnt)%p;
        if(x==1) break;
    }
    if(x>1) ans=ans*sol(x,y)%p;
    cout<<ans;
    return 0;
}