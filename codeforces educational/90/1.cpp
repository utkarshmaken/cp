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
#define mp make_pair
#define pb push_back
#define sz(x) (int) (x).size()
#define all(x) x.begin(),x.end()
using namespace std;
const int mod = 1000000007;
int area(vector<int> v, int n){
    int max_area= 0,i=0;
    stack<int> s; 
    v.pb(0);
    while(i<=n){
        if(s.empty() || v[s.top()]<=v[i])
            s.push(i++);
        else{
            int top = s.top();
            s.pop();
            int width = s.empty()?i:(i-s.top()-1);
            int area = v[top]*width;
            max_area = max(max_area,area);
         }
    }
     return max_area;
}
    
 int main(){   
    int r,c;
    cin>>r>>c;
    vector<vector<int>> matrix(r,vector<int>(c,0));
    f(i,0,r)
        f(j,0,c)
            cin>>matrix[i][j];
    vector<int> v;
    int ans = 0;
    f(i,0,r){
        f(j,0,c){
            if(i==0)
                v.pb(matrix[i][j]);
            else{
                if(matrix[i][j]==0)
                    v[j]=0;
                else
                    v[j]+=1;
            }
        }
        int temp = area(v,c);
        ans = max(ans,temp); 
    }
        cout<<ans<<endl;
 }
