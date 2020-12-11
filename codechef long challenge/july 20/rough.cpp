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
int search(vector<int> v, int val,int start,int end){
    int mid;int n = end;
    while(start<=end){
        mid = (start+end)/2;
        if(v[mid]>val){
            end = mid-1;
            if(end>=start && v[end]<=val)
                return mid;
        }
        else{
            start = mid+1;
            if(start<=n && v[start]>val)
                return mid+1;
        }
    }
    return start;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> v(n);
        f(i,0,n) cin>>v[i];
        sort(all(v));
        vector<int> max_possible(v);
        map<int,int> s;
        ll days = 0;
        int i = search(v,x,0,n-1);
        f(j,0,i)
            s.insert(mp(v[j],j));
        int dec1,dec2;
        while(i!=n){
            if(s.empty())
                dec1 = INT_MIN;
            else
                dec1 = min(2*s.rbegin()->fi,max_possible[s.rbegin()->se]);

            dec2 = min(2*v[i],max_possible[i]) - min(2*(v[i]-x),max_possible[i]);

            if(dec2>dec1){
                v[i] = min(2*(v[i]-x),max_possible[i]);
                x = 2*x;
            }
            else{
                auto it = s.end();
                it--;
                v[it->se] = 0;
                x = 2*it->fi;
                s.erase(it);
            }
            
            days++;
            cout<<days<<' '<<x<<' '<<v[i]<<endl;
            int inew = search(v,x,i,n-1);
            f(j,i,inew)
                s.insert(mp(v[j],j));
            i = inew;
        }

        for(auto it:s)
            days++;
        cout<<days<<endl;
    }
}