#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    freopen("data.txt","r",stdin);
    // cin.tie(nullptr)->sync_with_stdio(false);    
	int n;
    // cin >> n;
    scanf("%lld\n",&n);
    bool flag = true;
    signed ch;
    while ((ch = getchar()) != EOF){
        if (flag) {
            putchar(ch - 'a' + 'A');
            flag = false;
        } else if (ch == ' ') {
            flag = true;
        } else if (ch == '\n') {
            flag = true;
            putchar(ch);
        }
    }
    return 0;
}