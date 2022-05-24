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

bool cmp(int a, int b) {
    return a>b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    int t; cin>>t;
    while(t--) {
        int n, q; cin>>n>>q;
        vector<int> a(n);
        Fo(i,0,n-1) {
            cin>>a[i];
        }
        sort(a.begin(), a.end(), cmp);
        vector<int> s(n, 0);
        s[0] = a[0];
        Fo(i,1,n-1) {
            s[i] = s[i-1]+a[i];
        }
        Fo(i,1,q) {
            int c; cin>>c;
            if(c>s[n-1]) {
                cout<<"-1"<<endl;
                continue;
            }
            int b = lower_bound(s.begin(), s.end(), c)-s.begin();
            cout<<b+1<<endl;
        }
    }
    return 0;
}