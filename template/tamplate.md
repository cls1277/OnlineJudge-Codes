# datastruct

```c++
//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

const LL maxn = 1e3+5;

#define ls x<<1
#define rs x<<1|1

//线段树相关

struct Seg {
	LL l , r , sum , lazy;
};
Seg tree[maxn<<2];
LL n , m , data[maxn];

void pushup(LL num) {
	tree[num].sum = tree[num<<1].sum+tree[num<<1|1].sum;
}

void pushdown(LL num) {
	tree[num<<1].lazy += tree[num].lazy;
	tree[num<<1|1].lazy += tree[num].lazy;
	tree[num<<1].sum += (tree[num<<1].r-tree[num<<1].l+1)*tree[num].lazy;
	tree[num<<1|1].sum += (tree[num<<1|1].r-tree[num<<1|1].l+1)*tree[num].lazy;
	tree[num].lazy = 0;
}

//乘 和 加的时候这样写：先乘后加
/*
void pushdown(LL x) {
	tree[ls].sum=(tree[ls].sum*tree[x].mul%mod+tree[x].add*(tree[ls].r-tree[ls].l+1)%mod)%mod;
	tree[rs].sum=(tree[rs].sum*tree[x].mul%mod+tree[x].add*(tree[rs].r-tree[rs].l+1)%mod)%mod;
	tree[ls].mul=tree[ls].mul*tree[x].mul%mod;
	tree[rs].mul=tree[rs].mul*tree[x].mul%mod;
	tree[ls].add=(tree[ls].add*tree[x].mul%mod+tree[x].add)%mod;
	tree[rs].add=(tree[rs].add*tree[x].mul%mod+tree[x].add)%mod;	
	tree[x].add=0; tree[x].mul=1;
	return ;
}
*/

void build(LL num , LL l , LL r) {
	tree[num].l = l;
	tree[num].r = r;
	if(l==r) {
		tree[num].sum = data[l];
		return ;
	}
	LL mid = (l+r)>>1;
	build(num<<1 , l , mid);
	build(num<<1|1 , mid+1 , r);
	pushup(num);
}

void update(LL num , LL l , LL r , LL val) {
	if(l<=tree[num].l&&r>=tree[num].r) {
		tree[num].lazy += val;
		tree[num].sum += (tree[num].r-tree[num].l+1)*val;
		return ;
	}
	pushdown(num);
	LL mid = (tree[num].l+tree[num].r)>>1;
	if(l<=mid)
		update(num<<1 , l , r , val);
	if(r>mid)
		update(num<<1|1 , l , r , val);
	pushup(num);
}

LL query(LL num , LL l , LL r) {
	if(l<=tree[num].l&&r>=tree[num].r)
		return tree[num].sum;
	pushdown(num);
	LL mid = (tree[num].l+tree[num].r)>>1 , ans = 0;
	if(l<=mid)
		ans+=query(num<<1 , l , r);
	if(r>mid)
		ans+=query(num<<1|1 , l , r);
	return ans;
}

//ST表

LL st[maxn][30], lg[maxn];

void st_init() {
    for(int i=1; i<=n; i++) st[i][0] = data[i];
	for(int i=1; (1<<i)<=n; i++)
		for(int j=1; j+(1<<i-1)<=n; j++)
			st[j][i] = max(st[j][i-1] , st[j+(1<<i-1)][i-1]);
	for(int i=1; i<=n; i++) lg[i] = log2(i);
}

LL st_query(LL l , LL r) {
	LL k = lg[r-l+1];
	return max(st[l][k] , st[r-(1<<k)+1][k]);
}

//单调队列(滑动窗口，窗口大小k)

#define k 3

struct Que {
    LL ops , num;
};
deque<Que>q1;
deque<Que>q2;

void solo_queue() {
    LL maxx[maxn], minn[maxn], cnt=0;
    for(int i=1; i<=n; i++) {
        cin>>m;
        while(!q1.empty()&&m>=q1.back().num)
            q1.pop_back();
        q1.push_back({i,m});
        while(i-k+1>q1.front().ops)
            q1.pop_front();
        while(!q2.empty()&&m<=q2.back().num)
            q2.pop_back();
        q2.push_back({i,m});
        while(i-k+1>q2.front().ops)
            q2.pop_front();
        if(i>=k) {
            cnt++;//记录了划过的窗口数
            maxx[cnt] = q1.front().num;
            minn[cnt] = q2.front().num;
        }
    }
}

// 树状数组
// https://blog.csdn.net/bestsort/article/details/80796531
// 注意下标是从1开始的

#define lowbit(_) _&(-_)
LL c[maxn];

// 单点更新 区间查询
void update(LL x , LL y) {
	while(x<=n) {
		c[x]+=y;
		x+=lowbit(x);
	}
}

LL sum(LL x) {
	if(x<=0) return 0;
	LL ans = 0;
	while(x) {
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

/*
逆序对
Fo(i,1,n) {
	update(a[i], 1);
	res += i-sum(a[i]);
}
*/

// 区间更新
void rangeUpdate(LL l, LL r, LL x) {
    update(l, x);
    update(r+1, -x);
}

// 二维树状数组
LL nx, ny, bit[maxn][maxn];

void update(LL x, LL y, LL z) {
    for(int i=x; i<=nx; i+=lowbit(i))
        for(int j=y; j<=ny; j+=lowbit(j))
            bit[i][j] += z;
}

LL sum(LL x, LL y) {
    LL res = 0;
    for(int i=x; i>0; i-=lowbit(i))
        for(int j=y; j>0; j-=lowbit(j))
            res +=bit[i][j];
    return res;
}

// (a,b)和(c,d)之间二维矩阵和
LL ask(LL a, LL  b, LL c, LL d) {
    return sum(c, d)-sum(a-1, d)-sum(c, b-1)+sum(a-1, b-1);
}

// 扫描线面积

struct ScanLineS {
	// 在常规线段树开4倍空间下，扫描线要开8倍
	// https://www.luogu.com.cn/discuss/411005
	static const LL maxn = 4e5+5;
	LL n, xx[maxn];
	struct Line {
		LL x1, x2, y, flag;
		bool operator < (const Line & x) {
			return y<x.y;
		}
	}l[maxn];

	struct Seg {
		LL l, r, sum, len;
	} tree[maxn<<2];

	void build(LL x, LL l, LL r) {
		tree[x].l=l; tree[x].r=r;
		tree[x].sum = tree[x].len = 0;
		if(l==r) return ;
		LL mid = (l+r)>>1;
		build(ls, l, mid);
		build(rs, mid+1, r);
	}

	void updateLen(LL x) {
		if(tree[x].sum) tree[x].len = xx[tree[x].r+1]-xx[tree[x].l];
		else tree[x].len = tree[ls].len+tree[rs].len;
	}

	void update(LL x, LL l, LL r, LL flag) {
		if(l>=xx[tree[x].r+1]||r<=xx[tree[x].l]) return ;
		if(l<=xx[tree[x].l]&&r>=xx[tree[x].r+1]) {
			tree[x].sum += flag;
			updateLen(x);
			return ;
		}
		update(ls, l, r, flag);
		update(rs, l, r, flag);
		updateLen(x);
	}
	void main() {
		cin>>n;
		Fo(i,1,n) {
			LL a, b, c, d; cin>>a>>b>>c>>d;
			l[2*i-1] = {a, c, b, 1};
			l[2*i] = {a, c, d, -1};
			xx[2*i-1] = a;
			xx[2*i] = c;
		}
		n<<=1;
		sort(l+1, l+n+1);
		sort(xx+1, xx+n+1);
		LL tot = unique(xx+1, xx+n+1)-xx-1;
		build(1, 1, tot-1);
		LL ans = 0;
		Fo(i,1,n-1) {
			update(1, l[i].x1, l[i].x2, l[i].flag);
			ans += tree[1].len*(l[i+1].y-l[i].y);
		}
		cout<<ans;
	}
};
```

# dp

```c++
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>

using std::min;
using std::max;
using std::cin;
using std::vector;

typedef long long LL;

const LL maxn = 1e3+5;

LL n, f[maxn], w[maxn], v[maxn], W;

//01背包：一个物品可以取或者不取
void zero_one() {
    for(int i=1; i<=n; i++)
        for(int j=W; j>=w[i]; j--)
            f[j] = max(f[j], f[j-w[i]]+v[i]);
}

//完全背包：一个物品可以取无限次
void full_bags() {
    for(int i=1; i<=n; i++)
        for(int j=w[i]; j<=W; j++)
            f[j] = max(f[j], f[j-w[i]]+v[i]);
}

//多重背包：每种物品不止1个，有k个
//二进制分组优化：1个、2个、4个……合为一个物品，跑01背包
void mul_bags() {
    LL idx = 0;
    for(int i=1; i<=n; i++) {
        LL x, y, z; cin>>x>>y>>z;
        LL k=1;
        while(z>=k) {
            idx++;
            v[idx] = x*k;
            w[idx] = y*k;
            z-=k;
            k<<=1;
        }
        if(z) {
            idx++;
            v[idx] = x*z;
            w[idx] = y*z;
        }
    }
    for(int i=1; i<=idx; i++)
        for(int j=W; j>=w[i]; j--)
            f[j]=max(f[j], f[j-w[i]]+v[i]);
}

//混合背包：三种背包混合起来，有的只能取一次，有的能取无限次，有的只能取k次。
//取k次的又可以跑01背包，所以本质上就是01背包+完全背包，注意两个顺序别搞反了就可以
void mix_bags() {
    vector<LL>v[2];
    vector<LL>w[2]; //0：01背包；1：完全背包
    for(int i=1; i<=n; i++) {
        LL x, y, z; cin>>x>>y>>z;
        if(!z) {
            v[1].push_back(y);
            w[1].push_back(x);
        } else if(z==1) {
            v[0].push_back(y);
            w[0].push_back(x);
        } else {
            LL k=1;
            while(z>=k) {
                v[0].push_back(y*k);
                w[0].push_back(x*k);
                z-=k;
                k<<=1;
            }
            if(z) {
                v[0].push_back(y*z);
                w[0].push_back(x*z);
            }
        }
    }
    LL x = v[0].size()-1;
    for(int i=0; i<=x; i++)
        for(int j=W; j>=w[0][i]; j--)
            f[j] = max(f[j], f[j-w[0][i]]+v[0][i]);
    x = v[1].size()-1;
    for(int i=0; i<=x; i++)
        for(int j=w[1][i]; j<=W; j++)
            f[j] = max(f[j], f[j-w[1][i]]+v[1][i]);
}

//二维费用背包：会消耗两种价值，而不是一个w了，即w是二维数组
void twoD_bags() {
    LL a[maxn], b[maxn];//两种价值
    LL f[maxn][maxn];
    LL A, B;//两种价值限制
    for(int i=1; i<=n; i++)
        for(int j=A; j>=a[i]; j--)
            for(int k=B; k>=b[i]; k--)
                f[j][k] = max(f[j][k], f[j-a[i]][k-b[i]]+v[i]);
}

//分组背包：物品分组，每组物品相互冲突，最多只能选一个物品进去
void group_bags() {
    LL a[maxn], b[maxn], g;//g是分的组数
    vector<LL>c[maxn];//存储每一组中物品编号
    for(LL i=1; i<=n; i++) {
        cin>>a[i]>>b[i];
        LL x; cin>>x;
        c[x].push_back(i);
        g = max(g, x);
    }
    for(int i=1; i<=g; i++)
        for(int j=W; j>=0; j--)
            for(auto &it:c[i])
                if(j>=a[it])
                    f[j] = max(f[j], f[j-a[it]]+b[it]);
}

//有依赖的背包：有主件和附件，选择附件必须选择主件
/*
对于包含一个主件和若干个附件的集合有以下可能性：
仅选择主件，选择主件后再选择一个附件，选择主件后再选择两个附件……
需要将以上可能性的容量和价值转换成一件件物品。因为这几种可能性只能选一种，所以可以将这看成分组背包。
*/

vector<LL>res;//临时存一下选择的物品的编号
vector<LL>son[maxn];
vector<LL>g[maxn];//存储每一个组内的物品（分为每一种可能之后）
LL idx, d;//idx:对每一种可能性编号 d:分的组数
LL vm[maxn], wm[maxn];//每一种可能的价值和花费

void dfs(LL x, LL k, LL id) {
    if(x==k+1) {
        LL a=0, b=0;
        for(auto &it:res) {
            a+=v[son[id][it]];
            b+=w[son[id][it]];
        }
        idx++;
        vm[idx]=a+v[id]; wm[idx]=b+w[id];
        g[d].push_back(idx);
        return ;
    }
    res.push_back(x);
    dfs(x+1, k, id);
    res.pop_back();
    dfs(x+1, k, id);
}

void depend_bags() {
    LL c[maxn], d=0;
    for(int i=1; i<=n; i++) {
        LL x, y, z; cin>>x>>y>>z;
        v[i] = x*y;
        w[i] = x;
        c[i] = z;//表示编号z是编号i的主件
        if(z) son[z].push_back(i); //son[x]:x的附件的集合
    }
    for(int i=1; i<=n; i++) {
        if(son[i].size()) {
            d++;
            res.clear();
            dfs(0, son[i].size()-1, i);
        } else if(!c[i]){
            d++; idx++;
            vm[idx] = v[i];
            wm[idx] = w[i];
            g[d].push_back(idx);
        }
    }
    //分组背包
    for(int i=1; i<=d; i++)
        for(int j=W; j>=0; j--)
            for(auto &it:g[i])
                if(j>=wm[it])
                    f[j] = max(f[j], f[j-wm[it]]+vm[it]);
}
```

# else

```c++
/*

开太多long long容易T
如果int相乘放到long long中，最好再乘1ll
函数中的数组不要太大，不然容易内存过大而RE
模板自带long long，如果需要的话，分析数据规模改一些为int
memset() 不要带全部，用多少清空多少，还要看不清空是否《肯定》没影响
易错、讨论、卡常等：https://blog.csdn.net/WerKeyTom_FTD/article/details/50437196

*/

//对拍程序
/*

@echo off  
:loop  
    rand.exe>data.txt  
    my.exe<data.txt>my.out  
    std.exe<data.txt>std.out  
    fc my.out std.out  
if not errorlevel 1 goto loop  
pause  
goto loop

*/

//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647

//上面这个可以写成
#define INF INT_MAX

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

const LL maxn = 1e3+5;

/*
int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	return 0;
}
*/

// 程序运行时间
void calcRunTime() {
    clock_t start, finish;
    double totaltime;
    start = clock();
   
    //...

    finish = clock();
    totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
}

// 卡常
#pragma-GCC-optimize("-Ofast");

bool judge(int x) {
    //写二分的判断
}

// 整数域中>>1比/2要好！
// 模板1：找满足某个条件的第一个数  即右半段
int binary_search_1(int l, int r) {
    while(l<r) {
        int mid=(l+r)>>1;
        if(judge(mid)) r = mid;
        else l = mid+1;
    }
    return l;
}

// 模板2：找满足某个条件的最后一个数  即左半段
int binary_search_2(int l, int r) {
    while(l<r) {
        int mid=(l+r+1)>>1;
        if(judge(mid)) l = mid;
        else r = mid-1;
    }
    return l;
}

// 模板3：实数域上的二分
double binary_search_3(double l, double r) {
    // 防止与上文eps冲突，加了下划线结尾
    // 保留k位小数时，eps=10^{-k-2}
    const double eps_ = 1e-5;
    while(l + eps_ < r) {
        double mid = (l+r)/2;
        if(judge(mid)) r = mid;
        else l = mid;
    }
    return l;
}

// 模板4：精度难以控制的二分
double binary_search_4(double l, double r) {
    for(int i=0; i<100; i++) {
        double mid = (l+r)/2;
        if(judge(mid)) r= mid;
        else l = mid;
    }
    return l;
}

LL n;

//三分：单峰函数有唯一的极值点，严格单调！
double func(LL k) {
    //具体的函数形式
    // return (k*n+m)/(1-qpow(1-p, k));
}

double three_divide() {
    // double res = (n+m)/p;
    double res = INF;//可能的最值（此处为最小值）
    LL l=1, r=1000000;
    while(r-l+1>=10) {
        LL mid1=(l*2+r)/3, mid2=(l+r*2)/3;
        double f1=func(mid1), f2=func(mid2);
        res = min({res, f1, f2});
        if(f1<f2) r=mid2; else l=mid1;
    }
    for(int i=l; i<=r; i++)  res=min(res, func(i));
    return res;
}

// 枚举子集和超集
// https://blog.nowcoder.net/n/0137de03367d497ca9e16b684c4e9c61
void subset() {
    LL S = 22, MAXN = 32;
    for(int t=S; t; t=(t-1)&S) cout<<t<<' ';
    cout<<endl;
    for(int t=S; t<MAXN; t=(t+1)|S) cout<<t<<' ';
}

// 爬山算法
struct climbHill {
    static const double MAXN = 1e20;
    LL n, _x[maxn], _y[maxn];
    LL dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

    double getDis(double x, double y) {
        double dis = 0;
        Fo(i,1,n) dis+=sqrt((_x[i]-x)*(_x[i]-x)+(_y[i]-y)*(_y[i]-y));
        return dis;
    }

    double climb() {
        double x=rand()%10001, y=rand()%10001;
        double dis = getDis(x, y);
        double step = 10000;
        while(step>0.001) {
            double mn=MAXN, tx, ty;
            Fo(i,0,3) {
                double nx=x+dx[i]*step, ny=y+dy[i]*step;
                double ndis = getDis(nx, ny);
                if(ndis<mn) {
                    mn = ndis;
                    tx = nx;
                    ty = ny;
                }
            }
            if(mn<dis) {
                dis = mn;
                x = tx;
                y = ty;
            }
            step*=0.5;
        }
        return dis;
    }
};

// 模拟退火
// 记得多迭代几次的时候要初始化
// https://zhuanlan.zhihu.com/p/322278813
struct SAA {
    // 一些参数：Q:0.85~0.997, MAXN:2000~3000, eps:1e-12
    static const double Q = 0.997;
    const LL MAXN = 3000;
    // static const double eps = 1e-12;

    #define pdd pair<double, double>
    LL n, _x[maxn], _y[maxn];
    pdd ans, now;
    double res = 1e20;

    double getDis(double x, double y) {
        double dis = 0;
        Fo(i,1,n) dis+=sqrt((_x[i]-x)*(_x[i]-x)+(_y[i]-y)*(_y[i]-y));
        return dis;
    }

    void saa() {
        double t = MAXN;
        while(t>eps) {
            double x = now.first+((rand()<<1)-RAND_MAX)*t;
            double y = now.second+((rand()<<1)-RAND_MAX)*t;
            double dis = getDis(x, y);
            double det = dis-res;
            if(det<0) {
                res = dis;
                ans = now = {x, y};
            } else if(exp(-det/t)*RAND_MAX > rand()) {
                now = {x, y};
            }
            t*=Q;
        }
    }
};

// 基数排序
void numSort() {
    LL n; cin>>n;
    vector<string> a(n+1);
    LL mx = -1;
    string str;
    Fo(i,1,n) {
        cin>>a[i];
        LL num = (LL)atoi(a[i].c_str());
        if(num > mx) {
            mx = num;
            str = a[i];
        }
    } 
    for(int i=0; i<str.length(); i++) {
        queue<string> b[11];
        Fo(j,1,n) {
        	auto it = a[j];
            if(i>=it.length()) {
                b[0].push(it);
            } else {
                b[it[it.length()-i-1]-'0'].push(it);
            }
        }
        LL top = 0;
        Fo(i,0,9) {
            while(!b[i].empty()) {
                a[++top] = b[i].front();
                b[i].pop();
            }
        }
    }
    Fo(i,1,n) cout<<a[i]<<' ';
}
```

# geometry

```c++
//By cls1277 , learn from ECNU
#include<vector>
#include<algorithm>
#include<cmath>
using std::min;
using std::max;
using std::sort;
using std::swap;
using std::vector;

#define y1 yy1
#define LD double

const LD PI = 3.14159265358979323846;
const LD eps = 1e-10;

struct L;
struct P;
typedef P V;
typedef vector<P> S;
int sgn(LD x);

struct P {
    LD x, y;
    P(LD x=0, LD y=0): x(x), y(y) {}
    P(const P &p):x(p.x), y(p.y) {}
    P(const L &l);
};

P operator + (const P &p1, const P &p2) { return P(p1.x+p2.x, p1.y+p2.y); }
P operator - (const P &p1, const P &p2) { return P(p1.x-p2.x, p1.y-p2.y); }
P operator * (const P &p, LD k) { return P(p.x*k, p.y*k); }
P operator / (const P &p, LD k) { return P(p.x/k, p.y/k); }
bool operator < (const P & p1, const P &p2) { return (sgn(p1.x-p2.x)<0) || (!sgn(p1.x-p2.x)&&sgn(p1.y-p2.y)<0); }
bool operator == (const P & p1, const P &p2) { return (!sgn(p1.x-p2.x))&&(!sgn(p1.y-p2.y)); }

struct L {
    P s, t;
    L() {}
    L(P s, P t):s(s), t(t) {}
};

P::P(const L &l) { *this = l.t-l.s; }

int sgn(LD x) { return fabs(x)<eps ? 0 : (x>0 ? 1 : -1); }
LD dis(const P & p) { return sqrt(p.x*p.x+p.y*p.y); }
LD dot(const V &v1, const V & v2) { return v1.x*v2.x+v1.y*v2.y; }
LD det(const V &v1, const V & v2) { return v1.x*v2.y-v1.y*v2.x; }
LD cross(const P & p1, const P & p2, const P & p3=P()) { return det(p1-p3, p2-p3); }
V normal_vector(const V & v) { return V(-v.y, v.x) / dis(v); }

int quad(P p) {
    int x=sgn(p.x), y=sgn(p.y);
    if(x>0&&y>0) return 1;
    if(x<=0&&y>0) return 2;
    if(x<=0&&y<=0) return 3;
    if(x>0&&y<=0) return 4;
}

bool line_parallel(const L & l1 , const L & l2) { return !sgn(det(l1, l2)); }
bool line_equal(const L & l1, const L & l2) { return line_parallel(l1, l2)&&line_parallel(L(l1.s, l2.t), L(l2.s, l1.t)); }

P rotate_ccw_r(const P & p, const LD & r) { return P(p.x*cos(r)-p.y*sin(r), p.x*sin(r)+p.y*cos(r)); }
P rotate_ccw_90(const P & p) { return P(-p.y, p.x); }
P rotate_cw_90(const P & p) { return P(p.y, -p.x); }

bool point_on_segment(const P & p, const L & l) {
    P a=l.s, b=l.t;
    return !sgn(det(p-a, b-a)) && sgn(dot(p-a, p-b))<=0;
}

LD node_to_line(const P & p , const L & l) { return fabs(cross(l.s, l.t, p)) / dis(l); }

LD node_to_segment(const P & p, const L & l) {
    if (l.s==l.t) return dis(p-l);
    V vs = p-l.s, vt = p-l.t;
    if(sgn(dot(l, vs)) < 0) return dis(vs);
    else if(sgn(dot(l, vt)) > 0) return dis(vt);
    else return node_to_line(p, l);
}

P line_cross_line(const L & a, const L &b) {
    LD s1 = det(P(a), b.s-a.s), s2 = det(P(a), b.t-a.t);
    return (b.s*s2-b.t*s1)/(s2-s1);
}

LD vector_angle(const V & a, const V & b) {
    LD r = asin(fabs(det(a, b)) / dis(a) / dis(b));
    if(sgn(dot(a, b)) < 0) r = PI-r;
    return r;
}

int segment_cross_line(const L & seg, const L & line) {
    int d1 = sgn(cross(line.s, line.t, seg.s));
    int d2 = sgn(cross(line.s, line.t, seg.t));
    if((d1^d2)==-2) return 1;
    if(!d1 || !d2) return 2;
    return 0;
}

int segment_cross_segment(const L & a, const L & b, P & p) {
    int d1 = sgn(cross(a.t, b.s, a.s)), d2 = sgn(cross(a.t, b.t, a.s));
    int d3 = sgn(cross(b.t, a.s, b.s)), d4 = sgn(cross(b.t, a.t, b.s));
    if((d1^d2)==-2 && (d3^d4)==-2) { p = line_cross_line(a, b); return 1; }
    if(!d1 && point_on_segment(b.s, a)) { p = b.s; return 2; }
    if(!d2 && point_on_segment(b.t, a)) { p = b.t; return 2; }
    if(!d3 && point_on_segment(a.s, b)) { p = a.s; return 2; }
    if(!d4 && point_on_segment(a.t, b)) { p = a.t; return 2; }
    return 0;
}

struct C {
    P p; LD r;
    C(LD x=0, LD y=0, LD r=0):p(x,y), r(r) {}
    C(P p, LD r):p(p), r(r) {}
};

P circle_center(P a, P b, P c) {
    b=(a+b)/2; c=(a+c)/2;
    return line_cross_line(L(b, b+rotate_cw_90(a-b)), L(c, c+rotate_cw_90(a-c)));
}

int circle_relation(const C & a, const C & b) {
    LD d = dis(a.p-b.p);
    if(sgn(d-a.r-b.r)>0) return 5;
    if(sgn(d-a.r-b.r)==0) return 4;
    LD l = fabs(a.r-b.r);
    if(sgn(d-l)>0) return 3;
    if(sgn(d-l)==0) return 2;
    if(sgn(d-l)<0) return 1;
}

vector<P> circle_cross_line(const L & l, const C & c) {
    vector<P> res;
    P b(l), a=l.s-c.p;
    LD x=dot(b, b), y=dot(a, b), z=dot(a, a)-c.r*c.r;
    LD D = y*y-x*z;
    if(sgn(D)<0) return res;
    res.push_back(c.p+a+b*(-y+sqrt(D+eps))/x);
    if(sgn(D)>0) res.push_back(c.p+a+b*(-y-sqrt(D))/x);
    return res;
}

vector<P> circle_cross_circle(const C & a, const C & b) {
    vector<P> res;
    LD d = dis(a.p-b.p);
    if(sgn(d)==0 || sgn(d-(a.r+b.r))>0 || sgn(d+min(a.r, b.r)-max(a.r, b.r))<0)
        return res;
    LD x = (d*d-b.r*b.r+a.r*a.r) / (2*d);
    LD y = sqrt(a.r*a.r-x*x);
    P v = (b.p-a.p) / d;
    res.push_back(a.p+v*x+rotate_ccw_90(v)*y);
    if(sgn(y)>0) res.push_back(a.p+v*x-rotate_ccw_90(v)*y);
    return res;
}

P circle_center(P a, P b) {
    return (a+b)/2;
}

bool point_in_circle(const P & p, const C & c) {
    return sgn(dis(p-c.p)-c.r)<=0;
}

C min_circle_cover(const vector<P>&in) {
    vector<P> a(in.begin(), in.end());
    random_shuffle(a.begin(), a.end());
    P c=a[0]; LD r=0; int n=a.size();
    for(int i=1; i<n; i++) {
        if(!point_in_circle(a[i], {c,r})) {
            c = a[i]; r = 0;
            for(int j=0; j<i; j++) {
                if(!point_in_circle(a[j], {c,r})) {
                    c = circle_center(a[i], a[j]);
                    r = dis(a[j]-c);

                    
                    for(int k=0; k<j; k++) {
                        if(!point_in_circle(a[k], {c,r})) {
                            c = circle_center(a[i], a[j], a[k]);
                            r = dis(a[k]-c);
                        }
                    }
                }
            }
        }
    }
    return {c,r};
}

#define nxt(i) ((i+1)%s.size())
int polygon_inside(const S & s, const P & p) {
    int cnt = 0;
    for(int i=0; i<s.size(); i++) {
        P a=s[i], b=s[nxt(i)];
        if(point_on_segment(p, L(a, b))) return -1;
        if(sgn(a.y-b.y)<=0) swap(a,b);
        if(sgn(p.y-a.y)>0) continue;
        if(sgn(p.y-b.y)<=0) continue;
        cnt += sgn(cross(b, a, p))>0;
    }
    return bool(cnt&1);
}

LD polygon_area(const S & s) {
    LD res = 0;
    for(int i=1; i<s.size()-1; i++)
        res += cross(s[i], s[i+1], s[0]);
    return res/2;
}

const int maxn = 1e3;
S convex_hull(S & s) {
    sort(s.begin(), s.end());
    S res(maxn*2);
    int sz = 0;
    for(int i=0; i<s.size(); i++) {
        while(sz>1&&sgn(cross(res[sz-1], s[i], res[sz-2]))<0) sz--;
        res[sz++] = s[i];
    }
    int k = sz;
    for(int i=s.size()-2; i; i--) {
        while(sz>k && sgn(cross(res[sz-1], s[i], res[sz-2]))<0) sz--;
        res[sz++] = s[i];
    }
    res.resize(sz-(s.size()>1));
    return res;
}

P compute_centroid(const vector<P> & p) {
    P c(0,0);
    LD scale = 6.0*polygon_area(p);
    for(int i=0; i<p.size(); i++) {
        int j = (i+1)%p.size();
        c = c+(p[i]+p[j])*(p[i].x*p[j].y-p[j].x*p[i].y);
    }
    return c/scale;
}

struct LV {
    P p, v; LD angle;
    LV() {}
    LV(P s, P t): p(s), v(t-s) { angle = atan2(v.y,v.x); }
};

bool operator < (const LV & a , const LV & b) { return a.angle<b.angle; }

bool on_left(const LV & l, const P & p) { return sgn(cross(l.v, p-l.p))>=0; }

P line_cross_line(const LV & a, const LV & b) {
    P u = a.p-b.p; LD t = cross(b.v, u) / cross(a.v, b.v);
    return a.p+a.v*t;
}

S half_plane_intersection(vector<LV> & L) {
    int n=L.size(), fi, la;
    sort(L.begin(), L.end());
    vector<P> p(n); vector<LV> q(n);
    q[fi = la = 0] = L[0];
    for(int i=1; i<n; i++) {
        while(fi<la && !on_left(L[i], p[la - 1])) la--;
        while(fi<la && !on_left(L[i], p[fi])) fi++;
        q[++la] = L[i];
        if(sgn(cross(q[la].v, q[la - 1].v))==0) {
            la--;
            if(on_left(q[la], L[i].p)) q[la] = L[i];
        }
        if(fi<la) p[la-1] = line_cross_line(q[la-1], q[la]);
    }
    while(fi<la && !on_left(q[fi], p[la-1])) la--;
    if(la-fi<=1) return vector<P>();
    p[la]=line_cross_line(q[la], q[fi]);
    return vector<P>(p.begin()+fi, p.begin()+la+1);
}

S convex_intersection(const vector<P> & v1, const vector<P> & v2) {
    vector<LV> h; int n=v1.size(), m=v2.size();
    for(int i=0; i<n; i++) h.push_back(LV(v1[i], v1[(i+1)%n]));
    for(int i=0; i<m; i++) h.push_back(LV(v2[i], v2[(i+1)%m]));
    return half_plane_intersection(h);
}
```

# graph

```c++
//By cls1277
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))

const int maxn = 1e3+5;

//根据实际情况决定是否添加val，比如mcmf就需要添加
struct Edge {
    LL to , next , len, val;
}e[maxn<<1];

LL tot, head[maxn];
LL n;//n是点的个数

void add(LL x, LL y, LL z=0) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].len = z;
    head[x] = tot;
}

//wt是带权值的lca
LL deep[maxn], fa[maxn][25], wt[maxn][25];
bool vis[maxn];

void dfs(LL u, LL f, LL w) {
    deep[u] = deep[f]+1;
    fa[u][0] = f;
    wt[u][0] = w;
    for(int i=head[u]; i; i=e[i].next) {
        LL v=e[i].to;
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v, u, e[i].len);
    }
}

LL lca(LL x, LL y) {
    LL ans = INT_MAX;
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=20; i>=0; i--) {
        if(deep[fa[x][i]]>=deep[y]) {
            ans = min(ans, wt[x][i]);
            x = fa[x][i];
        }
        if(x==y) return ans;
    }
    for(int i=20; i>=0; i--) {
        if(fa[x][i]!=fa[y][i]) {
            ans = min(ans, wt[x][i]);
            ans = min(ans, wt[y][i]);
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    ans = min(ans, wt[x][0]);
    ans = min(ans, wt[y][0]);
    return ans;
}

void lca_init(LL n) {
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(i,0,INT_MAX);
        }
    }
    for(int i=1; i<=20; i++) {
        for(int j=1; j<=n; j++) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
            wt[j][i] = min(wt[j][i-1], wt[fa[j][i-1]][i-1]);
        }
    }
}

// 无边权的LCA
LL lca(LL x, LL y) {
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=20; i>=0; i--) {
        if(deep[fa[x][i]]>=deep[y]) {
            x = fa[x][i];
        }
        if(x==y) return x;
    }
    for(int i=20; i>=0; i--) {
        if(fa[x][i]!=fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    return fa[x][0];
}

void lca_init() {
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            vis[i] = 1;
            dfs(i,0,INT_MAX);
        }
    }
    for(int i=1; i<=20; i++) {
        for(int j=1; j<=n; j++) {
            fa[j][i] = fa[fa[j][i-1]][i-1];
        }
    }
}

// LCA tarjan做法

// 并查集，将fa改为pa

LL pa[maxn], lca_ans[maxn];
map<LL, vector<pair<LL, LL>>> q;

LL find(LL x) {
    while(x!=pa[x]) {
        x = pa[x] = pa[pa[x]];
    }
    return x;
}

void Union(LL x, LL y) {
    LL fx=find(x), fy=find(y);
    pa[fx] = fy;
}

void lca_tarjan(LL x, LL f) {
    Eo(i, x, e) {
        LL v = e[i].to;
        if(v==f) continue;
        lca_tarjan(v, x);
        Union(v, x);
    }
    vis[x] = 1;
    for(auto it:q[x]) {
        if(vis[it.second]) {
//            cout<<x<<' '<<it.second<<' '<<find(it.second)<<endl;
            lca_ans[it.first] = find(it.second);
        }
    }
}

void lca_tarjan_main() {
    LL m; cin>>m; //m次查询
    Fo(i,1,m) {
        LL a, b; cin>>a>>b;
        q[a].push_back({i, b});
        q[b].push_back({i, a});
    }
    lca_tarjan(s, s); //s为树的根，可以看题目给不给，或者通过入度判断
    Fo(i,1,m) cout<<lca_ans[i]<<endl;
}

// LCA RMQ做法

LL first[maxn];
pair<LL, LL> stb[maxn][25]; //first:deep, second:id
vector<pair<LL, LL>> a; //表

pair<LL, LL> calc(pair<LL, LL> x, pair<LL, LL> y) {
    if(x.first < y.first) return x;
    return y;
}

void lca_rmq(LL x, LL f) {
    first[x] = cnt;
    // a.push_back({deep[x], x}); cnt++;
    bool flag = 0;
    Eo(i, x, e) {
        LL v = e[i].to;
        if(v==f) continue;
        flag = 1;
        deep[v] = deep[x]+1;
        a.push_back({deep[v], v}); cnt++;
        lca_rmq(v, x);
        a.push_back({deep[x], x}); cnt++;
    }
    if(flag) {
        a.push_back({deep[x], x});
        cnt++;
    }
}

void lca_rmq_main() {
    cin>>n>>m>>s;
    Fo(i,2,n) {
        LL x, y; cin>>x>>y;
        add(x, y);
        add(y, x);
    }
    cnt = 1;
    deep[s] = 1;
    a.push_back({1, s});
    lca_rmq(s, s);
    Fo(i,1,cnt) {
        stb[i][0] = a[i-1];
    }
    Fo(j,1,21) {
        Fo(i,1,cnt) {
            stb[i][j] = calc(stb[i][j-1], stb[i+(1<<(j-1))][j-1]);
        }
    }
    Fo(i,1,m) {
        LL a, b; cin>>a>>b;
        LL l=first[a], r=first[b];
        if(l>r) swap(l, r);
        LL k = LL(log(r-l+1)/log(2));
        cout<<calc(stb[l][k], stb[r-(1<<k)+1][k]).second<<endl;
    }
}

// 最大流（最小割）

LL minn, maxx; //最小费用，最大流
LL s, t; //源点，汇点

// EK算法
LL mf_vis[maxn][maxn]; //应对重边的情况
LL dis[maxn], pre[maxn];

bool ek_bfs() {
    Ms(vis, 0);
    queue<LL> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = INT_MAX;
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        if(u==t) return 1;
        Eo(i,u,e) {
            LL v = e[i].to;
            if(vis[v]||e[i].val<=0) continue;
            dis[v] = min(dis[u], e[i].val);
            vis[v] = 1;
            pre[v] = i; // 存的i
            q.push(v);
        }
    }
    return 0;
}

void ek_update() {
    LL x = t;
    while(x!=s) {
        LL i = pre[x];
        e[i].val  -= dis[t];
        e[i^1].val += dis[t];
        x = e[i^1].to;
    }
    maxx += dis[t];
}

void ek_main() {
    cin>>n>>m>>s>>t;
    tot = 1;
    Fo(i,1,m) {
        LL x, y, z; cin>>x>>y>>z;
        if(!mf_vis[x][y]) {
            add(x, y, z);
            mf_vis[x][y] = tot;
            add(y, x, 0);
        } else {
            e[mf_vis[x][y]].val += z;
        }

    }
    while(ek_bfs()) ek_update();
    cout<<maxx;
}

// dinic算法

bool dinic_bfs() {
    Ms(vis, 0);
    queue<LL> q;
    q.push(s);
    vis[s] = 1;
    deep[s]  = 1;
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        if(u==t) return 1;
        Eo(i,u,e) {
            LL v = e[i].to;
            if(vis[v]||e[i].val<=0) continue;
            vis[v] = 1;
            deep[v] = deep[u] + 1;
            q.push(v);
        }
    }
    return 0;
}

LL dinic_dfs(LL x, LL dis) {
    if(x==t) return dis;
    LL rest = dis;
    Eo(i,x,e) {
        LL v = e[i].to;
        if(!e[i].val || deep[v]!=deep[x]+1) continue;
        LL k = dinic_dfs(v, min(rest, e[i].val));
        if(!k) deep[v] = -1;
        e[i].val -= k;
        e[i^1].val += k;
        rest -= k;
    }
    return dis-rest;
}

void dinic_main() {
    cin>>n>>m>>s>>t;
    tot = 1;
    Fo(i,1,m) {
        LL x, y, z; cin>>x>>y>>z;
        if(!mf_vis[x][y]) {
            add(x, y, z);
            mf_vis[x][y] = tot;
            add(y, x, 0);
        } else {
            e[mf_vis[x][y]].val += z;
        }
    }
    while(dinic_bfs()) {
        LL flow;
        while(flow = dinic_dfs(s, INT_MAX)) {
            maxx += flow;
        }
    }
    cout<<maxx;
}

// 最小费用最大流

// EK算法

LL len[maxn]; //费用长度，含义为spfa中的dis数组

// 重载add函数
void add(LL x, LL y, LL z, LL w) {
    tot++;
    e[tot].next = head[x];
    e[tot].to = y;
    e[tot].val = z;
    e[tot].len = w;
    head[x] = tot;
}

bool ek_spfa() {
    Ms(vis, 0); Ms(dis, 0x3f); Ms(len, 0x3f);
    len[s] = 0; dis[s] = INT_MAX; vis[s] = 1;
    queue<LL>q; q.push(s);
    bool flag = 0;
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        if(u==t) flag = 1;
        vis[u] = 0;
        Eo(i,u,e) {
            LL v = e[i].to;
            if(e[i].val>0&&len[v]>len[u]+e[i].len) {
                len[v] = len[u] + e[i].len;
                pre[v] = i;
                dis[v] = min(dis[u], e[i].val);
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return flag;
}

void ek_mcmf_update() {
    LL x = t;
    while(x!=s) {
        LL i = pre[x];
        e[i].val -= dis[t];
        e[i^1].val += dis[t];
        x = e[i^1].to;
    }
    maxx += dis[t];
    minn += dis[t]*len[t];
}

void ek_mcmf_main() {
    cin>>n>>m>>s>>t;
    tot = 1;
    Fo(i,1,m) {
        LL x, y, z, w; cin>>x>>y>>z>>w;
        if(x==y) continue;
        add(x, y, z, w);
        add(y, x, 0, -w);
    }
    while(ek_spfa()) ek_mcmf_update();
    cout<<maxx<<' '<<minn;
}

// dinic算法

bool dinic_spfa() {
    Ms(vis, 0); Ms(len, 0x3f);
    vis[s] = 1; len[s] = 0;
    queue<LL>q; q.push(s);
    bool flag = 0;
    while(!q.empty()) {
        LL u = q.front(); q.pop();
        if(u==t) flag = 1;
        vis[u] = 0;
        Eo(i,u,e) {
            LL v = e[i].to;
            if(e[i].val>0&&len[v]>len[u]+e[i].len) {
                len[v] = len[u] + e[i].len;
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return flag;
}

LL dinic_mcmf_dfs(LL x, LL dis) {
    if(x==t) return dis;
    LL rest = dis;
    vis[x] = 1; //要有vis限制
    Eo(i,x,e) {
        LL v = e[i].to;
        if(vis[v] || !e[i].val || len[v]!=len[x]+e[i].len) continue;
        LL k = dinic_mcmf_dfs(v, min(rest, e[i].val));
        if(!k) len[v] = -1;
        e[i].val -= k;
        e[i^1].val += k;
        rest -= k;
        minn += k*e[i].len;
    }
    vis[x] = 0;
    return dis-rest;
}

void dinic_mcmf_main() {
    cin>>n>>m>>s>>t;
    tot = 1;
    Fo(i,1,m) {
        LL x, y, z, w; cin>>x>>y>>z>>w;
        if(x==y) continue;
        add(x, y, z, w);
        add(y, x, 0, -w);
    }
    while(dinic_spfa()) {
        LL flow;
        while(flow = dinic_mcmf_dfs(s, INT_MAX)) {
            maxx += flow;
        }
    }
    cout<<maxx<<' '<<minn;
}

//二分图匹配

//m一般是边的个数，匈牙利算法中是二分图右侧结点个数
LL line[maxn][maxn], match[maxn], m;

//匈牙利算法
bool xyl(LL x) {
    for(int i=1; i<=m; i++) {
        if(line[x][i]&&!vis[i]) {
            vis[i] = 1;
            if(!match[i]||xyl(match[i])) {
                match[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

//ans是二分图最大匹配数，n是二分图左侧结点个数
void xyl_init(LL n) {
    LL ans=0;
    for(int i=1; i<=n; i++) {
        memset(vis, 0, sizeof(vis));
        if(xyl(i)) ans++;
    }
    cout<<ans;
}

//除此之外，二分图匹配也可以用dinic来做，只需要建一个超级源点和一个超级汇点，同时注意点的序号问题
//https://github.com/cls1277/OnlineJudge-Codes/commit/3a5aa72b1f937c0d6ae84e0eff1b2718fc6a2d7a

LL dfn[maxn], low[maxn], idx, cnt, color[maxn];
bool ins[maxn];//是否在栈里
stack<LL>st;
vector<LL>ed[maxn];//vector存图

void tarjan(LL x) {
    dfn[x] = low[x] = ++idx;
    st.push(x); ins[x] = 1;
    for(LL i=0; i<ed[x].size(); i++) {
        LL v=ed[x][i];
        if(!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x],low[v]);
        } else if(ins[v]) {
            low[x] = min(low[x],dfn[v]);
        }
    }
    if(dfn[x]==low[x]) {
        cnt++; LL temp;
        do {
            //这次循环弹出来的所有temp一定是同一个强连通分量里的
            temp = st.top();
            ins[temp] = 0;
            color[temp] = cnt;
            st.pop();
        }while(temp!=x);
    }
}

void scc_init(LL n) {
    for(int i=1; i<=n; i++)
        if(!dfn[i])
            tarjan(i);
}

//n是变量个数，2*n是因为添加了非点，可以采用i+n的形式表示!i
void twoSAT_init(LL n) {
    /*
        根据题目要求连边，如
        !a||b -> (a->b)||(!b->!a) 连边
    */
    for(int i=1; i<=2*n; i++)
        if(!dfn[i])
            tarjan(i);
    /*
        判断x和!x是否在一个强连通分量内
        如果在说明无解
        最终答案为color(i)<color(!i)
    */
    for(int i=1; i<=n; i++)
        if(color[i]==color[i+n]) {
            cout<<"IMPOSSIBLE";
            return ;
        }
    for(int i=1; i<=n; i++)
        cout<<(color[i]<color[i+n])<<" ";
}

//割点 is[i]:i是否是割点
bool is[maxn];

void tarjan_points(LL u, LL f) {
    low[u] = dfn[u] = ++idx;
    LL child = 0;
    for(int i=head[i]; i; i=e[i].next) {
        LL v=e[i].to;
        if(v==f) continue;
        if(!dfn[v]) {
            tarjan_points(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]&&u!=f&&!is[u]) {
                //yes
                is[u] = 1;
                cnt++;
            }
            if(u==f) child++;
        }
        low[u]=min(low[u],dfn[v]);
    }
    if(child>1&&u==f&&!is[u]) {
        //yes
        is[u] = 1;
        cnt++;
    }
    return ;
}

//割边
void tarjan_edge(LL u, LL f) {
    low[u] = dfn[u] = ++idx;
    for(int i=head[i]; i; i=e[i].next) {
        LL v=e[i].to;
        if(v==f) continue;
        if(!dfn[v]) {
            tarjan_edge(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]) {
                //u->v的这条边就是割边
            }
        }
        low[u]=min(low[u],dfn[v]);
    }
    return ;
}

//缩点
/*
    代码与之前类似，就不单独再写了
    还是tarjan求强连通分量的思路
    求解过程中，cnt是强连通分量的序号
    就可以在do-while的时候顺便更新缩点的新的权值
    https://github.com/cls1277/OnlineJudge-Codes/commit/017c50e9fe2cab35889996bae32ec8e0b2beb2d4
*/

struct Que {
	LL len , num;
};

bool operator < (Que a , Que b) {
	return a.len > b.len;
}

void dij(LL s) {
    for(int i=1; i<=n; i++) dis[i]=INT_MAX;
	dis[s] = 0;
	priority_queue<Que>q;
	q.push({0,s});
	while(!q.empty()) {
		Que u=q.top();
		q.pop();
		if(u.len!=dis[u.num]) continue;
		for(int i=head[u.num]; i;i=e[i].next) {
			LL v=e[i].to;
			if(dis[v]>dis[u.num]+e[i].val) {
				dis[v] = dis[u.num]+e[i].val;
				q.push({dis[v], v});
			}
		}
	}
}

//spfa最短路

void spfa(LL s) {
	for(int i=1; i<=n; i++) dis[i]=INT_MAX;
	queue<LL>q;
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while(!q.empty()) {
		LL u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i=head[u]; i; i=e[i].next) {
			LL v = e[i].to;
			if(dis[v]>dis[u]+e[i].val) {
				dis[v] = dis[u]+e[i].val;
				if(!vis[v]) {
					vis[v] = 1;
					q.push(v);
				}
			} 
		} 
	}
}

//spfa求负环
LL countt[maxn]; //代替cnt数组

bool spfa_minus(LL s) {
	queue<LL>q;
    for(int i=1; i<=n; i++) {
        dis[i] = INT_MAX; //可能会赋值0
        countt[i] = vis[i] = 0;
        q.push(i); //没有给起点的时候都要压进去，给了起点只需要压进起点
    }
	while(!q.empty()) {
		LL u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i=head[u]; i; i=e[i].next) {
			LL v = e[i].to;
			if(dis[v]>dis[u]+e[i].len) {
				dis[v] = dis[u]+e[i].len;
				if(!vis[v]) {
					vis[v] = 1;
					q.push(v);
                    countt[v] = countt[u]+1;
                    if(countt[v]>=n) return 1;
				}
			} 
		} 
	}
    return 0;
}

//sum[]存强连通分量的值
LL ind[maxn], sum[maxn];

LL topo() {
    LL ans = 0;
    struct Node {
        LL id, sum;
    };
    queue<Node>q;
    for(int i=1; i<=cnt; i++)
        if(!ind[i])
            q.push({i,sum[i]});
    while(!q.empty()) {
        Node u=q.front(); q.pop();
        ans = max(ans, u.sum);
        for(LL i=0; i<ed[u.id].size(); i++) {
            LL v=ed[u.id][i];
            ind[v]--;
            if(!ind[v]) 
                q.push({v,u.sum+sum[v]});
        }
    }
    return ans;
}

void prim() {
    struct Node {
        LL to , next , val;
        bool operator < (const Node &a) const {
            return val>a.val;
        } 
    };
    Node e[maxn<<1];
    priority_queue<Node>q;
    LL ans = 0;
	dis[1] = 0; cnt = 0;
    memset(vis, 0, sizeof(vis));
	q.push(Node{1 , 1 , 0});
	while(!q.empty()&&cnt<n) {
		Node u = q.top();
		q.pop();
		if(vis[u.to]) continue;
		vis[u.to] = 1;
		ans+=u.val;
		cnt++;
		for(int i=head[u.to]; i; i=e[i].next)
			if(dis[e[i].to]>e[i].val) {
				dis[e[i].to] = e[i].val;
				q.push(Node{e[i].to , e[i].to , e[i].val});
			}
	}
}
```

# math

```c++
//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//复数库 可能会慢
#include<complex>

using namespace std;

typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;

#define PI acos(-1)

#define _M 2
struct Mat {
    LL a[_M][_M];
    Mat() {
        memset(a, 0, sizeof(a));
    }
    void eye() {
        for(LL i=0; i<_M; i++) a[i][i] = 1;
    }
    Mat operator * (Mat &b) {
        Mat res;
        for(LL i=0; i<_M; i++)
            for(LL j=0; j<_M; j++)
                for(LL k=0; k<_M; k++)
                    res.a[i][j] += this->a[i][k]*b.a[k][j];
        return res;
    }
    Mat operator + (Mat &b) {
        Mat res;
        for(LL i=0; i<_M; i++)
            for(LL j=0; j<_M; j++)
                res.a[i][j] = this->a[i][j]+b.a[i][j];
        return res;
    }
    Mat pow(LL b) {
        Mat res , a=*this;
        res.eye();        
        while(b) {
            if(b&1)
                res = res*a;
            a = a*a;
            b>>=1;
        }
        return res;
    }
    void prLL() {
        for(LL i=0; i<_M; i++) {
            for(LL j=0; j<_M; j++)
                cout<<a[i][j]<<" ";
            cout<<'\n';
        }
    }
};

LL gcd(LL x, LL y) {
    return y?gcd(y, x%y):x;
}

const LL maxn = 1e3+5;
void getprime(LL maxx, LL pri[]) {
    bool vis[maxn]; LL cnt=0;
    memset(vis, 0, sizeof(vis));
    for(LL i=2; i<=maxx; i++) {
        if(!vis[i]) pri[cnt++]=i;
        for(LL j=0; j<cnt; j++) {
            if(i*pri[j]>maxx) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j]==0) break;
        }
    }
}

void getphi(LL maxx, LL phi[]) {
    bool vis[maxn]; LL cnt=0, pri[maxn];
    memset(vis, 0, sizeof(vis));
    phi[1] = 1;
    for(LL i=2; i<=maxx; i++) {
        if(!vis[i]) {
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        for(LL j=0; j<cnt; j++) {
            if(i*pri[j]>maxx) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j]==0) {
                phi[i*pri[j]] = phi[i]*pri[j];
                break;
            } else {
                phi[i*pri[j]] = phi[i]*(pri[j]-1);
            }
        }
    }
}

LL getonephi(LL x) {
    LL temp = x;
    for(LL i=2; i<=sqrt(x); i++) {
        if(x%i) continue;
        temp = temp-temp/i;
        while(x%i==0) x/=i;
    }
    if(x!=1) temp=temp-temp/x;
    return temp;
}

void getmu(LL maxx, LL mu[]) {
    bool vis[maxn]; LL cnt=0, pri[maxn];
    memset(vis, 0, sizeof(vis));
    mu[1] = 1;
    for(LL i=2; i<=maxx; i++) {
        if(!vis[i]) {
            mu[i] = -1;
            pri[cnt++] = i;
        }
        for(LL j=0; j<cnt; j++) {
            if(i*pri[j]>maxx) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j])
                mu[i*pri[j]] = -mu[i];             
            else {
                mu[i*pri[j]] = 0;
                break;
            }
        }
    }
}

inline ULL qmul(ULL a, ULL b, const ULL mod){
    LL c=(LL)(a)*b-(LL)((ULL)((LD)(a)*b/mod)*mod);
    return c<0? c+mod:(c<mod? c:c-mod);
}

// qmul的另一种写法
inline LL qmul2(LL a, LL b, LL p) {
    LL ans = 0;
    while(b>0) {
        if(b&1) ans = (ans+a)%p;
        a = a*2%p;
        b>>=1;
    }
    return ans;
}

inline LL _qpow(LL a, LL b) {
    LL res = 1;
    while(b) {
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}

inline LL qpow(LL a, LL b, LL mod = 19260817) {
    LL res = 1;
    while(b) {
        if(b&1)
            res = qmul(res,a,mod);
        a = qmul(a,a,mod);
        b>>=1;
    }
    return res;
}

bool miller_rabin(LL x) {
    if(x==2) return true;
    if(x<2||x%2==0) return false;
    LL A[12]={2,3,5,7,11,13,17,19,23,29,31,37}, sz=11;
    //LL范围内只需检查2,7,61
    //long long范围2,325,9375,28178,450775,9780504,1795265022
    //3E15内2,2570940,880937,610386380,4130785767
    //4E13内2,2570940,211991001,3749873356
    for(LL i=0; i<=sz; i++)
        if(x==A[i])
            return true;
    LL m=x-1, k=0;
    while(m%2==0) {
        k++;
        m>>=1;
    }
    for(LL i=0; i<=sz; i++) {
        LL y = qpow(A[i],m,x), z;
        z = y;
        for(LL j=1; j<=k; j++) {
            y = qmul(y,y,x);
            if(y==1&&z!=1&&z!=x-1)
                return false;
            z = y;
        }
        if(y!=1) return false;
    }
    return true;
}

LL rho_function(LL x , LL c , LL mod) {
    return (qmul(x, x, mod)+c)%mod;
}

LL rho(LL n) {
    LL x, y, i, j, c, z;
    while(1) {
        i=0;j=1;z=1;
        x=y=rand()%n; c=rand()%n;
        while(++i) {
            x = rho_function(x, c, n);
            z = qmul(z, abs(y-x), n);
            if(!z || x==y) break;
            if(i==j || i%127==0) {
                LL g = gcd(z, n);
                if(g > 1) return g;
                if(i == j) {
                    j<<=1;
                    y=x;
                }
            }
        }
    }
}

LL max_prime_factor = 0;

void dfs(LL n) {
    if(n<max_prime_factor || n<2)
        return ;
    if(miller_rabin(n)) {
        max_prime_factor = max(max_prime_factor,n);
        return ;
    }
    LL p=n;
    p = rho(n);
    while(n%p == 0) n/=p;
    dfs(n); dfs(p);
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if(!b) {
        x=1; y=0;
        return a;
    }
    LL d=exgcd(b, a%b, x, y);
    LL k = x; x = y;
    y = k-a/b*y;
    return d;
}

//卡常gcd stein算法 去掉了取模 加快了速度
inline LL ctz(LL x) { return __builtin_ctzll(x); }
LL fast_gcd(LL a, LL b) {
    if(!a) return b; if(!b) return a;
    LL t = ctz(a | b);
    a >>= ctz(a);
    do {
        b >>= ctz(b);
        if(a > b) swap(a, b);
        b -= a;
    } while (b);
    return a << t;
}

LL inv[maxn];

LL inv1(LL x , LL y) {
    return qpow(x,y-2,y);
}

void inv2(LL n , LL mod) {
    inv[1] = 1;
    for(LL i=2; i<=n; i++)
        inv[i] = (mod-mod/i)%mod*inv[mod%i]%mod;
}

//阶乘逆元
LL frac[maxn];
void inv3(LL n , LL mod) {
    frac[0] = 1;
    for(LL i=1; i<=n; i++)
        frac[i] = frac[i-1]*i%mod;
    inv[n] = qpow(frac[n],mod-2,mod);
    for(LL i=n-1; i>=0; i--)
        inv[i] = inv[i+1]*(i+1)%mod;
}

LL inv4(LL n, LL mod) {
    LL x, y;
    exgcd(n, mod, x, y);
    return (x+mod)%mod;
}

LL C(LL n, LL m, LL mod=1e9+7) {
    LL res=1;
    for(LL i=1; i<=m; i++)
        res=res*(n-m+i)%mod*qpow(i,mod-2,mod)%mod;
    return res;
}

// 求组合数的另一种写法，用于求y不大情况
LL C2(LL x, LL y) {
    if(x<0||y<0||x<y) return 0;
    if(x%mod==0||y==0) return 1;
    LL res = 1;
    Fo(i,x-y+1,x) res = (res*(i%mod))%mod;
    Fo(i,1,y) res = (res*(inv[i]%mod))%mod;
    return res;
}

// 此处的inv为阶乘逆元
LL C3(LL x, LL y) {
    return frac[x]*inv[y]%mod*inv[x-y]%mod;
}

//求C_{n+m}^n mod p的值
LL lucas(LL n , LL m , LL mod) {
    if(!m) return 1;
    return C(n%mod,m%mod,mod)*lucas(n/mod,m/mod,mod)%mod;
}

const LD eps = 1e-10;
LL mat[maxn][maxn];
//第n+1列是y值，第i个变量的值为mat[i][n+1]/mat[i][i]
bool gauss(LL n) {
    for(LL i=1; i<=n; i++) {
        LL maxrow=i;
        for(LL j=i+1; j<=n; j++)
            if(mat[j][i]>mat[maxrow][i])
                maxrow = j;
        if(fabs(mat[maxrow][i])<=eps) return false;
        for(LL j=1; j<=n+1; j++)
            swap(mat[maxrow][j],mat[i][j]);
        for(LL j=1; j<=n; j++) {
            if(i==j) continue;
            LD p=mat[j][i]/mat[i][i];
            for(LL k=i+1; k<=n+1; k++)
                mat[j][k]-=mat[i][k]*p;
        }
    }
    return true;
}

//原根

void init(LL n, LL phi[], bool exi[], bool vis[]) {
    //预处理exi和vis为0
    for(LL i=1; i<=n; i++) exi[i]=vis[i]=0;
    LL pri[maxn]; LL cnt = 0;
    phi[1]=1;
    for(LL i=2; i<=n; i++) {
        if(!vis[i]) {
            pri[cnt++] = i;
            phi[i] = i-1;
        }
        for(LL j=0; j<cnt; j++) {
            if(i*pri[j]>n) break;
            vis[i*pri[j]] = 1;
            if(i%pri[j]==0) {
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            } else {
                phi[i*pri[j]]=phi[i]*(pri[j]-1);
            }
        }
    }
    exi[2]=exi[4]=1;
    for(LL i=1; i<cnt; i++) {
        LL p=pri[i];
        for(LL q=p; q<=n; q*=p) {
            exi[q] = 1;
            if(2*q<=n) exi[2*q]=1;
        }
    }
}

//之前应手动运行init(max_n);
//答案存在root中
void primitive_root(LL n, LL phi[], bool exi[], vector<LL>root) {
    if(!exi[n]) return ;
    LL tempn=n; n=phi[n];
    vector<LL>facts;
    for(LL i=1; i<=sqrt(n); i++) {
        if(n%i==0) {
            facts.push_back(i);
            if(i!=n/i)
                facts.push_back(n/i);
        }
    }
    LL i=0;
    while(1) {
        i++;
        if(gcd(i,tempn)!=1) continue;
        bool is=true;
        for(auto fact:facts) {
            LL t=qpow(i,fact,tempn);//tempn!!!
            if(fact!=n&&t==1) {
                is = false;
                break;
            }
        }
        if(is) break;
    }
    LL tempi=i, p=i;
    for(LL i=1; i<=n; i++) {
        if(gcd(i,n)==1)
            root.push_back(p);
        p=p*tempi%tempn;
    }
}

//二次剩余：
//给定N,p 求解x^2同余N(mod p)
//此处的mod与下面的p都是模数
//quad_n = n ，quad_a是找到的满足a^2-n是二次非剩余的a，quad_a = a
LL quad_a, quad_n, mod;

LL lrand(LL x, LL p) {
    return qpow(x%p, (p-1)/2, p);
}

struct Zi {
    LL x, y;
    Zi operator * (Zi m) {
        return {(x*m.x%mod+y*m.y%mod*(quad_a*quad_a%mod-quad_n)%mod)%mod,(x*m.y%mod+y*m.x%mod)%mod};
    }
    Zi qpow(LL b) {
        Zi res={1,0},x=(*this);
        while(b) {
            if(b&1)
                res=res*x;
            x=x*x;
            b>>=1;
        }
        return res;
    }
};

LL quad_residue(LL n, LL p) {
    if(n%p==0) return 0;
    if(lrand(n, p)!=1) return -1;//无解
    LL i=rand()%p;
    quad_n = n;
    while(1) {
        if(lrand(i*i-n, p)==p-1) {
            quad_a = i;
            break;
        } else i=rand()%p;
    } 
    Zi ans={quad_a,1};
    return ans.qpow((p+1)/2).x%p;
    /*
    //调整ans；求另一个答案
        if(ans<0) ans=(p+ans)%p;
        ans2=(p-ans)%p;
    */
}

//_M = m[i]的累乘
//f[]:余数，m[]:模数
//以下代码用qmul卡常
LL CRT(LL f[], LL m[], LL n, LL M) {
    LL ans = 0;
    for(LL i=1; i<=n; i++) {
        LL Mi=M/m[i], inv, z;
        exgcd(Mi, m[i], inv, z);
        ans = (ans+qmul(qmul(Mi, inv, M), f[i], M))%M;
    }
    return (ans+M)%M;
}

//a^x=b mod p，给定a,b,p 求最小非负x
//a p互质
LL bsgs(LL a, LL b, LL p) {
    LL t=sqrt(p)+1;
    map<LL,LL>mp;
    LL m=b%p;
    for(LL i=0; i<t; i++) {
        mp[m]=i+1;
        m=m*a%p;
    }
    LL temp=qpow(a,t,p);
    m=temp;
    for(LL i=1; i<=t; i++) {
        if(mp[m])
            return i*t-mp[m]+1;
        m=m*temp%p;
    }
    return -1;//无解
}

//a^x=b mod p，给定a,b,p 求最小非负x
//a p不互质
LL exbsgs(LL a, LL b, LL p) {
    if(b==1||p==1) return 0;
    LL d,cnt=0,ai=1;
    while((d=gcd(a,p))>1) {
        if(b%d) return -1;
        b/=d; p/=d; ai=(ai*a/d)%p; cnt++;
        if(b==ai) return cnt;
    }
    LL x,y;
    exgcd(ai,p,x,y);
    LL inv=(x+p)%p;
    LL res=bsgs(a,b*inv%p,p);
    if(res==-1) return -1;
    return res+cnt;
}

//数论分块：f(i)=floor(n/i)=t的取值范围是[l,r]
void divide_block(LL n) {
    for(LL l=1,r; l<=n; l=r+1) {
        LL t=n/l;
        if(t) r=min(n,n/t);
        else r=n;
        //根据题目要求在[l,r]内进行对应操作
    }
}

//旋转染色polya n个点n种颜色，莫比乌斯反演后
LL polya_rotate(LL n, LL mod) {
    LL res = 0;
    for(LL i=1; i<=sqrt(n); i++) {
        if(n%i) continue;
        res = (res+qpow(n, i, mod)*getonephi(n/i)%mod)%mod;
        if(i*i!=n) res=(res+qpow(n, n/i, mod)*getonephi(i)%mod)%mod;
    }
    return res*qpow(n, mod-2, mod)%mod;
}

//翻转染色polya n个结点，m种颜色
LL polya_roll(LL n, LL m) {
    LL ans = 0;
    if(n&1) ans = n*qpow(m, (n+1)/2);
    else {
        ans = n/2*qpow(m, n/2);
        ans = n/2*qpow(m, n/2+1);
    }
    ans/=n;
    return ans;
}

//旋转+翻转染色 polya n个结点 m种颜色
LL polya_roll_rotate(LL n, LL m) {
    LL ans = 0;
    for(LL i=1; i<=n; i++) ans+=qpow(m, gcd(i, n));
    if(n&1) ans = n*qpow(m, (n+1)/2);
    else {
        ans = n/2*qpow(m, n/2);
        ans = n/2*qpow(m, n/2+1);
    }
    ans/=2*n;
    return ans;
}

//杜教筛sum
//大概预处理到n^(2/3)

LL maxx = INT_MAX;//输入的最大数
#define N pow(maxx, (2/3))
unordered_map<LL,LL>hashmu;
unordered_map<LL,LL>hashphi;

LL summu(LL n) {
    // if(n<=N) return mu[n]; //预处理莫比乌斯函数的前N项和，直接输出
    if(hashmu[n]) return hashmu[n];
    LL res = 1;
    for(LL i=2,j; i<=n; i=j+1) {
        j=n/(n/i);
        res -= summu(n/i)*(j-i+1);
    }
    return hashmu[n]=res;
}

LL sumphi(LL n) {
    // if(n<=N) return phi[n]; //预处理欧拉函数的前N项和，直接输出
    if(hashphi[n]) return hashphi[n];
    LL res = n*(n+1)/2;
    for(LL i=2,j; i<=n; i=j+1) {
        j = n/(n/i);
        res -= 1LL*sumphi(n/i)*(j-i+1);
    }
    return hashphi[n] = res;
}

//下面的代码是调用complex库的FFT写法
//注释掉的是自己写的复数结构体的FFT写法
/*
struct Complex {
	LD x , y;
	Complex(LD xx=0 , LD yy=0) {
		x=xx , y=yy;
	}
	Complex operator + (Complex a) {
		return Complex(x+a.x,y+a.y);
	}
	Complex operator - (Complex a) {
		return Complex(x-a.x,y-a.y);
	}
	Complex operator * (Complex a) {
		return Complex(x*a.x-y*a.y,x*a.y+y*a.x);
	}
}; 
#define cp Complex
*/

#define cp complex<LD>

//高精度乘法时一定要逆序存储

void fft(cp a[], LL n, LL inv) {
    LL r[maxn];//记得放到外面
    LL bit=1; while((1<<bit)<n) bit++;
    for(LL i=0; i<n; i++) {
        r[i] = (r[i>>1]>>1) | ((i&1)<<(bit-1));
        if(i<r[i]) swap(a[i], a[r[i]]);
    }
    for(LL mid=1; mid<n; mid<<=1) {
        cp wi(cos(PI/mid), inv*sin(PI/mid));
        for(LL i=0; i<n; i+=mid<<1) {
            cp wn(1,0);
            for(LL j=0; j<mid; j++,wn=wn*wi) {
                cp x=a[i+j], y=wn*a[i+j+mid];
                a[i+j]=x+y, a[i+j+mid]=x-y;
            }
        }
    }
}

//g是模数的原根
//通常意义下，模数是998244353
#define g 3

void ntt(LL a[], LL n, LL inv) {
    LL r[maxn];//记得放到外面
    LL bit=1; while((1<<bit)<n) bit++;
    for(LL i=0; i<n; i++) {
        r[i] = (r[i>>1]>>1) | ((i&1)<<(bit-1));
        if(i<r[i]) swap(a[i], a[r[i]]);
    }
    for(LL mid=1; mid<n; mid<<=1) {
        LL gi=qpow(g, (mod-1)/(mid<<1), mod);
        if(inv==-1) gi=qpow(gi, mod-2, mod);
        for(LL i=0; i<n; i+=mid<<1) {
            LL gn = 1;
            for(LL j=0; j<mid; j++,gn=gn*gi) {
                LL x=a[i+j], y=gn*a[i+j+mid]%mod;
                a[i+j]=(x+y)%mod; a[i+j+mid]=(x-y+mod)%mod;
            }
        }
    }    
}

LL invert(LL x) {
    LL bit = 1;
    while((1<<bit)<x) bit++;
    return (1<<bit);
}

void fft_init() {
    LL n, m, t; cp a[maxn], b[maxn];//记得放到外面
    cin>>n>>m; t=invert(n+m);
    // for(int i=0; i<=n; i++) cin>>a[i].x;
    // for(int i=0; i<=m; i++) cin>>b[i].x;
    for(int i=0; i<=n; i++) {
        double x; cin>>x;
        a[i].real(x);
    }
    for(int i=0; i<=m; i++) {
        double x; cin>>x;
        b[i].real(x);
    }
    fft(a, t, 1);
    fft(b, t, 1);
    for(int i=0; i<=t; i++) a[i]=a[i]*b[i];
    fft(a, t, -1);
    for(int i=0; i<=n+m; i++) cout<<(int)(a[i].real()/t+0.5)<<" ";
    // for(int i=0; i<=n+m; i++) cout<<(int)(a[i].x/t+0.5)<<" ";
}

void ntt_init() {
    LL n, m, t; LL a[maxn], b[maxn];
    cin>>n>>m; t=invert(n+m);
    for(int i=0; i<=n; i++) cin>>a[i];
    for(int i=0; i<=m; i++) cin>>b[i];
    ntt(a, t, 1);
    ntt(b, t, 1);
    for(int i=0; i<=t; i++) a[i]=a[i]*b[i]%mod;
    ntt(a, t, -1);
    for(int i=0; i<=n+m; i++) cout<<a[i]*qpow(t, mod-2, mod)%mod<<" ";
}

// 高精度模板（我的，有点慢）
// 加减乘除模

int stringmax(string num1, string num2) {
    LL len1=num1.length(), len2=num2.length();
    bool flag = 0, flag2 = 0;
    if(len2>len1) flag = 1;
    if(len1==len2) {
        Fo(i,0,len1-1) {
            if(num2[i]>num1[i]) {
                flag = 1;
                break;
            } else if(num1[i]>num2[i]) {
                flag2 = 1;
                break;
            }
        }
        if(flag) {
        	return 1;
		}
        if(!flag2) {
            return 0; //num1 == num2
    	} else {
    		return 2;
		}
    }
    if(flag) return 1; // num1 < num2
    return 2; // num1 > num2;
} 

string stringadd(string num1, string num2) {
    string num3 = "";
    LL len1 = num1.length(), len2 = num2.length();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    LL len3 = min(len1, len2);
    LL pre = 0;
    Fo(i,0,len3-1) {
        LL a = num1[i]-'0', b = num2[i]-'0';
        LL c = (a+b+pre);
        if(c>=10) {
        	pre = c/10;
        	c %= 10;
		} else {
			pre = 0;
		}
        num3 += c+'0';
    }
    if(len3==len1) {
        Fo(i,len3,len2-1) {
            LL a = num2[i]-'0';
            LL c = (a+pre);
	        if(c>=10) {
	        	pre = c/10;
	        	c %= 10;
			} else {
				pre = 0;
			}
            num3 += c+'0';
        }
    } else {
        Fo(i,len3,len1-1) {
            LL a = num1[i]-'0';
            LL c = (a+pre);
	        if(c>=10) {
	        	pre = c/10;
	        	c %= 10;
			} else {
				pre = 0;
			}
            num3 += c+'0';
        }
    }
    if(pre) num3 += pre+'0';
    reverse(num3.begin(), num3.end());
    return num3;
}

string stringdel(string num1, string num2) {
	int op = stringmax(num1, num2);
	if(!op) return "0";
	else if(op==1) swap(num1, num2); 
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    LL len1=num1.length(), len2=num2.length();
    bool pre = 0;
    string num3 = "";
    Fo(i,0,len2-1) {
        LL a = num1[i]-'0', b = num2[i]-'0';
        if(pre) {
            if(!a) {
                pre = 1;
                a = 9;
            } else {
                a--;
                pre = 0;
            }
        }
        if(a>=b) {
            num3 += (a-b)+'0';
        } else {
            pre = 1;
            a += 10;
            num3 += (a-b)+'0';
        }
    }
    if(len1>len2) {
        Fo(i,len2,len1-1) {
            LL a = num1[i]-'0';
            if(pre) {
                if(!a) {
                    pre = 1;
                    a = 9;
                } else {
                    a--;
                    pre = 0;
                }                
            }
            num3 += a+'0';
        }
    }
    reverse(num3.begin(), num3.end());
    LL l = num3.length(), top = 0;
    string num4 = "";
    if(op==1) num4 += '-';
    Fo(i,0,l-1) {
        if(num3[i]!='0') {
            top = i;
            break;
        }
    }
    Fo(i,top,l-1) num4 += num3[i];
    return num4;
}

string stringmul(string num1, char num2) {
    string num3 = "";
    LL b = num2-'0';
    LL len = num1.length();
    LL pre = 0;
    reverse(num1.begin(), num1.end());
    Fo(i,0,len-1) {
        LL a = num1[i]-'0';
        LL c = a*b+pre;
        if(c>=10) {
            pre = c/10;
            c %= 10;
        } else {
            pre = 0;
        }
        num3 += c+'0';
    }
    if(pre) num3 += pre+'0';
    reverse(num3.begin(), num3.end());
    return num3;
}

string stringmul2(string num1, string num2) {
    LL len = num2.length();
    string num3 = "0";
    string num4 = "";
    Ro(i,len-1,0) {
        string temp = stringmul(num1, num2[i]);
        temp += num4;
        num4 += '0';
        num3 = stringadd(num3, temp);
    }
    if(!atoi(num3.c_str())) return "0";
    else {
        LL l = num3.length();
        LL top = 0;
        Fo(i,0,l-1) {
            if(num3[i]!='0') {
                top = i;
                break;
            }
        }
        string ans = "";
        Fo(i,top,l-1) ans += num3[i]; 
        return ans;
    }
}

string stringdiv1(string num1, LL num2) {
    string num3 = "";
    LL len = num1.length();
    LL pre = 0;
    Fo(i,0,len-1) {
        pre = pre*10+(num1[i]-'0');
        if(pre<num2) continue;
        Ro(j,9,1) {
            if(num2*j<=pre) {
                num3 += j+'0';
                pre -= num2*j;
                break;
            }
        }
    }
    return num3;
}

string stringdiv2(string num1, string num2) {
    int op = stringmax(num1, num2);
    if(!op) return "1";
    else if(op==1) return "0";
    else {
        string num3="", num4="";
        LL len1=num1.length(), len2=num2.length();
        Fo(i,0,len1-1) {
            num3 += num1[i];
            int op1 = stringmax(num3, num2);
            if(op1==1) continue;
            Ro(j,9,1) {
                string temp = stringmul(num2, j+'0');
                int op2 = stringmax(temp, num3);
                if(op2<2) {
                    num4 += j+'0';
                    num3 = stringdel(num3, temp);
                    break;
                }
            }
        }
        LL l = num4.length(), top = 0;
        string num5 = "";
        Fo(i,0,l-1) {
            if(num4[i]!='0') {
                top = i;
                break;
            }
        }
        Fo(i,top,l-1) num5 += num4[i];
        return num5;
    }
}

string stringmod(string num1, string num2) {
    string divv = stringdiv2(num1, num2);
    return stringdel(num1, stringmul2(num2, divv));    
}

// 高精度模板

class Bigint
{
public :
    //constructor 
    Bigint(long long = 0);
    Bigint(const string &);
    Bigint(const char *str) { *this = string(str); }

    //assignment operators
    Bigint &operator=(long long num) { return *this = Bigint(num); }
    Bigint &operator=(const string &str) { return *this = Bigint(str); }
    Bigint &operator=(const char *str) { return *this = Bigint(str); }

    //relatiional operators 
    bool operator<(const Bigint &obj) const { return cmp(obj) < 0; }
    bool operator>(const Bigint &obj) const { return cmp(obj) > 0; }
    bool operator<=(const Bigint &obj) const { return cmp(obj) <= 0; }
    bool operator>=(const Bigint &obj) const { return cmp(obj) >= 0; }
    bool operator==(const Bigint &obj) const { return cmp(obj) == 0; }
    bool operator!=(const Bigint &obj) const { return cmp(obj) != 0; }

    //arithmetic operators
    Bigint operator+() const { return *this; }
    Bigint operator-() const { return Bigint(-sign_, val_); }
    Bigint operator+(const Bigint &) const;
    Bigint operator-(const Bigint &) const;
    Bigint operator*(const Bigint &) const;
    Bigint operator/(const Bigint &) const;
    Bigint operator%(const Bigint &) const;

    //compound assignment operators
    Bigint &operator+=(const Bigint &obj) { return *this = *this + obj; }
    Bigint &operator-=(const Bigint &obj) { return *this = *this - obj; }
    Bigint &operator*=(const Bigint &obj) { return *this = *this * obj; }
    Bigint &operator/=(const Bigint &obj) { return *this = *this / obj; }
    Bigint &operator%=(const Bigint &obj) { return *this = *this % obj; }

    //increment and decrement operators
    Bigint &operator++() { return *this += 1; }
    Bigint &operator--() { return *this -= 1; }
    Bigint operator++(int);
    Bigint operator--(int);

    //input and output
    friend istream &operator>>(istream &, Bigint &);
    friend ostream &operator<<(ostream &, const Bigint &);

protected :
    enum div_type { division, remainder };
    enum cmp_type { with_sign, without_sign };
    static const int base_ = (int)1e4;
    static const int width_ = 4;
    Bigint(int s, const vector<int> &v) : sign_(s), val_(v) {}
    int cmp(const Bigint &, cmp_type = with_sign) const;
    Bigint &delZero();
    Bigint &add(const Bigint &);
    Bigint &sub(const Bigint &);
    Bigint &mul(const Bigint &, const Bigint &);
    Bigint &div(Bigint &, Bigint, div_type = division);

private :
    int sign_;
    vector<int> val_;
};

Bigint::Bigint(long long num) : sign_(0)
{
    if (num < 0) sign_ = -1, num = -num;
    else if (num > 0) sign_ = 1;
    do
    {
        val_.push_back(num % base_);
        num /= base_;
    } while (num);
}

Bigint::Bigint(const string &str)
{
    sign_ = str[0] == '-' ? -1 : 1;
    int be = str[0] == '-' ? 1 : 0, en = str.size();
    while ((en -= width_) >= be)
    {
        stringstream ss(str.substr(en, width_));
        int temp;
        ss >> temp;
        val_.push_back(temp);
    }
    if ((en += width_) > be)
    {
        stringstream ss(str.substr(be, en - be));
        int temp;
        ss >> temp;
        val_.push_back(temp);
    }
    delZero();
}

Bigint Bigint::operator+(const Bigint &obj) const
{
    if (sign_ * obj.sign_ == 1)
    {
        Bigint temp;
        return cmp(obj, without_sign) >= 0 ? (temp = *this).add(obj) : (temp = obj).add(*this);
    }
    else if (sign_ * obj.sign_ == -1) return *this - -obj;
    else return sign_ == 0 ? obj : *this;
}

Bigint Bigint::operator-(const Bigint &obj) const
{
    if (sign_ * obj.sign_ == 1)
    {
        Bigint temp;
        return cmp(obj, without_sign) >= 0 ? (temp = *this).sub(obj) : (temp = -obj).sub(*this);
    }
    else if (sign_ * obj.sign_ == -1) return *this + -obj;
    else return sign_ == 0 ? -obj : *this;
}

inline Bigint Bigint::operator*(const Bigint &obj) const
{
    Bigint temp;
    return (temp.sign_ = sign_ * obj.sign_) == 0 ? temp : temp.mul(*this, obj);
}

inline Bigint Bigint::operator/(const Bigint &obj) const
{
    Bigint temp, mod = *this;
    return cmp(obj, without_sign) < 0 || (temp.sign_ = sign_ * obj.sign_) == 0 ? temp : temp.div(mod, obj);
}

inline Bigint Bigint::operator%(const Bigint &obj) const
{
    Bigint temp, mod = *this;
    return cmp(obj, without_sign) < 0 || (temp.sign_ = sign_) == 0 ? mod : temp.div(mod, obj, remainder);
}

inline Bigint Bigint::operator++(int)
{
    Bigint temp = *this;
    ++*this;
    return temp;
}

inline Bigint Bigint::operator--(int)
{
    Bigint temp = *this;
    --*this;
    return temp;
}

inline istream &operator>>(istream &in, Bigint &obj)
{
    string str;
    if (in >> str) obj = str;
    return in;
}

ostream &operator<<(ostream &out, const Bigint &obj)
{
    if (obj.sign_ == -1) cout << '-';
    out << obj.val_.back();
    for (int i = obj.val_.size() - 2; i >= 0; i--)
        out << setw(Bigint::width_) << setfill('0') << obj.val_[i];
    return out;
}

int Bigint::cmp(const Bigint &obj, cmp_type typ) const
{
    if (typ == with_sign && sign_ != obj.sign_) return sign_ - obj.sign_;
    int sign = typ == with_sign ? sign_ : 1;
    if (val_.size() != obj.val_.size()) return sign * (val_.size() - obj.val_.size());
    for (int i = val_.size() - 1; i >= 0; i--)
        if (val_[i] != obj.val_[i]) return sign * (val_[i] - obj.val_[i]);
    return 0;
}

inline Bigint &Bigint::delZero()
{
    while(val_.back() == 0 && val_.size() > 1) val_.pop_back();
    if (val_.back() == 0) sign_ = 0;
    return *this;
}

Bigint &Bigint::add(const Bigint &obj)
{
    int ts = val_.size(), os = obj.val_.size();
    for (int i = 0; i < os; i++) val_[i] += obj.val_[i];
    val_.push_back(0);
    for (int i = 0; i < ts; i++)
        if (val_[i] >= base_) val_[i] -= base_, ++val_[i + 1];
    return delZero();
}

Bigint &Bigint::sub(const Bigint &obj)
{
    int pos = obj.val_.size();
    for (int i = 0; i < pos; i++)
        if ((val_[i] -= obj.val_[i]) < 0) val_[i] += base_, --val_[i + 1];
    while (val_[pos] < 0) val_[pos] += base_, --val_[++pos];
    return delZero();
}

Bigint &Bigint::mul(const Bigint &a, const Bigint &b)
{
    int as = a.val_.size(), bs = b.val_.size();
    val_.resize(as + bs);
    for (int i = 0; i < as; i++) for (int j = 0; j < bs; j++)
    {
        int x = i + j;
        val_[x] += a.val_[i] * b.val_[j];
        val_[x + 1] += val_[x] / base_;
        val_[x] %= base_;
    }
    return delZero();   
}

Bigint &Bigint::div(Bigint &a, Bigint b, div_type typ)
{
    int move = a.val_.size() - b.val_.size();
    val_.resize(move + 1);
    b.val_.insert(b.val_.begin(), move, 0);
    for (int i = move; i >= 0; i--)
    {
        int left = 0, right = base_;
        while (left + 1 < right)
        {
            int mid = (left + right) >> 1;
            if (a.cmp(b * Bigint(mid), without_sign) >= 0) left = mid;
            else right = mid;
        }
        val_[i] = left;
        a.sub(b * Bigint(left));
        b.val_.erase(b.val_.begin());
    }
    return typ == division ? delZero() : a;
}

// 高精度模板使用示例
// int main()
// {
//     Bigint a, b;
//     cin >> a >> b;
//     cout << a + b << endl;
//     if (a > b) cout << a - b << endl;
//     else cout << '-' << b - a << endl;
//     cout << a * b << endl;
//     cout << a / b << endl;
//     cout << a % b << endl;
//     return 0;
// }

// 扩展欧拉定理：求a^b%m
void exoula() {
    LL a, b, m;
    cin>>a>>m;
	LL p = getonephi(m);
	cin>>b;
	if(b&&b<p) cout<<qpow(a, b, m);
	else cout<<qpow(a, b%p+p, m);
}

// 扩展中国剩余定理
// https://www.luogu.com.cn/blog/niiick/solution-p4777
// https://blog.csdn.net/Xm_wy/article/details/115526285
struct _exCRT {
    static const LL maxn = 1e5+5;
    LL n, m[maxn], a[maxn];
    inline LL qmul(LL a, LL b, LL p) {
        LL ans = 0;
        while(b>0) {
            if(b&1) ans = (ans+a)%p;
            a = a*2%p;
            b>>=1;
        }
        return ans;
    }
    LL exgcd(LL a, LL b, LL &x, LL &y) {
        if(!b) {
            x=1; y=0;
            return a;
        }
        LL d=exgcd(b, a%b, x, y);
        LL k = x; x = y;
        y = k-a/b*y;
        return d;
    }
    LL exCRT() {
        LL M=m[1], ans=a[1];
        Fo(i,2,n) {
            LL x, y;
            LL gcd = exgcd(M, m[i], x, y);
            LL c = ((a[i]-ans)%m[i]+m[i])%m[i];
            if(c%gcd) return -1;
            LL d = m[i]/gcd;
            x = qmul(x, c/gcd, d);
            ans += x*M;
            M *= d;
            ans = (ans%M+M)%M;
        }
        return (ans%M+M)%M;
    }
};

// 求行列式的值
struct _det {
    static const LL maxn = 605;
    LL n, a[maxn][maxn], mod;
    LL det() {
        LL ans=1, w=1;
        Fo(i,1,n) {
            Fo(j,i+1,n) {
                while(a[i][i]) {
                    LL div = a[j][i]/a[i][i];
                    Fo(k,i,n) a[j][k] = (a[j][k]-div*a[i][k]%mod+mod)%mod;
                    swap(a[i], a[j]);
                    w *= (-1);
                }
                swap(a[i], a[j]);
                w *= (-1);
            }
        }
        ans = w;
        Fo(i,1,n) ans=ans*a[i][i]%mod;
        return (ans%mod+mod)%mod;
    }
};

// 线性基
// https://www.luogu.com.cn/blog/szxkk/solution-p3812
struct _LB {
    static const LL maxn = 55;
    static const LL maxm = 51;
    LL n, a[maxn], p[maxn], cnt=0;
    void insert() {
        Fo(i,1,n) {
            LL x = a[i];
            Ro(j,maxm,0) {
                if(x&(1LL<<j)) {
                    if(!p[j]) {
                        p[j] = x;
                        // cnt++;
                        break;
                    } else {
                        x^=p[j];
                    }
                }
            }
        }
    }
    bool insert(LL x) {
        Ro(i,maxm,0) {
            if(x&(1LL<<i)) {
                if(!p[i]) {
                    p[i] = x;
                    return 1;
                } else {
                    x ^= p[i];
                }
            }
        }
        return 0;
    }
    LL maxXor() {
        LL ans = 0;
        Ro(i,maxm,0) {
            if((ans^p[i])>ans) {
                ans ^= p[i];
            }
        }
        return ans;
    }
};

// 多重集组合数
// https://blog.csdn.net/HenryYang2018/article/details/89469891
struct _multiC {
    LL n, s, a[maxn], ans;
    void multiC() {
        inv2(20, mod);
        cin>>n>>s;
        ans = C2(n+s-1, n-1);
        Fo(i,1,n) cin>>a[i];
        LL len = (1LL<<n)-1;
        Fo(i,1,len) {
            LL cnt=0, x=n+s;
            Fo(j,0,n-1) {
                if(i&(1<<j)) {
                    cnt ++;
                    x -= a[j+1]; 
                }
            }
            x -= (cnt+1);
            LL p = (cnt&1)?(-1):1;
            ans = ((ans + p*C2(x, n-1)%mod)%mod+mod)%mod;
        } 
        cout<<(ans%mod+mod)%mod;
    } 
};

// 期望的线性性
// https://blog.csdn.net/coco56181712/article/details/77975421

// 错排问题
// https://blog.csdn.net/BaiJian12138/article/details/125884517
struct _misSort {
    void solve() {
        LL n; cin>>n;
        vector<LL> f(n+1);
        f[1]=0; f[2]=1;
        Fo(i,3,n) f[i]=(i-1)*(f[i-1]+f[i-2]);
        cout<<f[n];
    }
};


```

# string

```c++
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

typedef long long LL;

unordered_map<string, int>mp;

int hash(string s, int t) {
    mp[s] = t;
}

int gethash(string s) {
    return mp[s];
}

const int maxn = 1e3+5;
const char base = 'a';
int num = 0;
//不同题目的Trie内的成员不同
struct Trie {
    int son[26], fail, cnt, end;
    Trie() {
        memset(son, 0, sizeof(son));
        cnt = end = 0;
    }
}trie[maxn];

void trie_insert(string s) {
    int u = 0;
    for(int i=0; i<s.length(); i++) {
        int v = s[i]-base;
        if(!trie[u].son[v]) trie[u].son[v] = ++num;
        u = trie[u].son[v];
        trie[u].cnt++;
    }
    trie[u].end++;
}

//ans的更新和返回部分，需要根据题目自己写
int trie_find(string s) {
    int ans=0, u=0;
    for(int i=0; i<s.length(); i++) {
        int v = s[i]-base;
        if(!trie[u].son[v])  return ans;
        u = trie[u].son[v];
        //ans += trie[u].end;
    }
    // return ans;
}

void nxt(string s, int t[]) {
    int p1=0, p2=-1;
    t[0] = -1;
    while(p1<s.length()) {
        if(p2==-1 || s[p1]==s[p2])
            t[++p1] = ++p2;
        else p2 = t[p2];
    }
}

void KMP(string s1, string s2) {
    int x[s2.length()+5], p1=0, p2=0;
    nxt(s2, x);
    while(p1<s1.length()) {
        if(p2==-1 || s1[p1]==s2[p2]) {
            p1++;
            p2++;
        } else p2 = x[p2];
        if(p2 == s2.length()) {
            //s2在s1中出现的位置是:p1-s2.length()+1
            p2 = x[p2];
        }
    }
}

int mpp[maxn];

void trie_insert(string s, int id) {
    int u = 0;
    for(int i=0; i<s.length(); i++) {
        int v = s[i]-base;
        if(!trie[u].son[v]) trie[u].son[v] = ++num;
        u = trie[u].son[v];
    }
    trie[u].end = id;
    mpp[id] = trie[u].end;
}

void aca_fail() {
    queue<int>q;
    for(int i=0; i<26; i++)
        if(trie[0].son[i]) {
            trie[trie[0].son[i]].fail = 0;
            q.push(trie[0].son[i]);
        }
    while(!q.empty()) {
        int u=q.front(); q.pop();
        for(int i=0; i<26; i++)
            if(trie[u].son[i]) {
                trie[trie[u].son[i]].fail = trie[trie[u].fail].son[i];
                q.push(trie[u].son[i]);
            } else trie[u].son[i] = trie[trie[u].fail].son[i];
    }
}

void aca_query(string s, int ans[]) {
    int u = 0;
    for(int i=0; i<s.length(); i++) {
        int v = s[i]-base;
        u = trie[u].son[v];
        for(int j=u; j; j=trie[j].fail)
            ans[mpp[trie[j].end]]++;
            //根据题意修改ans的更新方式
    }
}

void ACA(string s) {
    int ans[maxn];
    memset(ans, 0, sizeof(ans));
    memset(trie, 0, sizeof(trie));
    aca_fail();
    aca_query(s, ans);
    //根据题目要求输出答案，此处为输出ans[mpp[i]]
}

//建议改成char数组，length改成strlen
//所以f和s的长度 等于 2*str的长度
int manacher(string str) {
    int f[maxn<<1];
    memset(f, 0, sizeof(f));
    string s = str+str;
    s[0]='^', s[1]='$'; int j=2;
    for(int i=0; i<str.length(); i++) {
        s[j++] = str[i];
        s[j++] = '$';
    }
    s[j] = '&';
    int mid=1, maxx=1, ans=-1;
    for(int i=1; i<j; i++) {
        if(i<maxx) f[i] = min(maxx-i, f[mid*2-i]);
        else f[i] = 1;
        while(s[i-f[i]]==s[i+f[i]]) f[i]++;
        if(maxx<i+f[i]) {
            mid = i;
            maxx = i+f[i];
        }
        ans = max(ans, f[i]-1);
    }
    return ans;
    //最长回文串长度
}

char s[maxn];//从1开始存，即cin>>(s+1)

/*

解题可能用到的变量的含义：

right：一个结点代表的字符串集合中最长的字符串在原字符串哪里出现过
maxlen：每个结点代表的字符串集合中最长的字符串的长度
np：实际插入的点
nq：虚空的点（调整后加入的点）
fa：fail数组
ch：字典树
sz：right集合的大小，也就是这个结点代表的字符串出现的次数
tot：点的个数，包括虚点和实点

*/

struct SAM {
    //开的数组比较多，适度开long long，容易MLE，一般int就够了
    int ch[maxn<<1][26], fa[maxn<<1], maxlen[maxn<<1], sz[maxn<<1], k[maxn<<1], cnt[maxn<<1];
    vector<int>right[maxn<<1];
    int last, tot;
    void init() {
        last = tot = 1;
        memset(ch[1], 0, sizeof(ch[1]));
    }
    void insert(int c, int pos) {
        int p=last, np=++tot;
        last=np; maxlen[np]=maxlen[p]+1;
        memset(ch[tot], 0, sizeof(ch[tot]));
        for(;p&&!ch[p][c]; p=fa[p]) ch[p][c]=np;
        if(!p) fa[np]=1;
        else {
            int q=ch[p][c];
            if(maxlen[p]+1==maxlen[q]) fa[np]=q;
            else {
                int nq=++tot; maxlen[nq]=maxlen[p]+1;
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                fa[nq] = fa[q]; fa[q] = fa[np] = nq;
                for(; ch[p][c]==q; p=fa[p]) ch[p][c]=nq;
                //更新nq信息
            }
        }
        //更新np
        sz[np] = 1;
        right[np].push_back(pos);
    }
    void build() {
        init();
        int n=strlen(s+1);
        for(int i=1; i<=n; i++) insert(s[i]-'a',i);

        for(int i=1; i<=tot; i++) cnt[maxlen[i]]++;
        for(int i=1; i<=tot; i++) cnt[i]+=cnt[i-1];
        for(int i=1; i<=tot; i++) k[cnt[maxlen[i]]--]=i;

        for(int i=tot; i>=1; i--) {
            int id = k[i];
            sz[fa[id]] += sz[id];
            for(auto &j:right[id]) right[fa[id]].push_back(j);
        }

        //在这里求答案

        for(int i=1;i<=tot;i++) cnt[i]=sz[i]=0;
    }
}sam;

/*

SA 后缀数组

数组含义解释：

height：后缀排序后，第i个字符串和第i-1个字符串公共前缀的长度
rak：rank数组，以第i个字符为后缀开始的字符串 在后缀排序后排第几？
sa：排名第i的数组 是以第几个字符串为后缀开始的？

*/

int wa[maxn], wb[maxn], wv[maxn], wss[maxn], rak[maxn], height[maxn], cal[maxn], n, sa[maxn];

int cmp(int *r, int a, int b, int l) {
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

void da(int *r, int *sa, int n, int M) {
    int i, j, p, *x=wa, *y=wb, *t;
    for(i=0; i<M; i++) wss[i]=0; 
    for(i=0; i<n; i++) wss[x[i]=r[i]]++; 
    for(i=1; i<M; i++) wss[i]+=wss[i-1]; 
    for(i=n-1; i>=0; i--) sa[--wss[x[i]]]=i; 
    for(j=1, p=1; p<n; j*=2, M=p) {
        for(p=0, i=n-j; i<n; i++) y[p++]=i; 
        for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j; 
        for(i=0; i<n; i++) wv[i]=x[y[i]]; 
        for(i=0; i<M; i++) wss[i]=0; 
        for(i=0; i<n; i++) wss[wv[i]]++; 
        for(i=1; i<M; i++) wss[i]+=wss[i-1]; 
        for(i=n-1; i>=0; i--) sa[--wss[wv[i]]]=y[i]; 
        for(t=x, x=y, y=t, p=1, x[sa[0]]=0, i=1; i<n; i++) x[sa[i]]=cmp(y, sa[i-1], sa[i], j)?p-1:p++; 
    }
}
void calheight(int *r, int *sa, int n) {
     int i, j, k=0; 
     for(i=1; i<=n; i++) rak[sa[i]]=i; 
     for(i=0; i<n; height[rak[i++]]=k)
     for(k?k--:0, j=sa[rak[i]-1]; r[i+k]==r[j+k]; k++); 
     for(int i=n; i; i--) rak[i]=rak[i-1], sa[i]++; 
}

void da_init() {
    while(cin>>(s+1)) {
        n=strlen(s+1); 
        for(int i=1; i<=n; i++) cal[i]=s[i]; //第i位置的字符大小，不能是0
        cal[n+1]=0;  //n+1处位置一定等于0
        da(cal+1, sa, n+1, 200); //200是字符集大小
        calheight(cal+1, sa, n); // sa height rank 都是1-n的
        //到这里height sa rak数组都计算出来了
    }
}

/*

这里的maxn是平时的maxn的3倍，用N代替
下面的define是为了防止和上面da算法中数组重名

*/

#define wa _wa
#define ws _ws
#define wb _wb
#define wv _wv
#define sa _sa
#define rak _rak
#define height _height
#define cal _cal
#define n _n
#define calheight _calheight

#define F(x) ((x) / 3 + ((x) % 3 == 1 ? 0 : tb))
#define G(x) ((x) < tb ? (x) * 3 + 1 : ((x) - tb) * 3 + 2)
const int N = 3*(1e6+5);
int wa[N], wb[N], ws[N], wv[N], sa[N];
int rak[N], height[N], cal[N], n;

int c0(int *r, int a, int b) {
    return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}

int c12(int k, int *r, int a, int b) {
    if (k == 2) return r[a] < r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
    return r[a] < r[b] || r[a] == r[b] && wv[a + 1] < wv[b + 1];
}

void Rsort(int *r, int *a, int *b, int n, int m) {
    for(int i = 0; i < n; i++) wv[i] = r[a[i]];
    for(int i = 0; i < m; i++) ws[i] = 0;
    for(int i = 0; i < n; i++) ws[wv[i]]++;
    for(int i = 1; i < m; i++) ws[i] += ws[i - 1];
    for(int i = n - 1; i >= 0; i--) b[--ws[wv[i]]] = a[i];
}

void dc3(int *r, int *sa, int n, int m) {
    int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
    r[n] = r[n + 1] = 0;
    for(i = 0; i < n; i++) if (i % 3 != 0) wa[tbc++] = i;
    Rsort(r + 2, wa, wb, tbc, m);
    Rsort(r + 1, wb, wa, tbc, m);
    Rsort(r, wa, wb, tbc, m);
    for(p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
        rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
    if (p < tbc) dc3(rn, san, tbc, p);
    else for(i = 0; i < tbc; i++) san[rn[i]] = i;
    for(i = 0; i < tbc; i++) if (san[i] < tb) wb[ta++] = san[i] * 3;
    if (n % 3 == 1) wb[ta++] = n - 1;
    Rsort(r, wb, wa, ta, m);
    for(i = 0; i < tbc; i++) wv[wb[i] = G(san[i])] = i;
    for(i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for(; i < ta; p++) sa[p] = wa[i++];
    for(; j < tbc; p++) sa[p] = wb[j++];
    //for(int i=n;i;i--) rak[i]=rak[i-1];
    //for(int i=n;i;i--) sa[i]++;
}

void calheight(int *r, int *sa, int n) {
    int i, j, k = 0;
    for(i = 1; i <= n; i++) rak[sa[i]] = i;
    for(i = 0; i < n; height[rak[i++]] = k)
        for(k ? k-- : 0, j = sa[rak[i] - 1]; r[i + k] == r[j + k]; k++);
    for(int i=n;i;i--) rak[i]=rak[i-1];
    for(int i=n;i;i--) sa[i]++;
}

void dc3_init() {
    while (cin>>(s+1)) {
        n=strlen(s+1);
        for(int i=1; i<=n; i++) cal[i]=s[i]; //第i位置的字符大小，不能是0
        cal[n+1]=0;  //n+1处位置一定等于0
        da(cal+1, sa, n+1, 200); //200是字符集大小
        calheight(cal+1, sa, n); // sa height rank 都是1-n的
        //到这里height sa rak数组都计算出来了
    }
}
```

