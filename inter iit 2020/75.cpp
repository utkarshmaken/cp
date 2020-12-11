//TEAM FORMATION
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
    int n;cin>>n;
    vector<int> score(n);
    f(i,0,n) cin>>score[i];
    int team,m;
    cin>>team>>m;
    auto compare = [&](pii &a, pii &b){
        if(a.fi == b.fi)
            return a.se > b.se;
        return a.fi < b.fi;
    };
    priority_queue<pii,vector<pii>,decltype(compare)> pq(compare);
    f(i,0,m){
        pq.push({score[i],i});
        if(n-1-i > m-1)
            pq.push({score[n-1-i],n-1-i});
    }

    int low = m-1,high = n-m;
    long ans = 0;
    while(low < high && team){
        pii a  = pq.top();
        pq.pop();
        ans+=a.fi;
        --team;
        if(a.se<=low){
            ++low;
            if(low<high)
                pq.push({score[low],low});
        }
        else if(a.se>=high){
            --high;
            if(low<high)
                pq.push({score[high],high});
        }  
    }
    while(team){
        ans+=pq.top().fi;
        pq.pop();
        --team;
    }
    cout<<ans<<endl;

}