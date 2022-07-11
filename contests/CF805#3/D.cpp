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

bool cmp(pair<LL, LL> x, pair<LL, LL> y) {
    return x.first>y.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        string str; cin>>str;
        LL p, ans = 0; cin>>p;
        vector<pair<LL, LL>> a;
        vector<bool> vis(str.length(), 0);
        for(int i=0; i<str.length(); i++) {
            a.push_back({str[i]-'a'+1, i});
            ans += str[i]-'a'+1;
        }
        if(ans<=p) {
            cout<<str<<endl;
            continue;
        }
        sort(a.begin(), a.end(), cmp);
        for(auto it:a) {
            // cout<<it.first<<' '<<it.second<<endl;
            ans -= it.first;
            vis[it.second] = 1;
            if(ans<=p) {
                break;
            }
        }
        // return 0;
        for(int i=0; i<str.length(); i++) {
            if(!vis[i]) {
                cout<<str[i];
            }
        }
        cout<<endl;
    }
    return 0;
}