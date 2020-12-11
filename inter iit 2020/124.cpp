#include <bits/stdc++.h>
using namespace std;

bool palin(string &s, int i, int j){
    while(i < j){
        if(s[i] != s[j]) return false;
        ++i,--j;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        if(n == 1){
            cout<<s<<endl;
            continue;
        }
        int i = 0, j = n-1;
        while(i<j && s[i] == s[j]){
            ++i;--j;
        }
        string s1 = "", s2 = "", s3 = "";
        if(i != 0){
            s.substr(0,i);
            if(i+1<=j) s1 += s[i];
            s1 += s.substr(j+1);
        }

        for(i = n-1; i >= 0; i--)
            if(palin(s,0,i)){
                s2 = s.substr(0,i+1);
                break;
            }
        for(i = 0; i < n; i++)
            if(palin(s,i,n-1)){
                s3 = s.substr(i);
                break;
            }
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        int maxi = max({n1,n2,n3});
        if(n1 == maxi){
            cout<<s1<<endl;
            continue;
        }
        else if(n2 == maxi){
            cout<<s2<<endl;
            continue;
        }
        else
            cout<<s3<<endl;
    }

}