/*

开太多long long容易T
如果int相乘放到long long中，最好再乘1ll
函数中的数组不要太大，不然容易内存过大而RE
模板自带long long，如果需要的话，分析数据规模改一些为int
memset() 不要带全部，用多少清空多少，还要看不清空是否《肯定》没影响

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