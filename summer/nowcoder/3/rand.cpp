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
    freopen("data.txt","r",stdin);
    #endif
    srand(time(NULL));
    LL n = 10, m = 20;
    cout<<n<<' '<<m<<endl;
    Fo(i,1,m) {
        LL a=rand()%n+1, b=0;
        do {
            b = rand()%n+1;
        }while(a==b);
        cout<<a<<' '<<b<<endl;
    }
    LL q = 10; cout<<q<<endl;
    while(q--) {
        LL a=rand()%n+1, b=0;
        do {
            b = rand()%n+1;
        }while(a==b);
        cout<<a<<' '<<b<<endl;        
    }
    return 0;
}