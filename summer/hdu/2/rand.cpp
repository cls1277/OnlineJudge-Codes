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
    LL t = 1; cout<<t<<endl;
    while(t--) {
        LL n, m; n=100, m=100;
        cout<<n<<' '<<m<<endl;
        Fo(i,1,n) {
            cout<<rand()%10+1<<' ';
        }
        Fo(i,1,m) {
            LL l=rand()%(n-3)+1, r=rand()%(n-l-2)+l+3;
            cout<<l<<' '<<r<<endl;
        }
    }
    return 0;
}