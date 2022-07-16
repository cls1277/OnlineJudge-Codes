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
LL n;

vector<LL> solve(string s) {
    vector<LL> res;
    Fo(i,0,n-2) {
        if(s[i]!=s[i+1]) {
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        cin>>n;
        string s, t; cin>>s>>t;
        if(s[0]!=t[0]||s[n-1]!=t[n-1]) {
            cout<<-1<<endl;
        } else {
            vector<LL> a=solve(s), b=solve(t);
            if(a.size()!=b.size()) {
                cout<<-1<<endl;
            } else {
                LL ans = 0;
                for(int i=0; i<a.size(); i++) {
                    ans += abs(a[i]-b[i]);
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}