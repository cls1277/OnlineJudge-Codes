#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 3e5 + 5;
const int base = 37;
const int mod1 = 1e9 + 9;
const int mod2 = 998244353;

int hash11[maxn]; // order % mod1
int hash12[maxn]; // reverse % mod1
int hash21[maxn]; // order % mod2
int hash22[maxn]; // reverse % mod2
int p1[maxn];
int p2[maxn];

int gethash11(int l, int r)
{
    return (hash11[r] - (hash11[l - 1] - mod1) * p1[r - l + 1]) % mod1;
}

int gethash12(int l, int r)
{
    return (hash12[l] - (hash12[r + 1] -mod1) * p1[r - l + 1]) % mod1;
}

int gethash21(int l, int r)
{
    return (hash21[r] - (hash21[l - 1] - mod2) * p2[r - l + 1]) % mod2;
}

int gethash22(int l, int r)
{
    return (hash22[l] - (hash22[r + 1] - mod2) * p2[r - l + 1]) % mod2;
}

signed main()
{
//	freopen("G.in","r",stdin);
//	freopen("G.out","w",stdout);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin.tie(nullptr)->sync_with_stdio(false);
    p1[0] = 1;
    p2[0] = 1;
    for (int i = 1; i < maxn; i++) {
        p1[i] = (p1[i - 1] * base) % mod1;
        p2[i] = (p2[i - 1] * base) % mod2;
    }
    int T;
    cin >> T;
    string s;
    unordered_map<int, int> mp;
    for (int _t = 0; _t < T; _t++) {
        cin >> s;
        int n = s.size();
        hash11[0] = 0;
        hash11[n + 1] = 5345321;
        hash12[0] = 4213523;
        hash12[n + 1] = 0;
        hash21[0] = 0;
        hash21[n + 1] = 534531;
        hash22[0] = 3423154;
        hash22[n + 1] = 0;

        for (int i = 1; i <= n; i++) {
            hash11[i] = (hash11[i - 1] * base + (s[i - 1] - 'a' + 1)) % mod1;
        }
        for (int i = n; i > 0; i--) {
            hash12[i] = (hash12[i + 1] * base + (s[i - 1] - 'a' + 1)) % mod1;
        }
        for (int i = 1; i <= n; i++) {
            hash21[i] = (hash21[i - 1] * base + (s[i - 1] - 'a' + 1)) % mod2;
        }
        for (int i = n; i > 0; i--) {
            hash22[i] = (hash22[i + 1] * base + (s[i - 1] - 'a' + 1)) % mod2;
        }

        unordered_set<int> ss;
        for (int i = 1; i <= n; i++) {
            // 奇数
            {
                int l = 1, r = min(i, n - i);
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (gethash11(i - mid, i + mid) == gethash12(i - mid, i + mid) && gethash21(i - mid, i + mid) == gethash22(i - mid, i + mid)) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                for (int j = r; j >= 0; j--) {
                    // cout << i << " " << j << " " << i - j - 1 << " " << 2 * j + 1 << endl;
                    if (ss.find(gethash11(i - j, i + j)) != ss.end()) {
                        break;
                    }
                    ss.insert(gethash11(i - j, i + j));
                }
            }
            // 偶数
            {
                int l = 1, r = min(i, n - i);
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (gethash11(i - mid + 1, i + mid) == gethash12(i - mid + 1, i + mid) && gethash21(i - mid + 1, i + mid) == gethash22(i - mid + 1, i + mid)) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                for (int j = r; j > 0; j--) {
                    // cout << i << " " << j << " " << i - j << " " << 2 * j << endl;
                    if (ss.find(gethash11(i - j + 1, i + j)) != ss.end()) {
                        break;
                    }
                    ss.insert(gethash11(i - j + 1, i + j));
                }
            }
        }
        for (const auto& i : ss) {
            // cout << i << " ";
            mp[i]++;
        }
        // cout << endl;
    }
    int ans = 0;
    for (const auto& i : mp) {
        // cout << i.first << " " << i.second << endl;
        if (i.second == T) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
