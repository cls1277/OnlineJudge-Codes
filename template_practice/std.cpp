#include <bits/stdc++.h>
using namespace std;

int read() {
    int k = 1, x = 0;
    char s = getchar();
    while (s < '0' || s > '9') {
        if (s == '-')
            k = -1;
        s = getchar();
    }
    while (s >= '0' && s <= '9') {
        x = (x << 3) + (x << 1) + s - '0';
        s = getchar();
    }
    return x * k;
}

const int MAXN = 5e3 + 5;
const double q = 0.996;
// 温度变动量
struct node {
    double x, y;
    node() {}
    node(double X, double Y) {
        x = X;
        y = Y;
    }
} a[MAXN], now, anst;
// now 初值为 A1，在这里是 (0, 0)
double ans = 1e18;
// 答案初值

int n;
double f(double x, double y) {
    double ret = 0;
    for (int i = 1; i <= n; i++) ret += sqrt((x - a[i].x) * (x - a[i].x) + (y - a[i].y) * (y - a[i].y));
    return ret;
}

void Make_Fire() {
    double t = 3000;
    while (t > 1e-16) {
        double cx = now.x + ((rand() << 1) - RAND_MAX) * t;
        double cy = now.y + ((rand() << 1) - RAND_MAX) * t;
        // 求到 A 的横坐标，在这里是 (cx, cy)
        double cnt = f(cx, cy);
        // 求到 A
        double delta = cnt - ans;
        // 求到差
        if (delta < 0) { // 如果差是小于 0 的
            now = node(cx, cy);
            // 接纳它
            anst = node(cx, cy);
            // 根据题目需要，更新答案的坐标
            ans = cnt;
            // 跟新答案
        } else if (exp(-delta / t) * RAND_MAX > rand())
        // 玄学接受准则
            now = node(cx, cy);
            // 接纳它
        t *= q;
        // 降温
    }
}

int main() {
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    srand(998244353);
    n = read();
    ans = 1e18;
    for (int i = 1; i <= n; i++) 
        scanf("%lf %lf", &a[i].x, &a[i].y);
    for (int i = 1; i <= 5; i++) Make_Fire();
    printf("%.2lf %.2lf\n", anst.x, anst.y);
    cout<<ans;
    return 0;
}