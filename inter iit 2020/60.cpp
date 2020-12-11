#include <bits/stdc++.h>
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
unordered_map<string,vector<string>> songsAndGenre( unordered_map<string,vector<string>> &users, unordered_map<string,vector<string>> &songs){
    unordered_map<string,string> genre;
    for(auto x:songs){
        for(auto y:x.second)
            genre[y] = x.first;
    }
    unordered_map<string,vector<string>> ans;
    for(auto user:users){
        unordered_map<string,int> freq;
        for(auto x:user.second)
            freq[genre[x]]++;
        int maxi = 0;
        for(auto it:freq) maxi = max(maxi,it.second);
        for(auto it:freq)
            if(it.second == maxi)
                ans[user.first].push_back(it.first);
    }
    return ans;
}

int main() {
    unordered_map<string,vector<string>> users;
    users["David"] = {"song1", "song2", "song3", "song4", "song8"};
    users["Emma"] = {"song5", "song6", "song7"};
    
    unordered_map<string,vector<string>> songs;
    songs["Rock"] = {"song1", "song3"};
    songs["Dubstep"] = {"song7"};
    songs["Techno"] = {"song2", "song4"};
    songs["Pop"] = {"song5", "song6"};
    songs["Jazz"] = {"song8", "song9"};

    auto result = songsAndGenre(users,songs);
    for(auto x: result)
    {
        cout<<x.first<<" : ";
        for(auto song:x.second)
        {
            cout<<song<<" ";
        }
        cout<<endl;
    }
    
    users.clear();
    songs.clear();
    
    users["David"] = {"song1", "song2"};
    users["Emma"] = {"song3", "song4"};
    
    result = songsAndGenre(users,songs);
    for(auto x: result)
    {
        cout<<x.first<<" : ";
        for(auto song:x.second)
        {
            cout<<song<<" ";
        }
        cout<<endl;
    }
    
}