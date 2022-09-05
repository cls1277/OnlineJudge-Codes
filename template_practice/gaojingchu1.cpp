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

int stringmax(string num1, string num2) {
    LL len1=num1.length(), len2=num2.length();
    bool flag = 0, flag2 = 0;
    if(len2>len1) flag = 1;
    if(len1==len2) {
        Fo(i,0,len1-1) {
            if(num2[i]>num1[i]) {
                flag = 1;
                break;
            } else if(num1[i]>num2[i]) {
                flag2 = 1;
                break;
            }
        }
        if(flag) {
        	return 1;
		}
        if(!flag2) {
            return 0; //num1 == num2
    	} else {
    		return 2;
		}
    }
    if(flag) return 1; // num1 < num2
    return 2; // num1 > num2;
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

string stringdel(string num1, string num2) {
	int op = stringmax(num1, num2);
	if(!op) return "0";
	else if(op==1) swap(num1, num2); 
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    LL len1=num1.length(), len2=num2.length();
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
    reverse(num3.begin(), num3.end());
    LL l = num3.length(), top = 0;
    string num4 = "";
    if(op==1) num4 += '-';
    Fo(i,0,l-1) {
        if(num3[i]!='0') {
            top = i;
            break;
        }
    }
    Fo(i,top,l-1) num4 += num3[i];
    return num4;
}

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

string stringmul2(string num1, string num2) {
    LL len = num2.length();
    string num3 = "0";
    string num4 = "";
    Ro(i,len-1,0) {
        string temp = stringmul(num1, num2[i]);
        temp += num4;
        num4 += '0';
        num3 = stringadd(num3, temp);
    }
    if(!atoi(num3.c_str())) return "0";
    else {
        LL l = num3.length();
        LL top = 0;
        Fo(i,0,l-1) {
            if(num3[i]!='0') {
                top = i;
                break;
            }
        }
        string ans = "";
        Fo(i,top,l-1) ans += num3[i]; 
        return ans;
    }
}

string stringdiv1(string num1, LL num2) {
    string num3 = "";
    LL len = num1.length();
    LL pre = 0;
    Fo(i,0,len-1) {
        pre = pre*10+(num1[i]-'0');
        if(pre<num2) continue;
        Ro(j,9,1) {
            if(num2*j<=pre) {
                num3 += j+'0';
                pre -= num2*j;
                break;
            }
        }
    }
    return num3;
}

string stringdiv2(string num1, string num2) {
    int op = stringmax(num1, num2);
    if(!op) return "1";
    else if(op==1) return "0";
    else {
        string num3="", num4="";
        LL len1=num1.length(), len2=num2.length();
        Fo(i,0,len1-1) {
            num3 += num1[i];
            int op1 = stringmax(num3, num2);
            if(op1==1) continue;
            Ro(j,9,1) {
                string temp = stringmul(num2, j+'0');
                int op2 = stringmax(temp, num3);
                if(op2<2) {
                    num4 += j+'0';
                    num3 = stringdel(num3, temp);
                    break;
                }
            }
        }
        LL l = num4.length(), top = 0;
        string num5 = "";
        Fo(i,0,l-1) {
            if(num4[i]!='0') {
                top = i;
                break;
            }
        }
        Fo(i,top,l-1) num5 += num4[i];
        return num5;
    }
}

string stringmod(string num1, string num2) {
    string divv = stringdiv2(num1, num2);
    return stringdel(num1, stringmul2(num2, divv));    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifdef DEBUG
    freopen("data.txt","r",stdin);
    #endif
    string num1, num2; cin>>num1>>num2;
    cout<<stringadd(num1, num2)<<endl;
    cout<<stringdel(num1, num2)<<endl;
    cout<<stringmul2(num1, num2)<<endl;
    string divv = stringdiv2(num1, num2);
    cout<<divv<<endl;
    cout<<stringdel(num1, stringmul2(num2, divv));
    return 0;
}
