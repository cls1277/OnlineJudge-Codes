//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

// const LL maxn = ;
int n, id=1;

struct Node {
    int num;
    Node * next;
    Node() {};
    Node(int _num):num(_num), next(nullptr) {};
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    while(cin>>n&&n) {
        cout<<"Scenario #"<<id++<<endl;
        unordered_map<int, int> group;
        unordered_map<int, Node *> where;
        unordered_map<int, bool> iswhere;
        Node * q = new Node(-1);
        Node * p = q;
        Fo(i,1,n) {
            int m; cin>>m;
            Fo(j,1,m) {
                int x; cin>>x;
                group[x] = i;
            }
            iswhere[i] = 0;
        }
        while(1) {
            string str; cin>>str;
            if(str[0]=='S') {
                cout<<endl;
                break;
            } else if(str[0]=='E') {
                int x; cin>>x;
                if(iswhere[group[x]]) {
                    Node * t = where[group[x]];
                    Node * o = new Node(x);
                    o->next = t->next;
                    t->next = o;
                    where[group[x]] = o;
                } else {
                    iswhere[group[x]] = 1;
                    Node * o = new Node(x);
                    p->next = o;
                    p = o;
                    where[group[x]] = o;
                }
            } else {
                if(q->num==-1) q = q->next;
                int val = q->num;
                cout<<val<<endl;
                q = q->next;
                if(q!=nullptr&&q->next!=nullptr) {
                    if(group[q->next->num]!=val) {
                        iswhere[val] = 0;
                    }
                }
            }
        }
    }
    return 0;
}