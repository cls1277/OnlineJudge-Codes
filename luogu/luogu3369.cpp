//By cls1277
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<sstream>
#include<set>
#include<cassert>
#include<bitset>
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
inline LL read() {
	LL x = 0, f = 1;char c = getchar();
	while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
	while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
	return x * f;
}

const LL maxn = 1e5+5;
#define ls tree[u].l
#define rs tree[u].r
int n , root , id;
struct Node {
	int l , r , val , key , cnt , size;
};
Node tree[maxn];

void pushup(int u) {
	tree[u].size=tree[ls].size+tree[rs].size+tree[u].cnt;
	return ;
}

int build(int v) {
	id++;
	tree[id].val=v; tree[id].key=rand();
	tree[id].cnt = tree[id].size = 1;
	return id;
}

void zig(int &u) {
	//https://blog.csdn.net/yang_yulei/article/details/46005845ÓÐÍ¼Àí½â 
	int p=ls;
	ls=tree[p].r; tree[p].r=u;
	u=p;
	pushup(rs);
	pushup(u);
	return ; 
}

void zag(int &u) {
	int p=rs;
	rs=tree[p].l; tree[p].l=u;
	u=p;
	pushup(ls);
	pushup(u);
	return ;
}

void insert(int &u , int v) {
	if(!u) u=build(v);
	else if(tree[u].val==v) tree[u].cnt++;
	else if(tree[u].val>v) {
		insert(ls,v);
		if(tree[ls].key>tree[u].key) zig(u);
	}else {
		insert(rs,v);
		if(tree[rs].key<tree[u].key) zag(u);
	}
	pushup(u);
	return ;
}

void remove(int &u , int v) {
	if(!u) return ;
	if(tree[u].val==v) {
		if(tree[u].cnt>1) tree[u].cnt--;
		else if(ls||rs) {
			if(!rs||tree[ls].key>tree[rs].key) {
				zig(u);
				remove(rs,v);
			} else {
				zag(u);
				remove(ls,v);
			}
		} else u=0;
	} else if(tree[u].val>v) remove(ls,v);
	else remove(rs,v);
	if(u) pushup(u);
	return ;
}

int vth(int &u , int v) {
	if(!u) return 0;
	if(tree[u].val==v) return tree[ls].size+1;
	if(tree[u].val>v) return vth(ls,v);
	else return tree[ls].size+tree[u].cnt+vth(rs,v);
}

int find(int &u , int v) {
	if(!u) return INF;
	if(tree[ls].size>=v) return find(ls,v);
	if(tree[ls].size+tree[u].cnt>=v) return tree[u].val;
	return find(rs,v-tree[ls].size-tree[u].cnt);
}

int Pre(int &u , int v) {
	if(!u) return -INF;
	if(tree[u].val>=v) return Pre(ls,v);
	return max(tree[u].val,Pre(rs,v));
}

int Next(int &u , int v) {
	if(!u) return INF;
	if(tree[u].val<=v) return Next(rs,v);
	return min(tree[u].val,Next(ls,v));
}

int main() {
	ios::sync_with_stdio(false);
	#ifdef DEBUG
	freopen("data.txt","r",stdin);
	#endif
	cin>>n;
	Fo(i,1,n) {
		int op , x;
		cin>>op>>x;
		if(op==1) insert(root,x);
		else if(op==2) remove(root,x);
		else if(op==3) cout<<vth(root,x)<<endl;
		else if(op==4) cout<<find(root,x)<<endl;
		else if(op==5) cout<<Pre(root,x)<<endl;
		else if(op==6) cout<<Next(root,x)<<endl;
	}
	return 0;
}

