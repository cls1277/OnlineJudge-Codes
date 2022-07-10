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
LL idx, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    LL t; cin>>t;
    while(t--) {
        priority_queue<LL> q1;
        priority_queue<LL, vector<LL>, greater<LL>> q2;
        cin>>idx>>n;
        cout<<idx<<' '<<(n+1)/2<<endl;
        LL cnt = 1;
        LL x; cin>>x;
        cout<<x<<' ';
        q2.push(x);
        Fo(i,2,n) {
            cin>>x;
            LL p = q2.top();
            if(x<p) q1.push(x);
            else q2.push(x);
            while(q1.size() > i/2) {
            	q2.push(q1.top());
            	q1.pop();
			}
			while(abs((LL)q2.size()-(LL)q1.size()) > 1) {
				q1.push(q2.top());
				q2.pop();
			}
            if(i&1) {
                cout<<q2.top()<<' ';
                cnt++;
                if(cnt%10==0&&i!=n-1) cout<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
