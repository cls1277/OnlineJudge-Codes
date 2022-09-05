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
    LL t; cin>>t;
    while(t--) {
        LL E, L, R, B; cin>>E>>L>>R>>B;
        LL mn, mx;
        mn = E+L+R+B;
        if(L||R) mn -= B;
        else {
            if(B-1>0) mn -= (B-1);
        }
        mn -= min(L, R);
        cout<<mn<<' ';
        if(B-E-1<=0) mx = E+L+R+B;
        else {
            LL det = B-E-1;
            // cout<<det<<' ';
            if(det>0) mx = E+L+R+B-det;
            else mx = E+L+R+B;
        }
        cout<<mx<<endl;
    }
    return 0;
}