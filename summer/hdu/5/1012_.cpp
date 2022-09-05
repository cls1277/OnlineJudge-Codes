//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 2e5+5;
#define ls x<<1
#define rs x<<1|1

inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

struct Ans {
    LL idx, sum;
};

Ans operator + (const Ans &x, const Ans &y) {
    if(x.sum==y.sum) {
        if(x.idx<y.idx) return x;
        else return y;
    } else {
        if(x.sum<y.sum) return x;
        else return y;
    }
}

struct Seg {
	LL l, r;
    Ans s;
};
Seg tree[maxn<<2];
LL n , m;


void pushup(LL x) {
    tree[x].s = tree[ls].s + tree[rs].s;
}

void build(LL x , LL l , LL r) {
	tree[x].l = l;
	tree[x].r = r;
	if(l==r) {
		tree[x].s = {l, 0};
		return ;
	}
	LL mid = (l+r)>>1;
	build(x<<1 , l , mid);
	build(x<<1|1 , mid+1 , r);
	pushup(x);
}

void update(LL x , LL l , LL r , LL val) {
	if(l<=tree[x].l&&r>=tree[x].r) {
        tree[x].s.sum += val;
		return ;
	}
	LL mid = (tree[x].l+tree[x].r)>>1;
	if(l<=mid)
		update(x<<1 , l , r , val);
	if(r>mid)
		update(x<<1|1 , l , r , val);
	pushup(x);
}

Ans query(LL x , LL l , LL r) {
	if(l<=tree[x].l&&r>=tree[x].r)
        return tree[x].s;
	LL mid = (tree[x].l+tree[x].r)>>1;
    Ans ans = {INT_MAX, INT_MAX};
	if(l<=mid)
		ans = ans + query(x<<1 , l , r);
	if(r>mid)
		ans = ans + query(x<<1|1 , l , r);
	return ans;
}

#define pii pair<LL, LL>

pii a[maxn];

struct Que1 {
    LL first, second;
};

bool operator < (const Que1&x, const Que1&y) {
    if(x.first==y.first) return a[x.second].first+a[x.second].second>a[y.second].first+a[y.second].second;
    return x.first>y.first;
}

struct Que2 {
    LL first, second;
};

bool operator < (const Que2&x, const Que2&y) {
    if(x.first==y.first) return a[x.second].first>a[y.second].first;
    return x.first>y.first;
}

LL _time[maxn], idxx[maxn];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; t=read(); //cin>>t;
    while(t--) {
        n=read(); m=read(); // cin>>n>>m;
        priority_queue<Que1> q1;
        priority_queue<Que2> q2;
        Fo(i,1,n) idxx[i] = 0;
        Fo(i,1,m) _time[i] = 0;
        build(1, 1, m);
        Fo(i,1,n) {
            LL x, y; x=read(); y=read(); //cin>>x>>y;
            a[i] = {x, y};
            q1.push({x, i});
            q2.push({x+y, i});
        }
        while(!q1.empty()&&!q2.empty()) {
            Que1 u1=q1.top();
            Que2 u2=q2.top();
            if(u1.first<u2.first) {
                q1.pop();
                Ans res = query(1, 1, m);
                idxx[u1.second] = res.idx;
                update(1, res.idx, res.idx, 1);
            } else if(u1.first>u2.first) {
                q2.pop();
                update(1, idxx[u2.second], idxx[u2.second], -1);
                _time[idxx[u2.second]] = max(_time[idxx[u2.second]], a[u2.second].first)+a[u2.second].second;
            } else if(u1.first==u2.first) {
                q1.pop(); q2.pop();
                update(1, idxx[u2.second], idxx[u2.second], -1);
                _time[idxx[u2.second]] = max(_time[idxx[u2.second]], a[u2.second].first)+a[u2.second].second;
                Ans res = query(1, 1, m);
                idxx[u1.second] = res.idx;
                update(1, res.idx, res.idx, 1);  
            }
        }
        while(!q2.empty()) {
            Que2 u2 = q2.top(); q2.pop();
            update(1, idxx[u2.second], idxx[u2.second], -1);
            _time[idxx[u2.second]] = max(_time[idxx[u2.second]], a[u2.second].first)+a[u2.second].second;
        }
        LL ans = -INT_MAX;
        Fo(i,1,m) ans = max(ans, _time[i]);
        // cout<<ans<<endl;
        printf("%lld\n",ans);
    }
    return 0;
}
