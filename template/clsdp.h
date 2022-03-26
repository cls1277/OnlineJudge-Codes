#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>

using std::min;
using std::max;
using std::cin;
using std::vector;

typedef long long LL;

const LL maxn = 1e3+5;

LL n, f[maxn], w[maxn], v[maxn], W;

//01背包：一个物品可以取或者不取
void zero_one() {
    for(int i=1; i<=n; i++)
        for(int j=W; j>=w[i]; j--)
            f[j] = max(f[j], f[j-w[i]]+v[i]);
}

//完全背包：一个物品可以取无限次
void full_bags() {
    for(int i=1; i<=n; i++)
        for(int j=w[i]; j<=W; j++)
            f[j] = max(f[j], f[j-w[i]]+v[i]);
}

//多重背包：每种物品不止1个，有k个
//二进制分组优化：1个、2个、4个……合为一个物品，跑01背包
void mul_bags() {
    LL idx = 0;
    for(int i=1; i<=n; i++) {
        LL x, y, z; cin>>x>>y>>z;
        LL k=1;
        while(z>=k) {
            idx++;
            v[idx] = x*k;
            w[idx] = y*k;
            z-=k;
            k<<=1;
        }
        if(z) {
            idx++;
            v[idx] = x*z;
            w[idx] = y*z;
        }
    }
    for(int i=1; i<=idx; i++)
        for(int j=W; j>=w[i]; j--)
            f[j]=max(f[j], f[j-w[i]]+v[i]);
}

//混合背包：三种背包混合起来，有的只能取一次，有的能取无限次，有的只能取k次。
//取k次的又可以跑01背包，所以本质上就是01背包+完全背包，注意两个顺序别搞反了就可以
void mix_bags() {
    vector<LL>v[2];
    vector<LL>w[2]; //0：01背包；1：完全背包
    for(int i=1; i<=n; i++) {
        LL x, y, z; cin>>x>>y>>z;
        if(!z) {
            v[1].push_back(y);
            w[1].push_back(x);
        } else if(z==1) {
            v[0].push_back(y);
            w[0].push_back(x);
        } else {
            LL k=1;
            while(z>=k) {
                v[0].push_back(y*k);
                w[0].push_back(x*k);
                z-=k;
                k<<=1;
            }
            if(z) {
                v[0].push_back(y*z);
                w[0].push_back(x*z);
            }
        }
    }
    LL x = v[0].size()-1;
    for(int i=0; i<=x; i++)
        for(int j=W; j>=w[0][i]; j--)
            f[j] = max(f[j], f[j-w[0][i]]+v[0][i]);
    x = v[1].size()-1;
    for(int i=0; i<=x; i++)
        for(int j=w[1][i]; j<=W; j++)
            f[j] = max(f[j], f[j-w[1][i]]+v[1][i]);
}

//二维费用背包：会消耗两种价值，而不是一个w了，即w是二维数组
void twoD_bags() {
    LL a[maxn], b[maxn];//两种价值
    LL f[maxn][maxn];
    LL A, B;//两种价值限制
    for(int i=1; i<=n; i++)
        for(int j=A; j>=a[i]; j--)
            for(int k=B; k>=b[i]; k--)
                f[j][k] = max(f[j][k], f[j-a[i]][k-b[i]]+v[i]);
}

//分组背包：物品分组，每组物品相互冲突，最多只能选一个物品进去
void group_bags() {
    LL a[maxn], b[maxn], g;//g是分的组数
    vector<LL>c[maxn];//存储每一组中物品编号
    for(LL i=1; i<=n; i++) {
        cin>>a[i]>>b[i];
        LL x; cin>>x;
        c[x].push_back(i);
        g = max(g, x);
    }
    for(int i=1; i<=g; i++)
        for(int j=W; j>=0; j--)
            for(auto &it:c[i])
                if(j>=a[it])
                    f[j] = max(f[j], f[j-a[it]]+b[it]);
}

//有依赖的背包：有主件和附件，选择附件必须选择主件
/*
对于包含一个主件和若干个附件的集合有以下可能性：
仅选择主件，选择主件后再选择一个附件，选择主件后再选择两个附件……
需要将以上可能性的容量和价值转换成一件件物品。因为这几种可能性只能选一种，所以可以将这看成分组背包。
*/

vector<LL>res;//临时存一下选择的物品的编号
vector<LL>son[maxn];
vector<LL>g[maxn];//存储每一个组内的物品（分为每一种可能之后）
LL idx, d;//idx:对每一种可能性编号 d:分的组数
LL vm[maxn], wm[maxn];//每一种可能的价值和花费

void dfs(LL x, LL k, LL id) {
    if(x==k+1) {
        LL a=0, b=0;
        for(auto &it:res) {
            a+=v[son[id][it]];
            b+=w[son[id][it]];
        }
        idx++;
        vm[idx]=a+v[id]; wm[idx]=b+w[id];
        g[d].push_back(idx);
        return ;
    }
    res.push_back(x);
    dfs(x+1, k, id);
    res.pop_back();
    dfs(x+1, k, id);
}

void depend_bags() {
    LL c[maxn], d=0;
    for(int i=1; i<=n; i++) {
        LL x, y, z; cin>>x>>y>>z;
        v[i] = x*y;
        w[i] = x;
        c[i] = z;//表示编号z是编号i的主件
        if(z) son[z].push_back(i); //son[x]:x的附件的集合
    }
    for(int i=1; i<=n; i++) {
        if(son[i].size()) {
            d++;
            res.clear();
            dfs(0, son[i].size()-1, i);
        } else if(!c[i]){
            d++; idx++;
            vm[idx] = v[i];
            wm[idx] = w[i];
            g[d].push_back(idx);
        }
    }
    //分组背包
    for(int i=1; i<=d; i++)
        for(int j=W; j>=0; j--)
            for(auto &it:g[i])
                if(j>=wm[it])
                    f[j] = max(f[j], f[j-wm[it]]+vm[it]);
}