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
    LL t; t=5; cout<<t<<endl;
    while(t--) {
        LL n = 5, m1 = 5, m2 = 5;
        cout<<n<<' '<<m1<<' '<<m2<<endl;
        Fo(i,1,m1) {
            LL a, b, c;
            do {
                a = rand()%n+1;
                b = rand()%n+1;
            }while(a==b);
            c = rand()%2;
            cout<<a<<' '<<b<<' '<<c<<endl;
        }
        Fo(i,1,m2) {
            LL a, b;
            do {
                a = rand()%n+1;
                b = rand()%n+1;
            }while(a==b);
            cout<<a<<' ' <<b<<endl;           
        }
    }
    return 0;
}