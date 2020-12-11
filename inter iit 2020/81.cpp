//GCD MAX ROUND
//PLUTUS
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
const int maxn = 1e5;

int main(){
    int n;
    cin>>n;
    vector<int> arr(2*n);
    f(i,0,2*n) cin>>arr[i];
    
    priority_queue<vector<int>, vector<vector<int>>> pq;
    f(i,0,2*n)
        f(j,i+1,2*n)
            pq.push({__gcd(arr[i],arr[j]), i, j});
    
    set<int> rem;
    f(i,0,2*n)
        rem.insert(i);
    
    long ans = 0;
    repd(round,n,1){
        while(true){
            int i = pq.top()[1],j = pq.top()[2];
            if(rem.find(i)!=rem.end() && rem.find(j)!=rem.end())
                break;
            pq.pop();
        }

        ans+=(pq.top()[0])*round;
        rem.erase(pq.top()[1]);
        rem.erase(pq.top()[2]);
        pq.pop();
       
    }
    cout<<ans<<endl;
}