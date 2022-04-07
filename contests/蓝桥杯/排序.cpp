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
vector<char>e;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    Fo(i,0,25) e.push_back('a'+i);
    do {
        LL cnt = 0;
        for(int i=0; i<26; i++)
            for(int j=i+1; j<26; j++) {
                if(e[j]<e[j-1]) {
                    swap(e[j-1], e[j]);
                    cnt++;
                }
            }
        if(cnt==100) {
            for(auto c:e) cout<<c;
        }
    }while(next_permutation(e.begin(), e.end()));
    return 0;
}