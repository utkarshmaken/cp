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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string curr(51,'a');
        int x;
        f(i,0,n){
            cin>>x;
            cout<<curr<<endl;
            if(curr[x] == 'a')
                curr[x] = 'b';
            else
                curr[x] = 'a';
        }
        cout<<curr<<endl;

        /*string curr(max(a[0],1),'a');
        cout<<curr<<endl;
        char ch = 'b';
        curr = curr.substr(0,a[0]) + ch;

        f(i,1,n){
            if(a[i] < sz(curr)){
                cout<<curr<<endl;
                ch = curr[a[i]] + 1;
                if(ch>'z') ch = 'a';
                curr =  curr.substr(0,a[i]) + ch;
            }
            else{
                string temp(a[i]-sz(curr),ch);
                curr+= temp;
                cout<<curr<<endl;
                ch = curr.back() + 1;
                if(ch>'z') ch = 'a';
                curr+=ch;
            }
        }
        cout<<curr<<endl;*/
    }

}