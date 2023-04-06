// B.cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int vis[maxn]; // 数字i被访问的下标
int num[maxn*2];
int vidx[maxn*2]; // 第 i 个数是否被访问
int cnt = 0;

bool test(int idx) { // 测试访问第idx个数, 返回是否出现过
    vidx[idx] = 1;
    int nu = num[idx];
    // cout << "正在测试第" << idx << "个数" << nu << endl;
    if (vis[nu]) { // 这个数之前已经出现过
        // cout << "它出现过" << endl;
        cnt++;
        if (!vidx[idx+1]) {
            test(idx+1);
        }
        if (!vidx[vis[nu]+1]) {
            test(vis[nu]+1);
        }
        return true;
    } else {
        vis[nu] = idx;
        return false;
    }
}

void solve()
{
    memset(vis, 0, sizeof vis);
    fill(vidx, vidx+maxn*2, 1);
    int n, k;
    cnt = 0;
    cin >> n >> k;
    int i = 0;
    for (int j = 1; j <= k; j++)
    {
        int len;
        cin >> len; // 这一行的长度
        bool flag = true; // 这一个是否需要立即被访问
        for (int t = 1; t <= len; t++)
        {
            cin >> num[++i];
            if (flag)
            {
                flag = test(i);
            } else {
                vidx[i] = 0;
            }
        }
    }
    // cout << cnt << endl;
    cout << (cnt&1 ? "Kelly" : "Nacho" ) << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}