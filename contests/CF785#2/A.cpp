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

LL getans(string str) {
    // if(!str.length()) return 0;
    LL res = 0;
    for(int i=0; i<str.length(); i++) {
        res += (str[i]-'a')+1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    int t; cin>>t;
    while(t--) {
        string str; cin>>str;
        if(str.length()%2==0) {
            cout<<"Alice "<<getans(str)<<endl;
        } else {
            LL a=getans(str.substr(0,str.length()-1)), b=getans(str.substr(1,str.length()-1));
            // cout<<a<<' '<<b<<endl;
            if(a>b) {
                LL d = str[str.length()-1]-'a'+1;
                if(a<d) {
                    cout<<"Bob ";
                } else {
                    cout<<"Alice ";
                }
                cout<<abs(a-d)<<endl;
            } else {
                LL d = str[0]-'a'+1;
                if(b>d) {
                    cout<<"Alice ";
                } else {
                    cout<<"Bob ";
                }
                cout<<abs(b-d)<<endl;
            }
        }
    }
    return 0;
}