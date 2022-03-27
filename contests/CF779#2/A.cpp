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

const LL maxn = 10005;
LL ans;
char s[maxn], n[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL l; cin>>l;
        cin>>(s+1); ans=0;
        LL idx = 0;
        Fo(i,1,l) {
            if(i+2<=l&&s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0') {
                n[++idx] = '0';
                n[++idx] = '1';
                n[++idx] = '1';
                n[++idx] = '0';
                ans++;
            } else n[++idx] = s[i];
        }
        l = idx;
        Fo(i,1,l) {
            LL d = 0;
            if(n[i]=='0') {
                d = 1;
                LL j;
                for(j=i+1;j<=l;j++) {
                    if(n[j]=='0') d++;
                    else {
                        i = j-1;
                        break;
                    }
                }
                ans+=2*(d-1);
                if(j==l+1) break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}