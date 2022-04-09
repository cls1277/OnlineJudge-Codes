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
vector<LL>v[20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    freopen("out3.txt","w",stdout);
    #endif
    fstream in1; in1.open("out.txt");
    fstream in2; in2.open("out1.txt");
    Fo(i,0,32767) {
        LL a, b, c, d;
        in1>>a>>b;
        in2>>c>>d;
        // if(b!=d) cout<<"b["<<a<<"]="<<b<<";"<<endl;
        if(b!=d) {
            v[b].push_back(a);
        }
    }
    // cout<<v[15].size();
    // return 0;
    Fo(i,1,15) {
        for(auto j:v[i])
            cout<<"b["<<j<<"]=";
        cout<<i<<";"<<endl;
    }
    return 0;
}