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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> freq(26,0);
        for(char ch:s) freq[ch - 'a']++;

        repd(ans,n,1){
            vector<int> cycles;
            vector<bool> visited(ans);
            f(i,0,n){
                if(visited[i])
                    continue;
                visited[i] = true;
                int j = (i+k)%ans;
                cycles.pb(1);
                while(!visited[j]){
                    visited[j] = true;
                    cycles.back()++;
                    j = (j+k)%ans;
                }
            }
            vector<int> temp(freq);
            sort(all(temp));
            sort(all(cycles));
            while(!cycles.empty()){
                if(temp.back() < cycles.back())
                    break;
                else{
                    temp.back()-=cycles.back();
                    cycles.pop_back();
                    sort(all(temp));
                }
            }
            
            if(cycles.empty()){
                cout<<ans<<endl;
                break;
            }
        }
    }
}