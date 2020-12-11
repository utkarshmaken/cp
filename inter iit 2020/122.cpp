#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int i = 0, ans = 0;
    while(i < n){
        int j = i;
        while(j<n && s[j] == 'x') ++j;
        ans += (j-i >= 3 ? j-i-2:0);
        i = j+1;
    }
    cout<<ans<<endl;
}