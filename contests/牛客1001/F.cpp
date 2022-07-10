//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 250005;
LL a[maxn], a2[maxn], b[maxn], ans, ans2, n;

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

void mergeSort2(LL l, LL r) {
    if(l>=r) return ;
    LL mid = (l+r)>>1;
    LL i=l, j=mid+1, k=0;
    mergeSort2(l, mid);
    mergeSort2(mid+1, r);
    while(i<=mid&&j<=r) {
        if(a2[i]<=a2[j]) b[k++] = a2[i++];
        else {
            b[k++] = a2[j++];
            ans2 += mid-i+1;
        }
    }
    while(i<=mid) b[k++] = a2[i++];
    while(j<=r) b[k++] = a2[j++];
    Fo(ii,l,r) a2[ii] = b[ii-l];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(cin>>n&&n) {
        LL idx = 0, idx2 = 0;
        Fo(i,1,n*n) {
            LL x; cin>>x;
            if(x) a[++idx] = x;
        }
        ans = ans2 = 0;
        mergeSort(1, idx);
        Fo(i,1,n*n) {
            LL x; cin>>x;
            if(x) a2[++idx2] = x;
        }
        mergeSort2(1, idx2);
        if(ans%2==ans2%2) cout<<"TAK"<<endl;
        else cout<<"NIE"<<endl;
    }
    return 0;
}