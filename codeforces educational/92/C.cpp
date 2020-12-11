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
const int maxn = 2000000;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<int> count(10,0);
        for(auto x:s)
            count[x - '0']++;
        int maxi = 0;
        f(i,0,10)
            maxi = max(maxi,count[i]);
        f(i,0,10){
            f(j,0,10){
                if(i==j) continue;
                int search = i,c = 0;
                for(auto x:s){
                    if(x-'0' == search){
                        if(search==i) search = j;
                        else search = i;
                        c++;
                    }
                }
                if(search==j) c--;
                maxi = max(maxi,c);
            }
        }
        cout<<sz(s) - maxi<<endl;

    }

}