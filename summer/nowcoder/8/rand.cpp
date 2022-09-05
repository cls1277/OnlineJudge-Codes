//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    // freopen("data.txt","w",stdout);
    #endif
    srand(time(NULL));
    LL t; t=1; cout<<t<<endl;
    while(t--) {
        LL n, m, p, x, a, b, c;
        n = rand()%100000+1;
        m = rand()%100000+1;
        p = rand()%1000000000+1;
        x = rand()%1000000000;
        a = rand()%1000000000;
        b = rand()%1000000000;
        c = rand()%1000000000;
       a=b= c = 0;
        cout<<n<<' '<<m<<' '<<p<<' '<<x<<' '<<a<<' '<<b<<' '<<c<<endl;
    }
    return 0;
}