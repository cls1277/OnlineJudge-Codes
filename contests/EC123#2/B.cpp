//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
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
        Fo(i,1,n-1) {
            bool flag=0;
            Ro(j,n,2) {
                if(j==n+1-i&&!flag) {
                    cout<<"1 ";
                    j++; flag=1;
                    continue;
                }
                cout<<j<<' ';
            }
            cout<<endl;
        }
        Ro(i,n,1) cout<<i<<' '; cout<<endl;
    }
    return 0;
}