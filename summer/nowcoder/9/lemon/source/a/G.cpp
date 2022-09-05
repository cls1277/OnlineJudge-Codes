#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 3e5 + 5;
const int base = 37;

int hash1[maxn];
int hash2[maxn];
int p[maxn];

int gethash1(int l, int r)
{
    return hash1[r] - hash1[l - 1] * p[r - l + 1];
}

int gethash2(int l, int r)
{
    return hash2[l] - hash2[r + 1] * p[r - l + 1];
}

signed main()
{
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout); 
    cin.tie(nullptr)->sync_with_stdio(false);
    p[0] = 1;
    for (int i = 1; i < maxn; i++) {
        p[i] = p[i - 1] * base;
    }
    int T;
    long long ttt;
    cin >> ttt;
    T = ttt;
    string s;
    unordered_map<long long, long long> mp;
    for (int _t = 0; _t < T; _t++) {
        cin >> s;
        int n = s.size();
        hash1[0] = 0;
//        hash1[n + 1] = 1919810;
//        hash2[0] = 1919810;
        hash2[n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            hash1[i] = hash1[i - 1] * base + s[i - 1] - 'a' + 1;
        }
        for (int i = n; i > 0; i--) {
            hash2[i] = hash2[i + 1] * base + s[i - 1] - 'a' + 1;
        }

        unordered_set<long long> ss;
        for (int i = 1; i <= n; i++) {
            // ÆæÊý
            {
                int l = 1, r = min(i, n - i);
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (gethash1(i - mid, i + mid) == gethash2(i - mid, i + mid)) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                for (int j = r; j >= 0; j--) {
                    // cout << i << " " << j << " " << i - j - 1 << " " << 2 * j + 1 << endl;
                    if (ss.find(gethash1(i-j,i+j)) != ss.end()) {
                        break;
                    }
                    ss.insert(gethash1(i-j,i+j));
                }
            }
            // Å¼Êý
            {
                int l = 1, r = min(i, n - i);
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (gethash1(i - mid + 1, i + mid) == gethash2(i - mid + 1, i + mid)) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                for (int j = r; j > 0; j--) {
                    // cout << i << " " << j << " " << i - j << " " << 2 * j << endl;
                    if (ss.find(gethash1(i-j+1, i+j)) != ss.end()) {
                        break;
                    }
                    ss.insert(gethash1(i-j+1, i+j));
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
    ttt = ans;
    cout << ttt << endl;
    return 0;
}
