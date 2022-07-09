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
        int n; cin>>n;
        string str; cin>>str;
        char pre=str[0]; int ans=1, l=0, r=0;
        for(int i=1; i<str.length(); i++) {
            if(str[i]!=pre) {
                if(n%2) {
                    if(l<=n/2&&r>=n/2) {
                        ans = r-l+1;
                        cout<<ans<<endl;
                        break;
                    }
                } else {
                    if(l<=n/2-1&&r>=n/2) {
                        ans = r-l+1;
                        cout<<ans<<endl;
                        break;
                    }
                }
                l = r = i;
                pre = str[i];
            } else {
                r++;
            }
        }
        if(l==0&&r==n-1) {
            cout<<n<<endl;
        }
    }
    return 0;
}