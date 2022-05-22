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
        string s; cin>>s;
        int now = -1, cnt = 0;
        bool flag = 1;
        for(int i=0; i<s.length(); i++) {
            if(now==-1) {
                // cnt[s[i]]++;
                cnt++;
                now = s[i]-'a';
                continue;
            }
            if(s[i]==now+'a') {
                // cnt[s[i]]++;
                cnt++;
                continue;
            } else {
                now = s[i]-'a';
                int temp = cnt;
                cnt = 1;
                if(temp<=1) {
                    flag = 0;
                    break;
                }
            }
        }
        if(cnt<=1) flag = 0;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}