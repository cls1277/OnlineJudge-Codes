//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 5e5+5;
LL a[maxn], n, b[maxn], ans;

void mergeSort(LL l, LL r) {
    if(l>=r) return ;
    LL mid = (l+r)>>1;
    LL i=l, j=mid+1, k=0;
    mergeSort(l, mid);
    mergeSort(mid+1, r);
    while(i<=mid&&j<=r) {
        if(a[i]<=a[j]) b[k++] = a[i++];
        else {
            b[k++] = a[j++];
            ans += mid-i+1;
        }
    }
    while(i<=mid) b[k++] = a[i++];
    while(j<=r) b[k++] = a[j++];
    Fo(ii,l,r) a[ii] = b[ii-l];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(cin>>n&&n) {
        Fo(i,1,n) cin>>a[i];
        ans = 0;
        mergeSort(1, n);
        cout<<ans<<endl;    
    }
    return 0;
}