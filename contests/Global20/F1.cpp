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
        vector<pair<LL, LL>>a(n+5);
        vector<LL>b(n+5);
        Fo(i,1,n) {
            LL x; cin>>x;
            a[i] = {x, i};
        }
        sort(a.begin()+1, a.begin()+n+1);
        Fo(i,1,n) {
            b[a[i].second] = a[n-i+1].first;
        }
        Fo(i,1,n) cout<<b[i]<<' ';
        cout<<endl;
    }
    return 0;
}