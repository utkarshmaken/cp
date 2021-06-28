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
const int maxn = 2e5 + 1;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    f(i,0,n) cin >> arr[i];

    int sum = 0;
    f(i,0,n) sum += arr[i];

    if(sum & 1){
        cout << 0 << endl;
        return 0;
    }

   
    vector<bool> poss(maxn,false);
    poss[0]= true;poss[arr[0]] = true;
    f(i,1,n){
        vector<bool> nposs(maxn,false);
        f(j,0,maxn){
            if(poss[j]){
                nposs[j] = true;
                nposs[j + arr[i]] = true;
            }
        }
        poss = nposs;
    }

    if(!poss[sum/2]){
        cout << 0 << endl;
        return 0;
    }

    while(true){
        f(i,0,n){
            if(arr[i] & 1){
                cout << 1 << endl;
                cout << i+1 << endl;
                return 0;
            }
            arr[i] /= 2;
        }
    }
 
}