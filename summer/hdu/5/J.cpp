#include <algorithm>
#include <iostream>
using namespace std;

int a[7];
int b[7];

inline void output(bool flag)
{
    cout << (flag ? "Win!" : "Just a game of chance.") << endl;
}

inline void solve()
{
    // 清零和读取数据
    int n;
    cin >> n;
    for (int i = 1; i <= 6; i++) {
        a[i] = 0;
        b[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[t]++;
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        b[t]++;
    }
    bool finish = false;
    bool win = false;
    // 对a检验第三条规则
    {
        bool flag = true; // 第三条规则
        for (int i = 1; i <= 6; i++) {
            if (a[i] > 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            output(false);
            return;
        }
        // 为什么a符合第三条规则就必输？因为他说什么都是假的可以被拆穿
    }
    // 对b检验第三条规则
    {
        bool flag = true; // 是否符合第三条规则
        for (int i = 1; i <= 6; i++) {
            if (b[i] > 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            output(true); // win
            return;
        }
        // 这里已经保证了a不满足第三条规则，所以只要b满足，a就一定赢
    }
    // 对a检验第二条规则
    {
        int samea = -1; // 相同的点数
        int num1a = a[1]; // 点数1的个数，应用第一条规则
        for (int i = 6; i >= 2; i--) {
            if (a[i] == n - num1a) {
                samea = i;
                break;
            }
        }
        // 如果b也符合第二条规则且点数比a大，那么a就输了
        // 这里判定下b也符合的情况
        int sameb = -1;
        int num1b = b[1];
        for (int i = 6; i >= 2; i--) {
            if (b[i] == n - num1b) {
                sameb = i;
                break;
            }
        }
        // 这里只讨论a符合第二条规则的所有情况
        if (samea != -1) {
            // 如果b不符合第二条规则，则a必胜
            if (sameb == -1) {
                output(true);
                return;
            } else if (samea >= sameb) {
                // 在可以应用第一条规则的情况下，如果a和b同时符合第二种规则
                // 那么a点数大的话，a就会应用这个规则，否则a会ban掉第一条规则
                output(true);
                return;
            } else if (num1a == 0 || num1b == 0) {
                // 如果b是硬爷们，或者a是硬爷们，那a就输了
                output(false);
                return;
            } else {
                // 如果不是，那a就会废掉规则1公平对决
                // a第一步被限定为吹1的个数，直接出最大个数应该是最优
                int maxa = 1;
                int maxa_cnt = a[1];
                // 这个时候主动权到了b，b需要取让a最难受的
                for (int i = 6; i > 1; i--) {
                    if (a[i] >= maxa_cnt) {
                        maxa = i;
                        maxa_cnt = a[i];
                    }
                    if (maxa == i && b[i] >= maxa_cnt) {
                        output(false);
                        return;
                    }
                    if (maxa == 1 && b[i] >= maxa_cnt) {
                        output(false);
                        return;
                    }
                    if (maxa != i && maxa != 1 && b[i] > maxa_cnt) {
                        output(false);
                        return;
                    }
                }
                // 都到这了，b还搞不死a那a就赢了
                output(true);
                return;
            }
        }
    }
    // 对b检验第二条规则
    {
        int same = -1;
        int num1 = b[1];
        for (int i = 2; i <= 6; i++) {
            if (b[i] == n - num1) {
                same = i;
                break;
            }
        }
        // 这里需要特别讨论一下同时应用第一条规则和第二条规则的情况，因为a只要说出1就可以阻止b这么做
        if (num1 == n) { // 极为特殊的满足第二条规则且可以应用第一条规则
            output(false); // 不论a说什么，b都能拿出更大的
            return;
        }
        if (same != -1 && num1 != 0) { // 此时b有可能应用第二条规则，a应该先吹1的牛，即a，b都不使用第一条规则
            // 这里面比较复杂，下面这段可能可以放到后面判断
            // a第一步被限定为吹1的个数，直接出最大个数应该是最优
            int maxa = 1;
            int maxa_cnt = a[1];
            // 这个时候主动权到了b，b需要取让a最难受的
            for (int i = 6; i > 1; i--) {
                if (a[i] >= maxa_cnt) {
                    maxa = i;
                    maxa_cnt = a[i];
                }
                if (maxa == i && b[i] >= maxa_cnt) {
                    output(false);
                    return;
                }
                if (maxa == 1 && b[i] >= maxa_cnt) {
                    output(false);
                    return;
                }
                if (maxa != i && maxa != 1 && b[i] > maxa_cnt) {
                    output(false);
                    return;
                }
            }
            // 都到这了，b还搞不死a那a就赢了
            output(true);
            return;
        }
        if (same != -1 && num1 == 0) { // 如果b是不需要应用第一条规则的纯爷们
            if (same == 6) { // b已经最大了，a必输，这里不用考虑a，b都同时符合第二条且点数一样的情况，因为前面已经判定了
                output(false);
                return;
            }
            if (a[1] != 0) { // 此时b一定没6，a应用第一条规则说有6就赢了
                output(true);
                return;
            }
            // 这里不用考虑a，b都同时符合第二条且点数一样的情况，因为前面已经判定过了
            for (int i = same + 1; i <= 6; i++) {
                if (a[i] >= 1) { // a一开始就喊一个比b大的，直接赢了
                    output(true);
                    return;
                }
            }
        }
    }
    // 无法应用第二条和第三条规则
    // 判断a使用第一条规则
    {
        // 如果应用第一条规则a能必赢，那就考虑应用第一条规则
        int maxb = 0; // b 目前的最大点数
        int maxb_cnt = 0; // b 目前最大点数的个数
        for (int i = 6; i >= 2; i--) {
            if (b[i] + b[1] >= maxb_cnt) {
                maxb = i;
                maxb_cnt = b[i] + b[1];
            }
            if (maxb != i && a[i] + a[1] > maxb_cnt) {
                output(true);
                return;
            }
            if (maxb == i && a[i] + a[1] >= maxb_cnt && a[i] + a[1] != 0) {
                output(true);
                return;
            }
        }
        // 如果能到这，那说明应用第一条规则，a没办法吹过b，于是决定破坏第一条规则
    }
    // 判断a不使用第一条规则
    {
        // a第一步被限定为吹1的个数，直接出最大个数应该是最优
        int maxa = 1;
        int maxa_cnt = a[1];
        // 这个时候主动权到了b，b需要取让a最难受的
        for (int i = 6; i > 1; i--) {
            if (a[i] >= maxa_cnt) {
                maxa = i;
                maxa_cnt = a[i];
            }
            if (maxa == i && b[i] >= maxa_cnt) {
                output(false);
                return;
            }
            if (maxa == 1 && b[i] >= maxa_cnt) {
                output(false);
                return;
            }
            if (maxa != i && maxa != 1 && b[i] > maxa_cnt) {
                output(false);
                return;
            }
        }
        // 都到这了，b还搞不死a那a就赢了
        output(true);
        return;
    }
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
