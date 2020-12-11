#include <bits/stdc++.h>
using namespace std;


int find(vector<int> obstacle){
    int n = obstacle.size();
    map<int,int> m;
    m[2] = 0;
    for(int i = 0; i < n; i++){
        int x = obstacle[i];
        map<int,int>  nm;
        for(auto it:m){
            int pos = it.first, d = it.second;
            for(int j = 1; j <= 3; j++){
                if(j != x){
                    if(j != pos){
                        if(nm.find(j) != nm.end())
                            nm[j] = min(nm[j],d+1);
                        else
                            nm[j] = d+1;
                    }
                    else{
                        if(nm.find(pos) != nm.end())
                            nm[pos] = min(nm[pos],d);
                        else
                            nm[pos] = d;
                    }
                }
            }
        }
        m = nm;
    }
    int ans = INT_MAX;
    for(auto it:m) ans = min(ans,it.second);
    return ans;
}

int main(){
    vector<int> obstacle = {2,1,2};
    cout<<find(obstacle);
}