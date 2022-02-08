//By cls1277
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cctype>
// using namespace std;
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

inline LL mymax(LL a, LL b){ return a > b ? a : b ; }
inline LL myabs(LL a) {return a<0?(-a):a; };

// const LL mymaxn = ;

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

LL f(LL x , LL c , LL mod) {
    return (qmul(x,x,mod)+c)%mod;
}

LL gcd(LL x , LL y) {
    return (y==0)?x:gcd(y,x%y);
}

// #define mytz __builtin_ctzll
// inline LL gcd(LL a, LL b){
//     if(!a) return b;
//     if(!b) return a;
//     register int t = mytz(a|b) ;
//     a >>= mytz(a) ;
//     do{
//         b >>= mytz(b) ;
//         if(a>b){LL t=b;b=a,a=t;}
//         b-=a;
//     }while(b);
//     return a<<t;
// }

LL rho(LL n) {
    LL x,y,i,j,c,z;
    while(1) {
        i=0;j=1;z=1;
        x=y=rand()%n; c=rand()%n;
        while(++i) {
            x=f(x,c,n);
            z=qmul(z,myabs(y-x),n);
            if(!z||x==y) break;
            if(i==j||i%127==0) {
                LL g=gcd(z,n);
                if(g>1) return g;
                if(i==j) {
                    j<<=1;
                    y=x;
                }
            }
        }
    }
}

LL ans;

void dfs(LL n) {
    if(n<ans||n<2)
        return ;
    if(miller_rabin(n)) {
        ans = mymax(ans,n);
        return ;
    }
    LL p=n;
    p=rho(n);
    while(n%p==0) n/=p;
    dfs(n); dfs(p);
}

int main() {
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    srand(time(NULL));
    LL T; T=read();
    while(T--) {
        LL n; n=read();
        ans=0;
        if(miller_rabin(n)) {
            printf("Prime\n");
            continue;
        }
        dfs(n);
        printf("%lld\n",ans);
    }
    return 0;
}