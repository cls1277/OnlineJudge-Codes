//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 3e5+5;
LL a[maxn], b[maxn];

bool cmp (LL x, LL y) {
	return x>y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        LL n, mx=0; cin>>n;
        LL cnt1=0, cnt2=0;
        Fo(i,1,n) {
            cin>>a[i];
            mx = max(mx, a[i]);
			b[i] = a[i];
        }
		// mx++;
		LL bmx = mx+1;
        Fo(i,1,n) {
			a[i] = mx-a[i];
			b[i] = bmx-b[i];
		}
        sort(a+1, a+n+1);
		sort(b+1, b+n+1);
		// cout<<a[1];
		// return 0;
        Fo(i,1,n) {
        	if(!a[i]) continue;
        	LL det = cnt1-cnt2;
        	if(det<0) {
        		LL m = -det;
        		if(m<=a[i]) {
        			cnt1 = cnt2;
        			a[i]-=m;
				} else {
					cnt1 += a[i];
					a[i] = 0;
				}
			} else if(det>0) {
				LL m = det*2;
				if(m<=a[i]) {
					cnt2 = cnt1;
					a[i]-=m;
				} else {
					cnt2 += a[i]/2;
					a[i] %= 2;
				}
			}
			if(!a[i]) continue;
			LL k = a[i]/3;
            cnt1 += k;
            cnt2 += k;
            a[i] -= k*3;
            if(!a[i]) continue;
            else if(a[i]==1) cnt1++;
            else cnt2++;
		}
        LL ans = 0;
		ans = 2*min(cnt1, cnt2);
		if(cnt1>cnt2) ans += 2*(cnt1-cnt2)-1;
		if(cnt1<cnt2) ans += 2*(cnt2-cnt1);

		LL res = 0;
		cnt1=0, cnt2=0;
		Fo(i,1,n) {
        	if(!b[i]) continue;
        	LL det = cnt1-cnt2;
        	if(det<0) {
        		LL m = -det;
        		if(m<=b[i]) {
        			cnt1 = cnt2;
        			b[i]-=m;
				} else {
					cnt1 += b[i];
					b[i] = 0;
				}
			} else if(det>0) {
				LL m = det*2;
				if(m<=b[i]) {
					cnt2 = cnt1;
					b[i]-=m;
				} else {
					cnt2 += b[i]/2;
					b[i] %= 2;
				}
			}
			if(!b[i]) continue;
			LL k = b[i]/3;
            cnt1 += k;
            cnt2 += k;
            b[i] -= k*3;
            if(!b[i]) continue;
            else if(b[i]==1) cnt1++;
            else cnt2++;
		}
		res = 2*min(cnt1, cnt2);
		if(cnt1>cnt2) res += 2*(cnt1-cnt2)-1;
		if(cnt1<cnt2) res += 2*(cnt2-cnt1);
        cout<<min(ans, res)<<endl;
    }
    return 0;
}
