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
        LL n; cin>>n;
        map<string, bool> vis;
        vector<string> a;
        Fo(i,1,n) {
            string str; cin>>str;
            a.push_back(str);
            vis[str] = 1;
        }
        for(auto str:a) {
            bool flag = 0;
            for(int i=1; i<str.length(); i++) {
                string b = str.substr(0, i), c = str.substr(i);
                // cout<<b<<' '<<c<<endl;
                if(vis[b]&&vis[c]) {
                    flag = 1;
                    break;
                }
            }
            cout<<flag;
        }
        cout<<endl;
    }
    return 0;
}