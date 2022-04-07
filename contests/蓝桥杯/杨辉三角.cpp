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
unordered_map<LL, LL>mp;
vector<LL>a[2];
LL now, idx;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    mp[1] = 1; mp[2] = 5;
    idx = 0;
    a[0].push_back(1);
    a[0].push_back(2);
    a[0].push_back(1);
    now = 6;
    while(now<=100000) {
        a[idx^1].clear();
        now++;
        a[idx^1].push_back(1);
        for(int i=0; i<a[idx].size()-1; i++) {
            now++;
            a[idx^1].push_back(a[idx][i]+a[idx][i+1]);
            if(!mp[a[idx][i]+a[idx][i+1]]) mp[a[idx][i]+a[idx][i+1]] = now;
        }
        now++;
        a[idx^1].push_back(1);
        idx^=1;
    }
    Fo(i,1,100) {
        cout<<i<<':'<<mp[i]<<endl;
    }
    return 0;
}