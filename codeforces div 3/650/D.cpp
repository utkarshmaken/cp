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
#define mp make_pair
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string s;
        cin>>s;
        int m;
        cin>>m;
        vector<int> b(m);
        f(i,0,m) cin>>b[i];
        vector<vector<int>> zero;

        while(true){
            vector<int> a;
            f(i,0,m)
                if(b[i] == 0)
                    a.pb(i);

            if(a.empty())
                break;
            zero.pb(a);
            f(i,0,m)
                if(b[i] == 0)
                    b[i] = INT_MAX;
                else
                    for(int j:a)
                        b[i]-=abs(i-j);
        }

        map<char,int> freq;
        for(char ch:s)
            freq[ch]+=1;
        auto it = freq.rbegin();
        auto it1 = zero.begin();
        string ans(m,'?');

        while(it1!=zero.end()){
            vector<int> a = *it1;
            if(it->se < sz(a))
                it++;
            else{
                for(int i:a)
                    ans[i] = it->fi;
                it++; it1++;
            }
           
        }
        cout<<ans<<endl;
        
    }

}