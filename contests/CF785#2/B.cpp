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
        string str; cin>>str;
        set<char> s; int k=-1;
        bool flag = 0;
        for(int i=0; i<str.length(); i++) {
            char c = str[i];
            if(s.find(c)==s.end()) s.insert(c);
            else {
                k = i;
                break;
            }
        }
        if(k==-1) {
            cout<<"YES"<<endl;
            continue;
        }
        for(int i=k; i<str.length(); i++) {
            if(str[i]!=str[i-k]) {
                flag = 1;
            }
        }
        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}