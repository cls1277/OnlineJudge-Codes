#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int a[maxn];

inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

void solve() {
    int n = read();
    a[0] = read();
    int k = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    a[n + 1] = 0;       // �յ�
    int idx = 0;        // ��ǰ¥���±�
    int tk = k;         // ��ʱ��k
    while (idx <= n) {
        cout << "�Ҹմ���ǰ" << idx << "�㣬��������" << a[idx] << "����������������" << tk << "��" << endl;
        int rest = 0;      // ����Ҫ����atk
        int acc = a[idx];  // �ۼ�ֵ
        bool flag = false;  // �ܼ�������ȥ��
        for (int i = idx + 1; i <= idx + tk; i++) {
            rest = max(a[i] - a[idx], rest - a[i]);
            acc += a[i];
            cout << "�������ڼ����" << i << "�㣬����" << a[idx] << "�������һ���Ҫ" << rest << "������" << endl;
            if (rest <= 0) {  // ����
                a[i] = acc;
                tk = min(k - (i - idx - 1), n-i+1);
                idx = i;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

signed main() {
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    // cin.tie(nullptr)->sync_with_stdio(false);
    int T = read();
    while (T--) {
        solve();
    }
    return 0;
}
