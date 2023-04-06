// //By cls1277
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long LL;
// #define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
// #define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
// #define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
// #define Ms(a,b) memset((a),(b),sizeof(a))
// #define endl '\n'

// //const LL maxn = ;

// LL gcd(LL x, LL y) {
//     return y?gcd(y, x%y):x;
// }

// vector<LL> a[1005];
// unordered_map<LL, vector<LL>> b;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     #ifdef DEBUG
//     freopen("data.txt","r",stdin);
//     #endif
//     // LL n = 100;
//     // Fo(x,1,100) {
//     for(LL x=1; x<=1000; x++) {
//         LL n = x;
//         LL cnt = 0;
//         Fo(i,1,n) {
//             // cout<<i<<" "<<((i*x)^(x))<<endl;
//             LL k = (i*x)^(x);
//             LL g = gcd(k, x);
//             if(g==1) {
//                 cnt++;
//                 b[x].push_back(i);
//                 // cout<<i<<' ';
//             }
//         }
//         // cout<<x<<':'<<cnt<<endl;
//         a[cnt].push_back(x);
//     }
//     Fo(i,1,20) {
//         if(a[i].size()<=1) continue;
//         cout<<i<<":"<<endl;
//         for(auto it:a[i]) {
//             cout<<it<<"::";
//             for(auto it2:b[it]) {
//                 cout<<it2<<' ';
//             }
//             cout<<endl;
//         }
//         cout<<endl;
//     }
//     // for(auto it:b[11]) cout<<it<<' ';
//     // cout<<endl;
//     // for(auto it:b[13]) cout<<it<<' ';
//     // Fo(i,1,1000) {
//     //     if(a[i].size()==0) continue;
//     //     cout<<i<<":";
//     //     for(auto it:a[i]) {
//     //         cout<<it<<' ';
//     //     }
//     //     cout<<endl;
//     // }
//     return 0;
// }

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

LL gcd(LL x, LL y) {
    return y?gcd(y, x%y):x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL x = 15;
    Fo(i,1,200) {
        LL k = (i*x)^x;
        LL g = gcd(k, x);
        cout<<i<<":"<<g<<endl;
    }
    return 0;
}