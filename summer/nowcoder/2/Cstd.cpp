#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

using i128 = __int128_t;
using u128 = __uint128_t;

namespace debugger {
#ifdef EMOFUNC
    template <typename T>
    void __print_var(string_view name, T && x) { std::cerr << name << " = " << x; }

    template <>
    void __print_var(string_view name, int&& x) { std::cerr << x; }

    template <>
    void __print_var(string_view name, string&& x) { std::cerr << x; }

    template <typename T>
    void __print_var(string_view name, const vector<T>& x) {
        std::cerr << name << " = ";
        bool is_first = true;
        for (auto & ele : x) std::cerr << (is_first ? (is_first = false, "[") : ", ") << ele;
        std::cerr << "]";
    }
    template <typename T>
    void __print_var(string_view name, const set<T>& x) {
        std::cerr << name << " = ";
        bool is_first = true;
        for (auto & ele : x) std::cerr << (is_first ? (is_first = false, "{") : ", ") << ele;
        std::cerr << "}";
    }
    template <typename K, typename V>
    void __print_var(string_view name, const map<K, V>& x) {
        std::cerr << name << " = ";
        bool is_first = true;
        for (auto & [k, v] : x) std::cerr << (is_first ? (is_first = false, "{") : ", ") << "(" << k << ": " << v << ")";
        std::cerr << "}";
    }
    template <typename T>
    void __log(string_view name, T && x) {
        __print_var(name, std::forward<T>(x)); std::cerr << std::endl;
    }
    template <typename T, typename... Ts>
    void __log(string_view name, T && x, Ts &&... others) {
        size_t pos = name.find(',');
        __print_var(name.substr(0, pos), std::forward<T>(x)); std::cerr << ", ";
        __log(name.substr(pos + 1), std::forward<Ts>(others)...);
    }

#define LOG(args...)\
    { std::cerr << "line " << __LINE__ << ": " << __func__ << "(): ";\
    __log(#args, ##args); }
#else
#define LOG(...)
#endif
}
using namespace debugger;


int main(void) {
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        ll tot = 0;
        int sum = 0;
        for (auto& v: a) cin >> v, sum ^= v, tot += v;
        
        if (sum == 0) {
            const int B = 31;
            vector<bool> ok(B, true);
            for (int i = 0; i < n; i++) {
                cout<<(a[i]&-a[i])<<' ';
                for (int j = __lg(a[i] & -a[i]) + 1; j < B; j++) if ((a[i] >> j) & 1) ok[j] = false;
            }
            cout<<endl;

            for (int i = 0; i < B; i++) cout << i << " " << ok[i] << "\n";

            int cnt = 0;
            for (int i = 0; i < n; i++) {
                // cout << i << " " << __lg(a[i] & -a[i]) << "\n";
                if (ok[__lg(a[i] & -a[i])]) cnt++;
            }
            cout << tot << " " << cnt << "\n";
        } else {

            int mx = 0, cnt = 0;
            for (int i = 0; i < n; i++) if (a[i] > (a[i] ^ sum)) {
                int diff = a[i] - (a[i] ^ sum);
                if (diff > mx) {
                    mx = diff;
                    cnt = 1;
                } else if (diff == mx) {
                    mx = diff;
                    cnt++;
                }
            }
            cout << tot - mx + 1 << " " << cnt << "\n";
        }

    }
    
    return 0;
}