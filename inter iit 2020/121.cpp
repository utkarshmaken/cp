#include <bits/stdc++.h>
using namespace std;


vector<string> find(int num){
    int n = num;
    vector<string> ans;
    string s(n,'0');
    ans.push_back(s);
    while(true){
        int i;
        for(i = n-1; i >= 0; i--)
            if(s[i] == '0')
                break;
        if(i == -1)
            break;
        s = s.substr(0,i) + "1" + string(n-1-i,'0');
        ans.push_back(s);
    }
    return ans;
}

int main(){
    vector<string> ans = find(3);
    for(auto &x:ans) cout<<x<<endl;
}