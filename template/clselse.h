/*

开太多long long容易T
如果int相乘放到long long中，最好再乘1ll
函数中的数组不要太大，不然容易内存过大而RE
模板自带long long，如果需要的话，分析数据规模改一些为int

*/

//By cls1277
#include<bits/stdc++.h>
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


bool judge(int x) {
    //写二分的判断
}

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

LL n;

//三分
double func(double x, double a[]) {
    double ans = 0;
    for(int i=0; i<=n; i++) ans += a[i]*pow(x , n-i);
    return ans;
}

void three_divide() {
    double a[maxn], l, r, midl, midr;
    for(int i=0; i<=n; i++) cin>>a[i];
    while(fabs(r-l)>=eps) {
        midl = (l+r)/2;
        midr = (midl+r)/2;
        if(func(midl, a)<func(midr, a))//func是具体的函数表达式
            l = midl;
        else
            r = midr;
    }
    cout<<l;//最终答案存在l里
}