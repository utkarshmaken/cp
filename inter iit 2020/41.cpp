//HEAD TAIL PERCENTAGE
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

int main(){
    int n,k;
    cin>>n>>k;
    int heads = 0,turn;
    rep(i,1,n){
        string ch;
        cin>>ch;
        if(heads < k){
            if(ch == "H") ++heads;
            if(heads == k) turn = i;
        }
    }
    if(heads == k){
        int h = round((100*k)/turn);
        cout<<h<<endl;
        cout<<100-h<<endl;
    }
    else{
        int h = round((100*heads)/n);
        cout<<h<<endl;
        cout<<100-h<<endl;
    }

}