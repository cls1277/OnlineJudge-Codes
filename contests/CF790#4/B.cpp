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
    int T; cin>>T;
    while(T--) {
        int n, s=0; cin>>n;
        vector<int> a(n);
        Fo(i,0,n-1) cin>>a[i],s+=a[i];
        int mn = *min_element(a.begin(), a.end());
        cout<<s-mn*n<<endl;
    }
    return 0;
}