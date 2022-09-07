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
    LL n; cin>>n;
    vector<string> a(n+1);
    LL mx = -1;
    string str;
    Fo(i,1,n) {
        cin>>a[i];
        LL num = (LL)atoi(a[i].c_str());
        if(num > mx) {
            mx = num;
            str = a[i];
        }
    } 
    for(int i=0; i<str.length(); i++) {
        queue<string> b[11];
        Fo(j,1,n) {
        	auto it = a[j];
            if(i>=it.length()) {
                b[0].push(it);
            } else {
                b[it[it.length()-i-1]-'0'].push(it);
            }
        }
        LL top = 0;
        Fo(i,0,9) {
            while(!b[i].empty()) {
                a[++top] = b[i].front();
                b[i].pop();
            }
        }
    }
    Fo(i,1,n) cout<<a[i]<<' ';
    return 0;
}
