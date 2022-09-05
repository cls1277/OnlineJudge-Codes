//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//const LL maxn = ;
unordered_map<string, LL> mp;

bool judge(string s) {
    LL n = s.length();
    if(!n) return false;
    LL mid = n>>1, i, j;
	for(i=n-1,j=0; j<mid; i--,j++){
		if(s[i]!=s[j])
            return false;
	} 
    return true;
}

void solve(string s) {
    unordered_set<string> st;
    LL n = s.length();
    Fo(i,0,n-1) {
        for(int j=1; i+j<=n; j++) {
            string ss = s.substr(i, j);
            // cout<<ss<<endl;
            if(judge(ss)) {
                st.insert(ss);
            }
        }
    }
    for(auto it:st) mp[it]++;
}

int main() {
//    freopen("G.in","r",stdin);
//	freopen("G.out","w",stdout); 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    Fo(_t,1,t) {
        string str; cin>>str;
        solve(str);
    }
    LL ans = 0;
    for(auto it:mp)
        if(it.second==t) {
            // cout<<it.first<<endl;
            ans++;
        }
    cout<<ans;
    return 0;
}
