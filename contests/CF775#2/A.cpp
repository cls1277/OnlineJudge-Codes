//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 105;
LL n, a[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n;
        LL cnt = 0;
        Fo(i,1,n) {
            cin>>a[i];
            if(!a[i]) cnt++;
        }
        if(!cnt) {
            cout<<'0'<<endl;
            continue;
        }
        LL l=1, r=n;
        Fo(i,1,n)
            if(a[i]!=1) {
                l = i-1;
                break;
            }
        Ro(i,n,1)
            if(a[i]!=1) {
                r = i+1;
                break;
            }
        cout<<r-l<<endl;
    }
    return 0;
}