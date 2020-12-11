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
const int maxn = 200000;
int main(){
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    map<int,int> dp;
    f(i,0,n)
        scanf("%d", &a[i]);
    
    int maxi = 0,lst;
    f(i,0,n){
        dp[a[i]] = max(dp[a[i]],dp[a[i]-1] + 1);
        if(dp[a[i]]>maxi){
            maxi = dp[a[i]];
            lst = a[i];
        }
    }
    cout<<maxi<<endl;
    stack<int> ans;
    repd(i,n-1,0){
        if(a[i]==lst){
            ans.push(i);
            lst--;
        }
    }
    while(!ans.empty()){
        printf("%d ", ans.top()+1);
        ans.pop();
    }

}

//O(n^2) dp solution...gives TLE
/*int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    vector<int> dp(n,0);
    vector<int> prev(n,0);
    dp[0] = 1;
    int maxi = 1,index = 0;
    f(i,1,n){
        int l = 1,ind = i;
        repd(j,i-1,0)
            if(a[j] == a[i]-1){
                l = dp[j] + 1;
                ind = j;
                break;
            }
        dp[i] = l;
        prev[i] = ind;
        if(dp[i]>maxi){
            maxi = dp[i];
            index = i;
        }
    }
    cout<<maxi<<endl;
    stack<int> ans;
    while(prev[index]!=index){
        ans.push(index);
        index = prev[index];
    }
    ans.push(index);
    while(!ans.empty()){
        cout<<ans.top()+1<<' ';
        ans.pop();
    }
}*/