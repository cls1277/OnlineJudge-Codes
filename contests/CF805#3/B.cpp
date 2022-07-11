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
LL n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    Fo(i,1,n) {
        LL ans = 1;
        string str; cin>>str;
        LL cnt = 0; char ch[4];
        for(int j=0; j<str.length(); j++) {
            char c = str[j];
            bool flag = 1;
            for(int k=1; k<=cnt; k++) {
                if(ch[k]==c) {
                    flag = 0;
                    break;
                }
            }
            if(flag) {
            	cnt++;
                if(cnt==4) {
                    ch[1] = c;
                    cnt = 1;
                    ans++;
                }
                ch[cnt] = c;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
