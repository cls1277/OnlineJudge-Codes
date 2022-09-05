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
    LL t; t=1;
    cout<<t<<endl;
    while(t--) {
        LL n; n=rand()%10+2;
        cout<<n<<endl;
        Fo(i,1,n) cout<<rand()%6+1<<' ';
        cout<<endl;
        Fo(i,1,n) cout<<rand()%6+1<<' ';
    }
    return 0;
}