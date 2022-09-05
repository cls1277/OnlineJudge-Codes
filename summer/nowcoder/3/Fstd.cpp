#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll n,m,num=0, cnt=0;
ll ans, sum ;
ll DFN[500005], low[500005] ;
ll Num[500005];
bool isC[500005] ;
vector <ll> G[500005] ;
vector<ll> D[500005] ;
ll num1[500005],num2[500005];
ll q,a,b;
ll stk[500005],top=0;
void Tarjan( int x, int fa )
{
    num ++ ;
    DFN[x] = low[x] = num ;
    int kid = 0 ;
    stk[++top]=x;
    for(int i = 0 ; i < G[x].size() ; ++ i )
    {
        int s = G[x][i] ;
        if( !DFN[s] )
        {
            Tarjan( s, x );
            low[x] = min( low[s], low[x] );
            if( low[s] >= DFN[x] )
            {
                kid++;
                if(x!=1||kid>1)
                {
                    isC[x] = 1 ;
                }
                cnt ++ ;
                ll z;
                do
                {
                    z=stk[top--];
                    Num[z]=cnt;
                    D[cnt].push_back(z);
                }while(z!=s);
                D[cnt].push_back( x );
                Num[x]=cnt;
            }
        }
        else if(s != fa )
            low[x] = min( DFN[s], low[x] );
    }
}
int main()
{
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1; i<=m; i++)
    {
        ll a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    Tarjan(1,0);
    ll flag=0;
    for(ll i=1; i<=n&&!flag; i++)
    {
        if(!DFN[i])
        {
            flag=1;
        }
    }
    for(ll i=1; i<=cnt; i++)
    {
        for(ll j=0; j<D[i].size(); j++)
        {
            ll u=D[i][j];
            if(isC[u])
            {
                num1[i]++;
                num2[u]++;
                if(num1[i]>=3||num2[u]>=3)
                {
                    flag=1;
                }
            }
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>a>>b;
        if(flag||isC[a]||isC[b])
        {
            cout<<"NO"<<endl;
        }
        else if(Num[a]==Num[b])
        {
            if(cnt==1)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        else if(num1[Num[a]]==1&&num1[Num[b]]==1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
