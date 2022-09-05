//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 65;
LL x, y, a[maxn];
vector<LL> d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>x>>y;
    // cout<<x<<' '<<y<<endl;
    LL t = x^y;
    // cout<<t<<endl;
    LL top = 0;
    while(t) {
        a[top++] = t%2;
        t >>= 1;
    }
    // Fo(i, 0, top-1) cout<<a[i]<<' ';
    // cout<<endl;
    LL b = 1, c = 0;
    Fo(i,0,top-1) {
        if(a[i]) {
            if(c+b>=x) {
                d.push_back(c);
                x = x^c;
                c = b;
            } else {
                c += b;
            }
        }
        b <<= 1;
    }
    if(c) d.push_back(c);
    cout<<d.size()<<endl;
    for(auto it:d) cout<<it<<' ';
    return 0;
}