#include <bits/stdc++.h>
using namespace std;

int chooseFlask(vector<int> requirements, int flaskTypes, vector<vector<int>> markings){
    int n = requirements.size();
    int ans = INT_MAX, idx = -1;
    map<int,set<int>> m;
    for(auto &v:markings)
        m[v[0]].insert(v[1]);
    for(auto it:m){
        int cnt = 0;
        set<int> s = it.second;
        for(auto &x:requirements){
            auto it1 = s.lower_bound(x);
            if(it1 == s.end()){
                cnt = -1;
                break;
            }
            else
            {
                cnt += (*it1 - x);
            }
        }
        if(cnt != -1){
            if(cnt < ans){
                ans = cnt;
                idx = it.first;
            }
        }
    }
    return idx;
}
int main(){
    vector<int> requirements = {4,5,6,7};
    vector<vector<int>> markings = {{0,3}, {0,5}, {0,7}, {1,6}, {1,8}, {1,9}};
    cout<<chooseFlask(requirements,3,markings);
}