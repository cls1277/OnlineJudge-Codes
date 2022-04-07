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
int num[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool run(LL x) {
    return (x%4==0&&x%100!=0)||(x%100==0&&x%400==0);
}

bool check1(LL x) {
    LL a = x%10000, b = x/10000, c = 0;
    while(b) {
        c = c*10+b%10;
        b/=10;
    }
    return a==c;
}

bool check2(LL x) {
    LL a = x%100; x/=100;
    LL b = x%100; x/=100;
    LL c = x%100; x/=100;
    LL d = x%100;
    if(a!=b||c!=d) return false;
    LL e = 0;
    while(c) {
        e = e*10+c%10;
        c/=10;
    }
    return a==e;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL n; cin>>n;
    bool f1=0, f2=0;
    LL ans1, ans2;
    while(1) {
        n++;
        LL month = n/100%100;
        LL day = n%100;
        LL year = n/10000;
        // cout<<month<<' '<<day<<' '<<year<<' '<<run(year);
        // break;
        if(month<1||month>12) continue;
        if(month!=2) {
            if(day>num[month]) continue;
        } else {
            bool is = run(year);
            if(is&&day>29) continue;
            if(!is&&day>28) continue;
        }
        // cout<<"1";
        // break;
        if(!f1) {
            if(check1(n)) {
                f1 = 1;
                ans1 = n;
            }
        }
        if(!f2) {
            if(check2(n)) {
                f2 = 1;
                ans2 = n;
            }
        }
        if(f1&&f2) {
            cout<<ans1<<endl<<ans2;
            return 0;
        }
        // break;
    }
    return 0;
}