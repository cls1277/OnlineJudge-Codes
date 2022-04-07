//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e3+5;
char s[maxn];
unordered_map<LL, LL>cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>(s+1);
    LL len = strlen(s+1);
    Fo(i,1,len) {
        cnt[s[i]-'a']++;
    }
    LL idx = 0;
    Fo(i,1,25) {
        if(cnt[i]>cnt[idx])
            idx = i;
    }
    cout<<char('a'+idx)<<endl<<cnt[idx];
    return 0;
}