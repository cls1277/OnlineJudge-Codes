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
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; t = 1;
    cout<<t<<endl;
    while(t--) {
        int n=1024, m=1024;
        cout<<n<<' '<<m<<endl;
        Fo(i,1,n) {
            LL x = rand()%100+1, y = rand()%1024+1;
            cout<<x<<' '<<y<<endl;
        }
    }
    return 0;
}