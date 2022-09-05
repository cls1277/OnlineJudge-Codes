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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL E, L, R, B; cin>>E>>L>>R>>B;
        LL n = E+L+R+B, idx=0;
        vector<pair<LL, LL>> a(n+1);
        Fo(i,1,E) a[++idx] = {0, 0};
        Fo(i,1,L) a[++idx] = {1, 0};
        Fo(i,1,R) a[++idx] = {0, 1};
        Fo(i,1,B) a[++idx] = {1, 1};
        vector<LL> b;
        Fo(i,1,n) b.push_back(i);
        LL mn = n, mx = 0;
        do {
            stack<pair<LL, LL>> s;
            for(auto it:b) {
                if(s.empty()) {
                    s.push(a[it]);
                    continue;
                }
                pair<LL, LL> now = a[it];
                while(1) {
                    if(s.empty()) {
                        s.push(now);
                        break;
                    }
                    pair<LL, LL> u = s.top();
                    if(u.second==1&&now.first==1) {
                        s.pop();
                        now.first = u.first;
                    } else {
                        s.push(now);
                        break;
                    }
                }
            }
            mn = min(mn, LL(s.size()));
            mx = max(mx, LL(s.size()));
        }while(next_permutation(b.begin(), b.end()));
        cout<<mn<<' '<<mx<<endl;
    }
    return 0;
}