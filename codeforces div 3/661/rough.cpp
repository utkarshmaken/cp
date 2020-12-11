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
    int b,n;
    cin>>b>>n;
    vector<int> num(b);
    for(int i = 0;i<b;i++) cin>>num[i];
    int maxi = 0,c = 0,sum = 0;
    for(int i = 0;i<b;i++){
        if(num[i]==maxi) c++;
        else if(num[i] > maxi){
            maxi = num[i];
            c = 1;
        }
        sum+=num[i];
    }
    int count = maxi-1;
    int l = n - (c-1);
    int empty = count*l;
    int avail = sum - maxi*c;
    int nothing = max(0,empty - avail);
 
    cout<<sum + nothing<<endl;
}