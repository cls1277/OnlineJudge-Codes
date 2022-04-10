//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 5e5+5;
LL n;
char s[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL cnt = 0;
        cin>>n; cin>>(s+1);
        LL l=1, r=1;
        while(l+1<=n) {
            if(s[l]=='('||(s[l]==')'&&s[l+1]==')')) l+=2;
            else {
                r = l+1;
                while(r<=n&&s[r]!=')') r++;
                if(r==n+1) break;
                l = r+1;
            }
            cnt++;
        }
        cout<<cnt<<" "<<n-l+1<<endl;
    }
    return 0;
}