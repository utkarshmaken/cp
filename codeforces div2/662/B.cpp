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
const int maxn = 200000;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    f(i,0,n) cin>>a[i];
    int q;cin>>q;
    vector<int> change(q);
    f(i,0,q){
        char t;cin>>t;
        cin>>change[i];
        if(t=='-') change[i]*=-1;
    }
    map<int,int> four,two,total;
    f(i,0,n){
        total[a[i]]++;
        if(total[a[i]]>=2) two[a[i]] = total[a[i]];
        if(total[a[i]]>=4) four[a[i]] = total[a[i]];
    }
    f(i,0,q){
        if(change[i] > 0){
            total[change[i]]++;
            if(total[change[i]]>=2) two[change[i]] = total[change[i]];
            if(total[change[i]]>=4) four[change[i]] = total[change[i]];

        }
        else{
            change[i]*=-1;
            total[change[i]]--;
            if(four.find(change[i])!=four.end()){
                four[change[i]]--;
                if(four[change[i]]<4) four.erase(change[i]);
            }
            if(two.find(change[i])!=two.end()){
                two[change[i]]--;
                if(two[change[i]] < 2) two.erase(change[i]);
            }
        }
        if(four.empty()){
            cout<<"NO"<<endl;
            continue;
        }
        if(sz(four)>=2){
            cout<<"YES"<<endl;
            continue;
        }
        auto it = four.begin();
        int num = it->fi,freq = it->se;
        if(freq>=8){
            cout<<"YES"<<endl;
            continue;
        }
        if(freq>=6 && sz(two)>=2){
            cout<<"YES"<<endl;
            continue;
        }
        if(sz(two)>=3){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;

    }

}