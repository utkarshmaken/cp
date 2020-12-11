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

vector<string> encryptedValue(vector<long> arr){
    int n = arr.size();
    vector<string> res;
    for(int i = 0;i<n;i++){
        long num = arr[i];
        if(num==1){
            res.push_back("1");
            continue;
        }
        vector<int> m(10,0);
        vector<int> p = {2,3,5,7};
        for(int q:p){
            while(num>0 && num%q==0){
                m[q]++;
                num/=q;
            }
        }
        if(num!=1){
            res.push_back("-1");
            continue;
        }

        m[8] = m[2]/3;m[2]%=3;
        m[9] = m[3]/2;m[3]%=2;

        if(m[3] == 1 && m[2]>=1){
            m[6]=1;m[3]=0;m[2]-=1;
        }
        if(m[2]==2){
            m[4] = 1;m[2] = 0;
        }
        string ans = "";
        for(int i = 2;i<=9;i++){
            string a(m[i],char('0'+i));
            ans+=a;
        }
        res.push_back(ans);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<long> arr(n);
    f(i,0,n) cin>>arr[i];
    vector<string> ans = encryptedValue(arr);
    cout<<endl;
    for(auto x:ans) cout<<x<<endl;
}