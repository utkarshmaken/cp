#include <bits/stdc++.h>
#define f(i,a,b) for(int i = a;i<b;i++)
#define rep(i,a,b) for(int i =a;i<=b;i++)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define all(con) con.begin(),con.end()
typedef long long ll;
using namespace std;
const int mod=1000000007;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        if(c-a > 0)
            cout<<1<<' ';
        else 
            cout<<-1<<' ';
  
        if(a*b <= c)
            cout<<-1<<endl;
        else
            cout<<b<<endl;
       
        
    }
}
