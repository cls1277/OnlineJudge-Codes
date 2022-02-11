//By cls1277
#include<bits/stdc++.h>
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

LL qpow(LL a, LL b, LL p) {
    LL res=1;
    while(b) {
        if(b&1)
            res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}

//a^x=b mod p
LL bsgs(LL a, LL b, LL p) {
    LL t=sqrt(p)+1;
    map<LL,LL>mp;
    LL m=b%p;
    Fo(i,0,t-1) {
        mp[m]=i+1;
        m=m*a%p;
    }
    LL temp=qpow(a,t,p);
    m=temp;
    Fo(i,1,t) {
        if(mp[m])
            return i*t-mp[m]+1;
        m=m*temp%p;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL p,b,n,res;
    cin>>p>>b>>n;
    res=bsgs(b,n,p);
    if(res==-1) cout<<"no solution";
    else cout<<res;
    return 0;
}