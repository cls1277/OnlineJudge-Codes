//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 20;
LL n, H, L;

struct Skill {
    LL t, len;
    vector<LL> d;
}a[maxn];

vector<LL> solve(LL x) {
    vector<LL> v;
    LL idx = 1;
    while(x) {
        if(x%2) v.push_back(idx);
        idx++;
        x>>=1;
    }
    return v;
}

bool judge(LL x) {
    Fo(i,0,L) {
    	LL hp = 0;
        vector<LL> b = solve(i);
        LL cur = 0, idx = -1;
        for(int j=0; j<b.size(); j++) {
        	auto it = b[j];
            if(cur+a[it].len-1<=x)
				hp += a[it].d[a[it].len-1];
            else {
                hp += a[it].d[min(x-cur, a[it].len-1)];
                if(cur+a[it].t>x) idx = -1;
                else idx = j;
                cur = x;
                break;
            }
            cur += min(a[it].t, a[it].len-1);
        }
        if(idx!=-1) {
        	for(int j=idx+1; j<b.size(); j++)
        		hp += a[b[j]].d[0];
		}
        if(cur<=x&&hp>=H) {
        	#ifdef DEBUG
 			cout<<x<<' '<<i<<endl;
 			#endif
			return true;       	
		}
    }
    return false;
}

inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

LL sum[(1<<maxn)];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; t=read();//cin>>t;
    while(t--) {
        n=read(); H=read();//cin>>n>>H;
        Fo(i,1,n) a[i].d.clear();
        L=(1<<n)-1;
        LL l=0, r=0;
        Fo(i,1,n) {
            a[i].t=read(); a[i].len=read(); //cin>>a[i].t>>a[i].len;
            r += a[i].t+a[i].len-1;
            Fo(j,1,a[i].len) {
                LL x; x=read(); //cin>>x;
                a[i].d.push_back(x);
            }
            Fo(j,1,a[i].len-1) a[i].d[j] += a[i].d[j-1];
        }
        while(l<r) {
            LL mid = (l+r)>>1;
            if(judge(mid)) r = mid;
            else l = mid+1;
        }
        if(judge(r)) printf("%lld\n",r);
        else printf("-1\n");
    }
    return 0;
}
