//NO OF DISTICNT SUBSTRINGS OF A STRING
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
const ll mod = 1000000007;
const int maxn = 1e5;
struct suffix{
    int index;
    int rank[2];
};
bool compare(struct suffix &a, struct suffix &b){
    if(a.rank[0] == b.rank[0])
        return a.rank[1] < b.rank[1];
    return a.rank[0] < b.rank[0];
}
vector<int> build(string s, int n){
    struct suffix suffixes[n];
    f(i,0,n){
        suffixes[i].index = i;
        suffixes[i].rank[0] = s[i] - 'a';
        suffixes[i].rank[1] = (i+1<n?(s[i+1]-'a'):-1);
    }
    sort(suffixes,suffixes+n,compare);

    int ind[n];
    for(int k = 4;k<2*n;k*=2){
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
        f(i,1,n){
            if(suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1]){
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else{
                prev_rank = suffixes[i].rank[0]; 
                suffixes[i].rank[0] = ++rank; 
            }
            ind[suffixes[i].index] = i;
        }
        f(i,0,n){
            
        }

    }

    ve

}
int main(){
    string s;
    cin>>s;
    int n = sz(s);
    vector<int> suffix_arr = build(s,n);

}