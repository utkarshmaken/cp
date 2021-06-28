#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int numDecodings(string s){
    int n = s.size();
    int prev = 1, prev2 = 1;
    for(int i = 0; i < n; i++){
        int ans = 0;
        if(s[i]!='0') ans = prev;
        if(i>0 && stoi(s.substr(i-1,2))>=10 && stoi(s.substr(i-1,2))<=26)
            ans+=prev2;
        swap(prev2,prev);
        prev = ans;
    }
    return prev;
}
 
int main(){
    string s;
    cin>>s;
    ll num = 0;
    for(auto &x:s)
        num = num*2 + (x-'0');
    string t = to_string(num);
    cout<<numDecodings(t)<<endl;
}