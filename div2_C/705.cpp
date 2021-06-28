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
#define endl '\n'
using namespace std;
const int mod = 1000000007;
const int maxn = 2e5;

bool beaut(string s, int n, int k){
    int count[26] = {0};
    f(i,0,n) ++count[s[i]-'a'];
    f(i,0,26) if(count[i] % k != 0) return false;
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(n % k != 0){
            cout<< -1 << endl;
            continue;
        }
        if(k == 1 || beaut(s,n,k)){
            cout<< s <<endl;
            continue;
        }

        map<char,int> m,needed;
        int sum = 0;
        f(i,0,n-1) ++m[s[i]];
        for(auto it:m){
            if(it.se % k != 0){
                needed[it.fi] = k - it.se % k;
                sum += k - it.se % k;
            }
        }

        string ans = "";
        repd(i,n-2,0){
            int rem = n-1-i;
            auto it = needed.upper_bound(s[i+1]);
            if((rem-sum) % k == 0 && ( (rem > sum && s[i+1] != 'z') || (rem >= sum && it != needed.end()) ) ){
                ans += s.substr(0,i+1);
                if(needed.find(s[i+1]+1) != needed.end()){
                    ans += (s[i+1] + 1);
                    --needed[s[i+1]+1];
                }
                else if(rem-sum > 0){
                    ans += (s[i+1] + 1);
                    needed[s[i+1]+1] = k-1;
                    sum += k-1;
                    rem--;
                } 
                else{
                    ans += it->fi;
                    --needed[it->fi];
                }
                if(rem-sum > 0) ans += string(rem-sum,'a');
                cout<<ans<<endl;
                for(auto it:needed)
                    if(it.se)
                        ans += string(it.se,it.fi);
                break;
            }
            else{
                --m[s[i]];
                int temp = needed[s[i]], curr = m[s[i]];
                if(curr % k == 0) needed.erase(s[i]);
                else  needed[s[i]] = k - curr % k;
                sum  = sum - temp + (needed.find(s[i])!= needed.end() ? needed[s[i]] : 0);
            }

        }
        if(ans.empty()) ans = string(1,s[0]+1) + string(n-k,'a') + string(k-1,s[0]+1);
        cout<<ans<<endl;
    }

}