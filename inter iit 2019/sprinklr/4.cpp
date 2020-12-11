//FIND PRIME
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
const int maxn = 1000001;
vector<int> prime(maxn,1);
void find_prime(){
    int n = maxn-1;
    prime[1] = 0;
    for(int i = 2;i*i<=n;i++){
        if(prime[i] == 0) continue;
        for(int j = i*i;j<=n;j+=i)
            prime[j] = 0;
    }
    for(int i = 2;i<=n;i++) prime[i]+=prime[i-1];

}
bool poss(int &x, int &y, int &k, int &p){
    rep(z,x,y-k+1){
        if(prime[z+k-1] - prime[z-1] <p)
            return false;
    }
    return true;
}
int main(){
    int t;cin>>t;
    find_prime();
    while(t--){
        int x,y,p;
        cin>>x>>y>>p;
        int low = 1,high = y-x+1;
        if(!poss(x,y,high,p)){
            cout<<-1<<endl;
            continue;
        }
        while(low<high){
            int mid = (low+high)/2;
            if(poss(x,y,mid,p))
                high = mid;
            else
                low = mid+1;
        }
        cout<<low<<endl;
    }
}