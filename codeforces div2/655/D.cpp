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
        int n;
        cin>>n;
        vector<ll> v(n);
        ll sum = 0;
        f(i,0,n){
            cin>>v[i];
            sum+=v[i];
        }
        auto compare = [&](pll a,pll b){
                return a.fi>b.fi;
        };
        priority_queue<pll,vector<pll>,decltype(compare)> pq(compare);
        f(i,0,n)
            pq.push({v[i],i});
        set<int> s;
        f(i,0,n)
            s.insert(i);
        while(s.size()!=1){
            pll p = pq.top();
            pq.pop();
            ll val = p.fi,index = p.se;
            if(s.find(index)!=s.end()){
                sum-=val;
                auto it = s.find(index);
                int i1,i2;
                auto it1 = it;
                i1 = (++it1 == s.end())?*s.begin():*it1;
                it1 = it;
                i2 = (it1 == s.begin())?*(--s.end()):*(--it1);
                s.erase(i1);
                s.erase(i2);
                pq.push({v[i1] + v[i2],index});
                v[index] = v[i1] + v[i2];
                cout<<i1<<' '<<index<<' '<<i2<<endl;
            }
        }
        while(!pq.size()==1)
            pq.pop();
        cout<<pq.top().fi<<endl;
        cout<<sum<<endl;
        

}