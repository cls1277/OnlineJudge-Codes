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

string stringmul(string num1, char num2) {
    string num3 = "";
    LL b = num2-'0';
    LL len = num1.length();
    LL pre = 0;
    reverse(num1.begin(), num1.end());
    Fo(i,0,len-1) {
        LL a = num1[i]-'0';
        LL c = a*b+pre;
        if(c>=10) {
            pre = c/10;
            c %= 10;
        } else {
            pre = 0;
        }
        num3 += c+'0';
    }
    if(pre) num3 += pre+'0';
    reverse(num3.begin(), num3.end());
    return num3;
}

string stringadd(string num1, string num2) {
    string num3 = "";
    LL len1 = num1.length(), len2 = num2.length();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    LL len3 = min(len1, len2);
    LL pre = 0;
    Fo(i,0,len3-1) {
        LL a = num1[i]-'0', b = num2[i]-'0';
        LL c = (a+b+pre);
        if(c>=10) {
        	pre = c/10;
        	c %= 10;
		} else {
			pre = 0;
		}
        num3 += c+'0';
    }
    if(len3==len1) {
        Fo(i,len3,len2-1) {
            LL a = num2[i]-'0';
            LL c = (a+pre);
	        if(c>=10) {
	        	pre = c/10;
	        	c %= 10;
			} else {
				pre = 0;
			}
            num3 += c+'0';
        }
    } else {
        Fo(i,len3,len1-1) {
            LL a = num1[i]-'0';
            LL c = (a+pre);
	        if(c>=10) {
	        	pre = c/10;
	        	c %= 10;
			} else {
				pre = 0;
			}
            num3 += c+'0';
        }
    }
    if(pre) num3 += pre+'0';
    reverse(num3.begin(), num3.end());
    return num3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    string num1, num2; cin>>num1>>num2;
    LL len = num2.length();
    string num3 = "0";
    string num4 = "";
    Ro(i,len-1,0) {
        string temp = stringmul(num1, num2[i]);
        temp += num4;
        num4 += '0';
        num3 = stringadd(num3, temp);
    }
    if(!atoi(num3.c_str())) cout<<0;
    else {
        LL l = num3.length();
        LL top = 0;
        Fo(i,0,l-1) {
            if(num3[i]!='0') {
                top = i;
                break;
            }
        }
        Fo(i,top,l-1) cout<<num3[i];
    }
    return 0;
}