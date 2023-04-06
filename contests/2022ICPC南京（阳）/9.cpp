#include<bits/stdc++.h>
using namespace std;

int cnt[30];

int main() {
//    freopen("data.txt","r",stdin);
    int T; scanf("%d",&T);
    while(T--) {
        for(int i=0; i<26; i++) cnt[i] = 0;
        string str; cin>>str; //scanf("%s",str);
        int len = str.length();
        for(int i=0; i<len; i++) {
            cnt[str[i]-'a']++;
        }
        int mx = -1;
        for(int i=0; i<26; i++) {
            mx = max(mx, cnt[i]);
        }
        printf("%d\n",len-mx);
    }
    return 0;
}
