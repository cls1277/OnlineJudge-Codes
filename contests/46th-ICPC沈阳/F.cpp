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

// const LL maxn = 1e3+5;
string a;
LL n;
vector<string>c;

int main() {
    // ios::sync_wi th_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    cin>>a;
    for(int i=0; i<n; i++) {
        string b=a.substr(0,i+1);
        LL cnt = -1;
        map<char,char>mp;
        for(int j=b.length()-1; j>=0; j--) {
            if(mp[b[j]]) continue;
            cnt++;
            mp[b[j]] = cnt+'a';
        }
        for(int j=0; j<b.length(); j++)
            b[j] = mp[b[j]];
        // cout<<b<<endl;
        c.push_back(b);
    }
    sort(c.begin(), c.end());
    cout<<c[c.size()-1];
    return 0;
}