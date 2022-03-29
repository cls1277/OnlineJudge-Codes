//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 2e5+5;
LL n, d, a[maxn], idx;

bool judge(LL x) {
    //idx-1
    LL cnt = 0;
    if(d-a[n]-1>=2*x+1) cnt++;
    if(idx==1) {
        if(a[2]-1>=2*x+1) cnt++;
        if(a[2]-1<x) return false;
        Fo(i,3,n) {
            if(a[i]-a[i-1]-1>=2*x+1) cnt++;
            if(a[i]-a[i-1]-1<x) return false;
        }
        if(!cnt) return false;
        return true;
    }
    Fo(i,1,idx-2) {
        if(a[i]-a[i-1]-1>=2*x+1) cnt++;
        if(a[i]-a[i-1]-1<x) return false;
    }
    if(idx>=2) {
        if(a[idx]-a[idx-2]-1>=2*x+1) cnt++;   
        if(a[idx]-a[idx-2]-1<x) return false;
    }
    Fo(i,idx+1,n) {
        if(a[i]-a[i-1]-1>=2*x+1) cnt++;
        if(a[i]-a[i-1]-1<x) return false;
    }
    if(!cnt) return false;
    return true;
}

bool judge2(LL x) {
    //idx
    LL cnt = 0;
    if(idx==n) {
        if(d-a[n-1]-1>=2*x+1) cnt++;
        Fo(i,1,n-1) {
            if(a[i]-a[i-1]-1>=2*x+1) cnt++;
            if(a[i]-a[i-1]-1,x) return false;
        }
        if(!cnt) return false;
        return true;
    }
    if(d-a[n]-1>=2*x+1) cnt++;
    Fo(i,1,idx-1) {
        if(a[i]-a[i-1]-1>=2*x+1) cnt++;
        if(a[i]-a[i-1]-1<x) return false;
    }
    if(idx-1>=0&&idx+1<=n) {
        if(a[idx+1]-a[idx-1]-1>=2*x+1) cnt++;
        if(a[idx+1]-a[idx-1]-1<x) return false;        
    }
    Fo(i,idx+2,n) {
        if(a[i]-a[i-1]-1>=2*x+1) cnt++;
        if(a[i]-a[i-1]-1<x) return false;
    }
    if(!cnt) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL mn=INT_MAX;
        cin>>n>>d;
        Fo(i,1,n) cin>>a[i];
        Fo(i,1,n) {
            if(a[i]-a[i-1]-1<mn) {
                mn = a[i]-a[i-1]-1;
                idx = i;
            }
        }
        LL l=mn, r=d;
        while(l<r) {
            LL mid=(l+r+1)>>1;
            if(judge(mid)||judge2(mid)) l=mid;
            else r=mid-1;
        }
    }
    return 0;
}