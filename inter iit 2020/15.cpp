//STRING
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string> s(n);
        for(int i = 0;i<n;i++) cin>>s[i];
        vector<vector<int>> weight(n,vector<int>());
        for(int i = 0;i<n;i++){
            int w = 0,max_inc = 0,mini = s[i].size();
            for(auto &x:s[i]){
                int d = x - 'a' + 1;
                w+=d;
                max_inc+=(26-d);
            }
            weight[i] = {w,w+max_inc,mini,i};
        }
        sort(weight.begin(),weight.end());
        int mini = INT_MAX,idx;
        int low = weight[0][0],high = weight[n-1][0];
        for(int wf = low;wf<=high;wf++){
            int change_req  = 0;
            bool poss = true;
            for(int i = 1;i<n-1;i++){
                int w = weight[i][0],ma = weight[i][1],mi = weight[i][2];
                if( (w < wf && ma < wf) || (w > wf && mi > wf) ){
                    poss = false;
                    break;
                }
                change_req+=abs(wf-w);
            }
            if(poss){
                int a = (wf<=weight[0][1]?wf-low:INT_MAX);
                int b = (wf>=weight[n-1][2]?high-wf:INT_MAX);
                if(a==INT_MAX && b==INT_MAX) continue;
                if(a <= b){
                    if(change_req + a < mini){
                        mini = change_req + a;
                        idx = n-1;
                    }
                }
                else{
                    if(change_req + b < mini){
                        mini = change_req + b;
                        idx = 0;
                    }
                }
            }
        }
        cout<<s[weight[idx][3]]<<endl;
    }
}