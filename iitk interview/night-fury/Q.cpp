#include <bits/stdc++.h>
using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    string S = "";
    for(auto &x:s){
        if(x!=' ')
            S+=x;
    }
    int n = S.size();
    int r,c;
    int root = sqrt(n);
    if(root*root==n)
        r = c = root;
    else{
        r = root;
        c = root+1;
    }
    char grid[r][c];
    int idx = 0;
    int maxr = 0,maxc = 0;
    for(int i = 0;i<r && idx<n;i++){
        for(int j = 0;j<c && idx<n;j++){
            grid[i][j] = S[idx++];
            maxc = j;
            maxr = max(maxr,i);
        }
    }
    string ans = "";
    for(int i = 0;i<c;i++){
        for(int j = 0;j<=maxr;j++){
            if(i>maxc && j==maxr) continue;
            ans+=grid[j][i];
        }
        ans+=' ';
    }
    return ans;
}

int main()
{
    string s;
    getline(cin, s);

    string result = encryption(s);

    cout << result << "\n";

    return 0;
}
