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
// pair<LL,LL>c[7];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL a, b; cin>>a>>b;
        LL s = sqrt(a*a+b*b);
        if(s==0) cout<<"0"<<endl;
        else if(s*s==a*a+b*b) cout<<"1"<<endl;
        else cout<<"2"<<endl;
    }
    // LL t; cin>>t;
    // c[0]={3,4}; c[1]={8,15}; c[2]={12,35}; c[3]={5,12}; c[4]={20,21}; c[5]={7,24}; c[6]={9,40};
    // while(t--) {
    //     LL a, b; cin>>a>>b;
    //     pair<pair<LL,LL>,LL> d={{0,0},0};
    //     queue<pair<pair<LL,LL>,LL>>q;
    //     q.push(d);
    //     while(!q.empty()) {
    //         pair<pair<LL,LL>,LL> u=q.front(); q.pop();
    //         if(u.first.first==a&&u.first.second==b) {
    //             cout<<u.second<<endl;
    //             break;
    //         }
    //         Fo(i,0,6) {
    //             if(u.first.first+c[i].first>a) continue;
    //             if(u.first.second+c[i].second>b) continue;
    //             q.push({{u.first.first+c[i].first, u.first.second+c[i].second}, u.second+1});
    //         }
    //         Fo(i,0,6) {
    //             if(u.first.first+c[i].second>a) continue;
    //             if(u.first.second+c[i].first>b) continue;
    //             q.push({{u.first.first+c[i].second, u.first.second+c[i].first}, u.second+1});
    //         }
    //     }
    // }
    return 0;
}