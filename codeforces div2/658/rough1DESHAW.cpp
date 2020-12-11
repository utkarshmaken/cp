#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;

#define f(i,a,b) for(int i = a;i<b;i++)
#define rep(i,a,b) for(int i = a;i<=b;i++)
#define fd(i,a,b) for(int i = a;i>b;i--)
#define repd(i,a,b) for(int i = a;i>=b;i--)

#define pii pair<int,int>
#define pll pair<ll,ll>

#define fi first
#define se second
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;
vector<int> getMaximumWin(string winners,vector<int> st, vector<int> en){
    int n = winners.size();
    vector<vector<int>> arr(n+1,vector<int>(26,0));
    for(int i = 1;i<=n;i++){
        arr[i] = arr[i-1];
        int w = winners[i-1]-'a';
        arr[i][w]++;
    }

    int q = st.size();
    vector<int> ans;
    int s,e,maxi;
    for(int i = 0;i<q;i++){
        s = st[i];e = en[i];
        maxi = 1;
        for(int j = 0;j<26;j++)
            maxi = max(maxi,arr[e][j] - arr[s-1][j]);
        ans.push_back(maxi);
    }

    return ans;

}
int main(){
    string winners;
    cin>>winners;
    int q;
    cin>>q;
    vector<int> st(q),en(q);
    f(i,0,q) cin>>st[i];
    cin>>q;
    f(i,0,q) cin>>en[i];
    vector<int> ans = getMaximumWin(winners,st,en);
    cout<<endl;
    for(auto x:ans) cout<<x<<endl;

}
    