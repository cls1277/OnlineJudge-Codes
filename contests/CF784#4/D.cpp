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
    string str; LL n;
    while(t--) {
        cin>>n; cin>>str;
        LL cnt1=0, cnt2=0;
        bool flag = 0;
        for(int i=0; i<n; i++) {
            if(str[i]=='R') cnt1++;
            if(str[i]=='B') cnt2++;
            if(str[i]=='W') {
                if((cnt1&&!cnt2)||(cnt2&&!cnt1)) {
                    cout<<"NO"<<endl;   
                    flag = 1;
                    break;
                }
                cnt1 = 0; cnt2 = 0;
            }
        }
        // cout<<cnt1<<' '<<cnt2<<endl;
        if(flag) continue;
        if((cnt1&&!cnt2)||(cnt2&&!cnt1)) {
            cout<<"NO"<<endl;
            flag = 1;
        }
        if(!flag) cout<<"YES"<<endl;
    }
    return 0;
}