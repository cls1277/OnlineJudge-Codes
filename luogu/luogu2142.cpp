//By cls1277
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define Fo(i,a,b) for(LL i=(a); i<=(b); i++)
#define Ro(i,b,a) for(LL i=(b); i>=(a); i--)
#define Eo(i,x,_) for(LL i=head[x]; i; i=_[i].next)
#define Ms(a,b) memset((a),(b),sizeof(a))
#define endl '\n'

//const LL maxn = ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    string num1, num2; cin>>num1>>num2;
    LL len1=num1.length(), len2=num2.length();
    bool flag = 0, flag2 = 0;
    if(len2>len1) flag = 1;
    if(len1==len2) {
        Ro(i,len1-1,0) {
            if(num2[i]>num1[i]) {
                flag = 1;
                break;
            } else if(num1[i]>num2[i]) {
                flag2 = 1;
                break;
            }
        }
        if(!flag2) {
        	cout<<0;
        	return 0;
    	}
    }
    if(flag) swap(num1, num2);
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    len1=num1.length(), len2=num2.length();
    bool pre = 0;
    string num3 = "";
    Fo(i,0,len2-1) {
        LL a = num1[i]-'0', b = num2[i]-'0';
        if(pre) {
            if(!a) {
                pre = 1;
                a = 9;
            } else {
                a--;
                pre = 0;
            }
        }
        if(a>=b) {
            num3 += (a-b)+'0';
        } else {
            pre = 1;
            a += 10;
            num3 += (a-b)+'0';
        }
    }
    if(len1>len2) {
        Fo(i,len2,len1-1) {
            LL a = num1[i]-'0';
            if(pre) {
                if(!a) {
                    pre = 1;
                    a = 9;
                } else {
                    a--;
                    pre = 0;
                }                
            }
            num3 += a+'0';
        }
    }
    if(flag) num3 += '-';
    reverse(num3.begin(), num3.end());
    cout<<num3;
    return 0;
}
