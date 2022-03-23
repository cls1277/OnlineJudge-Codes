//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define INF 2147483647
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 2e5+5;

void nxt(string s, int t[]) {
    int p1=0, p2=-1;
    t[0] = -1;
    while(p1<s.length()) {
        if(p2==-1 || s[p1]==s[p1])
            t[++p1] = ++p2;
        else p2 = t[p2];
    }
}

bool KMP(string s1, string s2) {
    int x[s2.length()+5], p1=0, p2=0;
    nxt(s2, x);
    while(p1<s1.length()) {
        if(p2==-1 || s1[p1]==s2[p2]) {
            p1++;
            p2++;
        } else p2 = x[p2];
        if(p2 == s2.length()) {
            //s2在s1中出现的位置是:p1-s2.length()+1
            p2 = x[p2];
            return true;
        }
    }
    return false;
}

LL lst[26], idx;
char str[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        // string str; cin>>str; Ms(lst, 0);
        cin>>(str+1); LL n=strlen(str+1); Ms(lst, 0);
        for(int i=1; i<=n; i++)
            lst[str[i]-'a'] = i;
        idx = n+1;
        Fo(i,0,25)
            if(lst[i])
                idx = min(idx, lst[i]);
        for(int i=idx; i<=n; i++)
            cout<<str[i];
        cout<<endl;
        // LL p=str.length();
        // while(p>=1) {
        //     string str2 = str.substr(0,p);
        //     string str3 = str.substr(p);
        //     if(str2.length()>str3.length()) {
        //         p--; continue;
        //     }
        //     if(KMP(str3, str2)) {
        //         str = str3;
        //         p=str.length();
        //         continue;
        //     } else p--;
        // }
        // cout<<str<<endl;
    }
    return 0;
}