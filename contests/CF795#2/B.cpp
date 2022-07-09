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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> a(n+5), b;
        Fo(i,1,n) {
            cin>>a[i];
            b.push_back(a[i]);
        }
        int m = unique(b.begin(), b.end())-b.begin()-1;
        int mx = 0;
        Fo(i,1,n) {
            a[i] = lower_bound(b.begin(), b.end(), a[i])-b.begin()+1;
            mx = max(mx, a[i]);
        }
        vector<int> c[mx+5], d(mx+5, 0);
        Fo(i,1,n) {
            c[a[i]].push_back(i);
            d[a[i]] = 1;
        }
        bool flag = 1;
        Fo(i,1,n) {
            if(c[a[i]].size()==1) {
                flag = 0;
                break;
            }
        }
        if(!flag) cout<<"-1"<<endl;
        else {
            Fo(i,1,n) {
                if(d[a[i]]==c[a[i]].size())
                    cout<<c[a[i]][0]<<' ';
                else cout<<c[a[i]][(d[a[i]]++)]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}