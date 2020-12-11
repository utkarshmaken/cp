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
const int maxn = 100001;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s;cin>>s;
        int zer = 0,one = 0,ques = 0;
        f(i,0,k){
            if(s[i]=='0') zer++;
            else if(s[i]=='1') one++;
            else ques++;
        }
        if(zer>k/2 || one>k/2){
            cout<<"NO"<<endl;
            continue;
        }
        int zq = k/2-zer,oq = k/2-one;
        bool flag = true;
        f(i,k,n){
            if(s[i]!='?'){
                if(s[i-k]=='?'){
                    s[i-k] = s[i];
                    if(s[i]=='0') zq--;
                    else oq--;
                    if(oq<0 ||zq<0){
                        flag = false;break;
                    }
                }
                else if(s[i-k]!=s[i]){
                    flag = false;
                    break;
                }
            }
            else{
                if(s[i-k]!='?')
                    s[i] = s[i-k];
                else
                    continue;
            }

        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }

}