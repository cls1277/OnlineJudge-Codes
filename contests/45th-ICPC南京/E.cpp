//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define ls x<<1
#define rs x<<1|1
#define endl '\n'

const LL maxn = 1e5+5;
LL n, m, l, cnt[4], color;
struct Node {
    LL x, y, i;
};
LL dx[4] = {0,0,-1,1};
LL dy[4] = {1,-1,0,0};
char s[maxn];
char op[4]={'U','D','L','R'};
map<char, LL>mp;

bool bfs() {
    queue<Node>q;
    q.push({0,0,0});
    bool flag = false;
    while(!q.empty()) {
        Node u=q.front(); q.pop();
        if(u.x==n&&u.y==m) flag = true;
        if(u.i==l) return flag;
        LL f = mp[s[u.i+1]];
        u.x += dx[f];
        u.y += dy[f];
        u.i ++;
        q.push(u);
    }
    return flag;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    mp['U']=0; mp['D']=1; mp['L']=2; mp['R']=3;
    while(t--) {
        vector<LL>c;
        color = 0;
        cin>>n>>m; cin>>(s+1);
        if(!n&&!m) {
            cout<<"Impossible"<<endl;
            continue;
        }
        l = strlen(s+1);
        if(!bfs()) {
            cout<<(s+1)<<endl;
            continue;
        }
        Fo(i,0,3) cnt[i] = 0;
        Fo(i,1,l) cnt[mp[s[i]]]++;
        Fo(i,0,3) if(cnt[i]) c.push_back(i);
        color = c.size();
        bool flag = false;
        if(color==1) {
            cout<<"Impossible"<<endl;
            continue;
        } else {
            do {
                LL idx = 0;
                for(auto &it:c)
                    Fo(i,1,cnt[it])
                        s[++idx] = op[it];
                if(!bfs()) {
                    flag = true;
                    break;
                }
            }while(next_permutation(c.begin(), c.end()));
        }
        if(flag) cout<<(s+1)<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}