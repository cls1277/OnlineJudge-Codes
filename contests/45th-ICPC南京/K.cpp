#include <iostream>
using namespace std;

int main() {
    // return 0;
    freopen("data.txt","r",stdin);
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if (k <= 0) {
        cout << -1;
    } else if (k == 1) {
        cout << 1;
        for (int i = 2; i <= n; ++i) {
            cout << " " << i;
        }
    } else {
        cout << 2;
        for (int i = 3; i <= k; ++i) {
            cout << " " << i;
        }
        cout << " " << 1;
        for (int i = k + 1; i <= n; ++i) {
            cout << " " << i;
        }
    }
}