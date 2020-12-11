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

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        multiset<int> m;
        f(i,0,n) {
            cin>>v[i];
            m.insert(v[i]);
        }
        int sans = 0,start = 0,end = n-1;
        while(!m.empty()){
            int small = *m.begin();
            m.erase(m.begin());
            if(v[end] == small)
                end--;
            else if(v[start] == small)
                start++;
            else{
                while(v[start]!=small){
                    m.erase(m.find(v[start]));
                    start++;
                }
                sans = start;
                start++;
            }

        }
        cout<<sans<<endl;

    }

}