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
    int T; cin>>T;
    while(T--) {
        string str; cin>>str;
        int a=0, b=0;
        Fo(i,0,2) a+=(str[i]-'0');
        Fo(i,0,2) b+=(str[3+i]-'0');
        if(a==b) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}