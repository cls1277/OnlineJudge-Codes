#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 5003;
int dp[maxn];

struct Triangle {
    int a, b, c;
    Triangle(int a = 0, int b = 0, int c = 0)
        : a(a)
        , b(b)
        , c(c)
    {
    }
    int C() const {
        return a + b + c;
    }
    void sort() {
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }
        if (a > b) {
            swap(a, b);
        }
    }
} t[maxn*10];

struct Rect {
    int a, b, c, d;
    Rect(int a, int b, int c, int d) : a(a),b(b),c(c),d(d) {}
    void sort() {
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }
        if (c > d) {
            swap(c, d);
        }
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }
        if (a > b) {
            swap(a, b);
        }
    }
    int C() const {
        return a + b + c + d;
    }
};


inline void update(int i, int v) {
    dp[i] = min(dp[i], v);
}

inline void update(const Triangle& t) {
    // dp[t.C()] = min(dp[t.C()], t.c - t.a);
    update(t.C(), t.c - t.a);
}

inline void update(Rect& r) {
    if (dp[r.C()] == INT32_MAX) {
        cout << "如果没有输出这个我就不写了" << endl;
        r.sort();
        update(r.C(), r.d - r.a);
    }
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 0; i < maxn; i++) {
        dp[i] = INT32_MAX;
    }
    // 生成三角形
    int cnt = 0;
    for (int a = 1; 3 * a < maxn; a++) {
        for (int b = a; a + 2 * b < maxn; b++) {
            for (int c = b; a + b + c < maxn; c++) {
                if (a * a + b * b == c * c) {
                    t[cnt].a = a;
                    t[cnt].b = b;
                    t[cnt].c = c;
                    cnt++;
                }
            }
        }
    }
    // 处理三角形
    int idx = cnt;
    for (int i = 0; i < cnt; i++) {
        update(t[i]);
        for (int j = 0; j < cnt; j++) {
            if (t[i].a == t[j].a && t[i].b + t[j].b + t[i].c + t[j].c < maxn) {
                t[idx] = Triangle(t[i].b+t[j].b, t[i].c , t[j].c);
                t[idx].sort();
                update(t[idx++]);
            } 
            if (t[i].b == t[j].b && t[i].a + t[j].a + t[i].c + t[j].c < maxn) {
                t[idx] = Triangle(t[i].a+t[j].a, t[i].c , t[j].c);
                t[idx].sort();
                update(t[idx++]);
            } 
            if (t[i].a == t[j].b && t[i].b + t[j].a + t[i].c + t[j].c < maxn) {
                t[idx] = Triangle(t[i].b+t[j].a, t[i].c , t[j].c);
                t[idx].sort();
                update(t[idx++]);
            } 
            if (t[i].b == t[j].a && t[i].a + t[j].b + t[i].c + t[j].c < maxn) {
                t[idx] = Triangle(t[i].a+t[j].b, t[i].c , t[j].c);
                t[idx].sort();
                update(t[idx++]);
            } 
        }
    }
    cnt = idx;
    // 处理矩形
    for (int i = 0; i < maxn; i++) {
        if (dp[i] == INT32_MAX) {
            if (i%4==0) update(i, 0);
            else if(i%2==0) update(i, 1);
            // else update(i, -1);
        }
    }
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            if (t[i].a == t[j].a) {
                auto rr = Rect(t[i].b, t[j].b, t[i].c, t[j].c);
                update(rr);
            }
            if (t[i].a == t[j].b) {
                auto rr = Rect(t[i].b, t[j].a, t[i].c, t[j].c);
                update(rr);
            }
            if (t[i].a == t[j].c) {
                auto rr = Rect(t[i].b, t[j].a, t[i].c, t[j].b);
                update(rr);
            }
            if (t[i].b == t[j].a) {
                auto rr = Rect(t[i].a, t[j].b, t[i].c, t[j].c);
                update(rr);
            }
            if (t[i].b == t[j].b) {
                auto rr = Rect(t[i].a, t[j].a, t[i].c, t[j].c);
                update(rr);
            }
            if (t[i].b == t[j].c) {
                auto rr = Rect(t[i].a, t[j].b, t[i].c, t[j].a);
                update(rr);
            }
            if (t[i].c == t[j].a) {
                auto rr = Rect(t[i].a, t[j].b, t[i].b, t[j].c);
                update(rr);
            }
            if (t[i].c == t[j].b) {
                auto rr = Rect(t[i].a, t[j].a, t[i].b, t[j].c);
                update(rr);
            }
            if (t[i].c == t[j].c) {
                auto rr = Rect(t[i].a, t[j].b, t[i].b, t[j].a);
                update(rr);
            }
        }
    }
    // 处理其他情况
    for (int i = 0; i < maxn; i++) {
        if (dp[i] == INT32_MAX) dp[i] = -1;
    }
    // 输出dp
    for (int i = 0; i < maxn; i++) {
        cout << dp[i] << ",";
        if (i%20==19) cout << "\n";
    }
    // cout << cnt << endl;
    return 0;
}
