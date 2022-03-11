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

const LL maxn = 105;
LL n, m;
string mp[maxn], b[maxn];
struct Pair {
    LL a, b, c, d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        vector<Pair>a;
        cin>>n>>m;
        Fo(i,0,n-1) cin>>mp[i];
        Fo(i,0,n-1)
            Fo(j,0,m-1)
                b[i][j] = '0';
        bool flag = false;
        Fo(i,0,n-1) {
            if(mp[i][0]=='1') {
                if(m>1) {
                    if(mp[i][1]=='1') {
                        flag = true;
                        break;
                    }
                }
                if(i-1<0) {
                    flag = true;
                    break;
                }
                if(mp[i-1][1]!='1') {
                    flag = true;
                    break;
                }
                b[i][0] = b[i-1][1] = '1';
                b[i-1][0] = b[i][1] = '0';
                a.push_back({i,1,i+1,2});
            }
        }
        if(flag) {
            cout<<"-1"<<endl;
            continue;
        }
        Fo(i,0,n-1) {
            Ro(j,m-1,1) {
                if(mp[i][j]=='1'&&b[i][j]=='0') {
                    a.push_back({i+1,j,i+1,j+1});
                    b[i][j-1] = '0';
                }
            }
        }
        cout<<a.size()<<endl;
        for(auto &it:a)
            cout<<it.a<<" "<<it.b<<" "<<it.c<<" "<<it.d<<endl;
    }
    return 0;
}