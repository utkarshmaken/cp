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
        int n;
        scanf("%d",&n);
        vector<int> A(n),B(n);
        f(i,0,n) cin>>A[i];
        f(i,0,n) cin>>B[i];
        map<int,pii> m;
        f(i,0,n){
            m[A[i]].fi+=1;
            m[B[i]].se+=1;
        }
        ll mini = m.begin()->fi;
        ll cost  = 0;
        map<ll,ll> mx;
        map<ll,ll> my;
        for(auto it=m.begin();it!=m.end();it++){
            if((it->se.fi+it->se.se)&1){
                cost = -1;
                break;
            }
            if(it->se.fi>it->se.se)
                mx.insert({it->fi,(it->se.fi - it->se.se)/2});
                
            if(it->se.fi<it->se.se)
                my.insert({it->fi,(it->se.se - it->se.fi)/2});       
        }

        if(cost==-1)
            cout<<-1<<endl;
        else{    
            auto it1 = mx.begin();
            auto it2 = my.rbegin();
            while(it1!=mx.end() && it2!=my.rend()){
                if(it1->se > it2->se){
                    cost+=min(2*mini,min(it1->fi,it2->fi))*it2->se;
                    it1->se-=it2->se;
                    it2++;
                }
                else if(it1->se < it2->se){
                    cost+=min(2*mini,min(it1->fi,it2->fi))*it1->se;
                    it2->se-=it1->se;
                    it1++;
                }
                else{
                    cost+=min(2*mini,min(it1->fi,it2->fi))*it1->se;
                    it1++;it2++;
                }
           }
            cout<<cost<<endl;
        }
        

    }
}