#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);    
    string a;
    string b;
    int n;
    cin >> n;
    cin >> a >> b;
    int i = n-1;
    for (int j = n - 1; j >= 0; j--) {
        bool flag = false;
        while (i >= 0) {
            if (a[i--] == b[j]) {
                flag = true;
                break;
            }
        }
        if (i < 0) {
            cout << (flag ? j : j+1) << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
