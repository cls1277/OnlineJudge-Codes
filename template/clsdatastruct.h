#include<iostream>
#include<algorithm>
#include<cmath>
#include<deque>
#include<queue>

using std::cin;
using std::max;
using std::min;
using std::deque;


typedef long long LL;

const LL maxn = 1e3+5;

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
    Que(){}
    Que(LL oo , LL nn) {
        ops=oo , num=nn;
    }
};
deque<Que>q1;
deque<Que>q2;

void solo_queue() {
    LL maxx[maxn], minn[maxn], cnt=0;
    for(int i=1; i<=n; i++) {
        cin>>m;
        while(!q1.empty()&&m>=q1.back().num)
            q1.pop_back();
        q1.push_back(Que(i,m));
        while(i-k+1>q1.front().ops)
            q1.pop_front();
        while(!q2.empty()&&m<=q2.back().num)
            q2.pop_back();
        q2.push_back(Que(i,m));
        while(i-k+1>q2.front().ops)
            q2.pop_front();
        if(i>=k) {
            cnt++;//记录了划过的窗口数
            maxx[cnt] = q1.front().num;
            minn[cnt] = q2.front().num;
        }
    }
}