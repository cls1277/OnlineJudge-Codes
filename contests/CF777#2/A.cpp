//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define INF 2147483647
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

// const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n; cin>>n;
        if(n<=2) cout<<n<<endl;
        else {
            LL a=n/3;
            if(n%3==0) {
                Fo(i,1,a) cout<<"21";
                cout<<endl;
            } else if(n%3==1) {
                Fo(i,1,a) cout<<"12";
                cout<<"1";
                cout<<endl;
            } else {
                Fo(i,1,a) cout<<"21";
                cout<<"2";
                cout<<endl;
            }
        }
    }
    return 0;
}