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
        LL n; multiset<LL>a, b;
        cin>>n;
        Fo(i,1,n) {
            LL x; cin>>x;
            while(x%2==0) {
                x /= 2;
            }
            a.insert(x);
        }
        Fo(i,1,n) {
            LL x; cin>>x;
            b.insert(x);
        }
        while(!b.empty()) {
            // LL x = *max_element(b.begin(), b.end());
            LL x = *b.rbegin();
            if(a.count(x)) {
                a.erase(a.find(x));
                b.erase(b.find(x));
            } else {
                if(x==1) break;
                b.erase(b.find(x));
                b.insert(x/2);
            }
        }
        if(b.empty()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}