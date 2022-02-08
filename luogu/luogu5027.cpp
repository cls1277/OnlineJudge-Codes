//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PI acos(-1)
#define INF 2147483647
#define eps 1e-6
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define lowbit(_) _&(-_)
#define mk(_,__) make_pair(_,__)
#define pii pair<int,int>
#define ls x<<1
#define rs x<<1|1
#define endl '\n'
inline LL read() {
    LL x = 0, f = 1;char c = getchar();
    while (!isdigit(c)) { if (c == '-')f = -f;c = getchar(); }
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48ll), c = getchar();
    return x * f;
}

const LL maxn = 105;
double a[maxn][maxn],b[maxn][maxn],w[maxn],maxw;
LL n,res[maxn],maxcnt;
bool ans;

int main() {
    ios::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    cin>>n;
    ans = false;
    Fo(i,1,n+1) {
        LL m; cin>>m;
        Fo(j,1,m) {
            LL x; cin>>x;
            b[i][x]+=1;
        }
        double y; cin>>y;
        b[i][n+1]=y;
    }
    // Fo(i,1,n+1) {
    //     Fo(j,1,n+1)
    //         cout<<b[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<"***"<<endl;
    Fo(q,1,n+1) {
        LL cnt=0; bool flag=true;
        Fo(i,1,n+1) {
            if(i==q) continue;
            cnt++;
            Fo(j,1,n+1) {
                a[cnt][j] = b[i][j];
            }
        }
        // Fo(i,1,n) {
        //     Fo(j,1,n+1)
        //         cout<<a[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<"---"<<endl;
        Fo(i,1,n) {
            LL maxrow=i;
            Fo(j,i+1,n)
                if(fabs(a[j][i])>fabs(a[maxrow][i]))
                    maxrow = j;
            if(fabs(a[maxrow][i])<=eps) {
                flag = false;
                break;
            }
            Fo(j,1,n+1)
                swap(a[maxrow][j],a[i][j]);
            Fo(j,1,n) {
                if(i==j) continue;
                double p=a[j][i]/a[i][i];
                Fo(k,i+1,n+1)
                    a[j][k]-=a[i][k]*p;
            }
        }
        if(flag==false) continue;
        maxcnt=maxw=0;
        // Fo(i,1,n) {
        //     Fo(j,1,n+1)
        //         cout<<a[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<"---"<<endl;
        // cout<<n<<endl;
        Fo(i,1,n) {
            w[i]=a[i][n+1]/a[i][i];
            if((int)w[i]<w[i]) {
                flag = false;
                break;
            }
            // cout<<w[i]<<" ";
            if(w[i]<=eps) {
                flag = false;
                break;
            }
            maxw=max(maxw,w[i]);
            // vis[w[i]]++;
            // // cout<<vis[w[i]]<<endl;
            // if(vis[w[i]]>1) {
            //     flag = false;
            // }
        }
        Fo(i,1,n) {
            if(w[i]==maxw) {
                maxcnt++;
                if(maxcnt>1) {
                    flag = false;
                    break;
                }
            }
        }
        // cout<<"---"<<endl;
        // Fo(i,1,n)
            // cout<<w[i]<<" "<<vis[w[i]]<<endl;
        // cout<<endl;
        // cout<<vis[2]<<endl;
        // cout<<"q:"<<q<<" flag:"<<flag<<endl;
        // Fo(i,1,n)
            // cout<<w[i]<<" ";
        // cout<<endl;
        bool op = false;
        if(flag) {
            if(ans==false) {
                Fo(i,1,n)
                    res[i]=w[i];
                ans = true;
            } else {
                Fo(i,1,n)
                    if(res[i]!=w[i]) {
                        ans = false;
                        op = true;
                        break;
                    }
            }
        }
        if(op==true) {
            cout<<"illegal";
            return 0;
        }
    }
    if(ans==false) {
        cout<<"illegal";
        return 0;
    }
    LL maxidx = 1;
    Fo(i,2,n)
        if(res[i]>res[maxidx])
            maxidx = i;
    cout<<maxidx;
    // Fo(i,1,n+1)
    //     Fo(j,1,n+1)
    //         temp[i][j]=a[i][j];
    // Fo(q,1,n+1) {
    //     Fo(i,1,n+1)
    //         Fo(j,1,n+1)
    //             a[i][j]=temp[i][j];
    //     bool flag = false;
    //     Fo(i,1,n+1) {
    //         if(i==q) continue;
    //         LL maxrow = i;
    //         Fo(j,i+1,n+1) {
    //             if(j==q) continue;
    //             if(a[j][i]>a[maxrow][i])
    //                 maxrow = j;
    //         }
    //         if(a[maxrow][i]==0) {
    //             flag = true;
    //             break;
    //         }
    //         Fo(j,1,n+1)
    //             swap(a[i][j],a[maxrow][j]);
    //         Fo(j,1,n+1) {
    //             if(j==q||i==j) continue;
    //             LL p=a[j][i]/a[i][i];
    //             Fo(k,i+1,n+1)
    //                 a[j][k]-=a[i][k]*p;
    //         }
    //     }
    //     Fo(i,1,n+1) {
    //         if(i==q) continue;
    //         Fo(j,1,n+1)
    //             cout<<a[i][j]<<" ";
    //         cout<<endl;
    //     }
    //     if(!flag) {
    //         LL cnt=0;
    //         Fo(i,1,n+1) {
    //             if(i==q) continue;
    //             w[++cnt]=a[i][n+1]/a[i][cnt];
    //             if(w[cnt]<=0) {
    //                 flag = true;
    //                 break;
    //             }
    //         }
    //     }
    //     // Ms(vis,0);
    //     // Fo(i,1,n) {
    //     //     vis[w[i]]++;
    //     //     if(vis[w[i]]>1) {
    //     //         flag = true;
    //     //         break;
    //     //     }
    //     // }
    //     if(flag==false)
    //         cout<<"*"<<q<<endl;
    //     Fo(i,1,n)
    //         cout<<w[i]<<" ";
    //     cout<<endl;
    //     // return 0;
    // }
    // LL minidx=1;
    // Fo(i,2,n) {
    //     if(w[i]>w[minidx])
    //         minidx = i;
    // }
    // cout<<minidx;
    return 0;
}