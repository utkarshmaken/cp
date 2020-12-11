//LUCKY SEQUENCES 1
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        ll x,p;
        cin>>x>>p;
        ll maxi = x/p;
        cout<<maxi<<endl;
        string s = to_string(maxi);
        int len = s.size();
        if(len == 1){
            cout<<stol(s)<<endl;
            continue;
        }
        vector<pair<int,int>> ans;
        ans.push_back({s[0]-'0',1});
        bool dec = false;
        for(int i = 1;i<len;i++){
            if(dec){
                ans.back().second+=1;
                continue;
            }
            int x1 = ans.back().first;
            int x2 = s[i] - '0';
            if(x1 == x2) ans.back().second+=1;
            else if(x2 > x1)
                ans.push_back({x2,1});
            else{
                int l = ans.back().second;
                ans.pop_back();
                ans.push_back({x1-1,1});
                ans.push_back({9,l});
                dec = true;
            }
        }
        string res = "";
        for(auto &x:ans)
            res+=string(x.second,('0' + x.first));
        cout<<stol(res)<<endl;
    }
    return 0;
}
