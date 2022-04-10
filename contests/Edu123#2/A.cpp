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
        char s[10]; cin>>(s+1);
        bool a=0, b=0, c=0, flag=0;
        Fo(i,1,6) {
            if((s[i]=='R'&&!a)||(s[i]=='B'&&!b)||(s[i]=='G'&&!c)) {
                flag = 1;
                break;
            }
            if(s[i]=='r') a=1;
            if(s[i]=='b') b=1;
            if(s[i]=='g') c=1;
        }
        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}