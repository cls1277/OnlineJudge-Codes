#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
const int maxn = 5e5 + 5;

struct Pos {
    Pos(int x, int y)
        : x(x)
        , y(y)
    {
    }
    int x, y;
    friend bool operator<(const Pos& p1, const Pos& p2)
    {
        if (p1.x != p2.x) {
            return p1.x < p2.x;
        }
        return p1.y < p2.y;
    }
};

set<Pos> sp;

// int xy[maxn][2];

unordered_map<int, int> mx;
unordered_map<int, int> my;
unordered_map<int, int> ma; // x + y
unordered_map<int, int> ms; // x - y

bool check(int x, int y)
{
    for (const auto& p : sp) {
        int dx = p.x - x;
        int dy = p.y - y;
        if (dx != 0 && dy != 0 && abs(dx) != abs(dy)) {
            return false;
        }
    }
    return true;
}

void solve()
{
    sp.clear();
    mx.clear();
    my.clear();
    ma.clear();
    ms.clear();
    int n;
    cin >> n;
    int x = maxn, y = maxn, xay = maxn, xsy = maxn;
    bool res = true;
    for (int i = 0; i < n; i++) {
        int px, py;
        cin >> px >> py;
        sp.emplace(px, py);
    }
    for (const auto& p : sp) {
        if (mx[p.x]++ == 3) {
            if (x == maxn) {
                x = p.x;
            } else {
                res = false;
                break;
            }
        }
        if (my[p.y]++ == 3) {
            if (y == maxn) {
                y = p.y;
            } else {
                res = false;
                break;
            }
        }
        if (ma[p.x + p.y]++ == 3) {
            if (xay == maxn) {
                xay = p.x + p.y;
            } else {
                res = false;
                break;
            }
        }
        if (ms[p.x - p.y]++ == 3) {
            if (xsy == maxn) {
                xsy = p.x - p.y;
            } else {
                res = false;
                break;
            }
        }
    }

    if (res == false) {
        // 啥也不做，发生冲突，一定不行
    } else if (x != maxn) { // 确定x
        if (y != maxn) { // 确定y
            res = check(x, y);
        } else if (xay != maxn) { // 确定x+y
            y = xay - x;
            res = check(x, y);
        } else if (xsy != maxn) { // 确定x-y
            y = x - xsy;
            res = check(x, y);
        } else { // 其他不能确定
            for (const auto& p : sp) {
                if (p.x == x)
                    continue;
                y = p.y;
                res = check(x, y);
                if (res) {
                    break;
                }
                xay = p.x + p.y;
                y = xay - x;
                res = check(x, y);
                if (res) {
                    break;
                }
                xsy = p.x - p.y;
                y = x - xsy;
                if (res) {
                    break;
                }
            }
        }
    } else if (y != maxn) { // 确定y
        if (xay != maxn) { // 确定x+y
            x = xay - y;
            res = check(x, y);
        } else if (xsy != maxn) { // 确定x-y
            x = xsy + y;
            res = check(x, y);
        } else { // 其他不能确定，逐个x试
            for (const auto& p : sp) {
                if (p.y == y)
                    continue;
                x = p.x;
                res = check(x, y);
                if (res) {
                    break;
                }
                xay = p.x + p.y;
                x = xay - y;
                res = check(x, y);
                if (res) {
                    break;
                }
                xsy = p.x - p.y;
                x = xsy + y;
                if (res) {
                    break;
                }
            }
        }
    } else if (xay != maxn) { // 确定x+y
        if (xsy != maxn) { // 确定x-y
            x = (xay + xsy) / 2;
            y = xay - x;
            res = check(x, y);
        } else { // 其他不能确定，一个一个试
            for (const auto& p : sp) {
                if (p.x + p.y == xay)
                    continue;
                x = p.x;
                y = xay - x;
                res = check(x, y);
                if (res) {
                    break;
                }
                y = p.y;
                x = xay - y;
                res = check(x, y);
                if (res) {
                    break;
                }
                xsy = p.x - p.y;
                x = (xay + xsy) / 2;
                y = xay - x;
                res = check(x, y);
                if (res) {
                    break;
                }
            }
        }
    } else if (xsy != maxn) { // 只能确定xsy
        for (const auto& p : sp) {
            if (p.x - p.y == xsy)
                continue;
            x = p.x;
            y = x - xsy;
            res = check(x, y);
            if (res) {
                break;
            }
            y = p.y;
            x = xsy + y;
            res = check(x, y);
            if (res) {
                break;
            }
            xay = p.x + p.y;
            x = (xay+xsy)/2;
            y = xay - x;
            res = check(x, y);
            if (res) {
                break;
            }
        }
    } else { // 小于12个点
        for (const auto& i : mx) {
            x = i.first;
            for (const auto& j : my) {
                y = j.first;
                res = check(x, y);
                if (res) {
                    break;
                }
            }
            if (res) {
                break;
            }
            for (const auto& j : ma) {
                xay = j.first;
                y = xay - x;
                res = check(x, y);
                if (res) {
                    break;
                }
            }
            if (res) {
                break;
            }
            for (const auto& j : ms) {
                xsy = j.first;
                y = x - xsy;
                res = check(x, y);
                if (res) {
                    break;
                }
            }
            if (res) {
                break;
            }
        }
        if (!res)
            for (const auto& i : my) {
                y = i.first;
                for (const auto& j : ma) {
                    xay = j.first;
                    x = xay - y;
                    res = check(x, y);
                    if (res) {
                        break;
                    }
                }
                if (res) {
                    break;
                }
                for (const auto& j : ms) {
                    xsy = j.first;
                    x = xsy + y;
                    res = check(x, y);
                    if (res) {
                        break;
                    }
                }
                if (res) {
                    break;
                }
            }
        if (!res)
            for (const auto& i : ma) {
                xay = i.first;
                for (const auto& j : ms) {
                    xsy = j.first;
                    x = (xay + xsy) / 2;
                    y = xay - x;
                    res = check(x, y);
                    if (res) {
                        break;
                    }
                }
                if (res) {
                    break;
                }
            }
    }
    cout << (res ? "YES" : "NO") << endl;
}

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
