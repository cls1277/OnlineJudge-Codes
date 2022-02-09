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

LL n,a,p;

struct Zi {
    LL x,y;
    Zi operator * (Zi m) {
        return {(x*m.x%p+y*m.y%p*(a*a%p-n)%p)%p,(x*m.y%p+y*m.x%p)%p};
    }
    Zi qpow(LL b) {
        Zi res={1,0},x=(*this);
        while(b) {
            if(b&1)
                res=res*x;
            x=x*x;
            b>>=1;
        }
        return res;
    }
};

LL qpow(LL x, LL y) {
    LL res=1;
    while(y) {
        if(y&1)
            res=res*x%p;
        x=x*x%p;
        y>>=1;
    }
    return res;
}

LL lrand(LL x) {
    return qpow(x%p,(p-1)/2);
}

LL qresidue() {
    LL i=rand()%p;
    while(1) {
        if(lrand(i*i-n)==p-1) {
            a = i;
            break;
        } else i=rand()%p;
    }
    // Fo(i,0,p-1)
    //     if(lrand(i*i-n)==p-1) {
    //         a=i;
    //         break;
    //     }
    Zi ans={a,1};
    return ans.qpow((p+1)/2).x%p;
}

int main() {
    // ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    srand(time(NULL));
    LL T; T=read();//cin>>T;
    while(T--) {
        n=read(); p=read();
        if(n%p==0) {
            printf("0\n");
            continue;
        }
        if(lrand(n)!=1) {
            printf("Hola!\n");
            continue;
        }
        // cin>>n>>p;
        LL ans=qresidue(),ans2;
        if(ans<0) ans=(p+ans)%p;
        ans2=(p-ans)%p;
        if(ans==ans2) {
            printf("%lld\n",ans);
            // cout<<ans<<endl;
            continue;
        }
        printf("%lld %lld\n",min(ans,ans2),max(ans,ans2));
        // cout<<min(ans,ans2)<<" "<<max(ans,ans2)<<endl;
    }
    return 0;
}