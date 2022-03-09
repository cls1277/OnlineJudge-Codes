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

// const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        string a,s; cin>>a>>s;
        string ans="";
        LL len1=a.length()-1, len2=s.length()-1;
        LL idx = len2;
        Ro(i,len1,0) {
            // cout<<s[idx]<<" "<<a[i]<<endl;
            // cout<<(s[idx]>a[i])<<endl;
            if(s[idx]<a[i]) {
                if(idx-1<0) {
                    ans="1-";
                    break;
                }
                LL b=(s[idx-1]-'0')*10+s[idx]-'0', c=a[i]-'0';
                LL d = b-c;
                if(d>=10||d<0) {
                    ans="1-";
                    break;
                }
                ans += (d+'0');
                idx-=2;
            } else {
                LL b=s[idx]-'0', c=a[i]-'0';
                ans += (b-c+'0');
                // cout<<ans<<endl;
                idx--;
            }
        }
        // cout<<idx<<endl;
        if(idx!=-1&&ans!="1-") {
            string temp = s.substr(0,idx+1);    
            reverse(temp.begin(),temp.end());
            ans+=temp;
        }
            // ans += s.substr(0,idx+1);
        // cout<<ans<<endl;
        if(ans=="1-") {
            cout<<"-1"<<endl;
            continue;
        }
        Ro(i,ans.length()-1,0) {
            if(ans[i]!='0') {
                ans.erase(i+1);
                break;        
            }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}