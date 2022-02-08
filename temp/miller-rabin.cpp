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

LL qmul(LL a , LL b , LL mod) {
    LL res = 0;
    while(b) {
        if(b&1)
            res = (res+a)%mod;
        a = (a+a)%mod;
        b>>=1;
    }
    return res;
}

LL qpow(LL a , LL b , LL mod) {
    LL res = 1;
    while(b) {
        if(b&1)
            res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}

int A[7]={2,325,9375,28178,450775,9780504,1795265022};

bool miller_rabin(LL x , LL a) {
    LL m = x-1 , k=0;
    while(m%2==0) {
        k++;
        m>>=1;
    }
    LL y = qpow(a,m,x) , z;
    Fo(i,1,k) {
        y = qmul(y,y,x);
        if(y==1&&z!=1&&z!=x-1)
            return false;
        z = y;
    }
    if(y!=1)
        return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    bool flag = 0;
    Fo(i,0,6) {
        if(miller_rabin(666623333,A[i])) {
            flag = 1;
            break;
        }
    }
    if(flag) cout<<"Y";
    else cout<<"N";
    return 0;
}