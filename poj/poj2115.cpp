//By cls1277
// #include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cctype>
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-7
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

// const LL maxn = ;

LL exgcd(LL a , LL b , LL &x , LL &y) {
    if(!b) {
        x=1; y=0;
        return a;
    }
    LL d=exgcd(b,a%b,x,y);
    LL k=x;
    x=y;
    y=k-a/b*y;
    return d;
}

LL gcd(LL a , LL b) {
    return b?gcd(b,a%b):a;
}

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL A,B,C,k;
    while(cin>>A>>B>>C>>k) {
        if(!A&&!B&&!C&&!k) break;
        k=(1ll<<k);
        LL x,y;
        LL g=gcd(C,k);
        if((B-A)%g) {
            cout<<"FOREVER"<<endl;
            continue;
        }
        k/=g;
        // cout<<k<<" "<<C<<endl;
        LL d=exgcd(C/g,k,x,y);  
        // cout<<x<<" "<<(B-A)/g<<endl;
        // cout<<d<<endl;
        cout<<(x%k*(B-A)/g%k+k)%k<<endl;
    }
    return 0;
}