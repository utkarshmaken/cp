//FRIENDSHIP DAY
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
struct info{
    string name;
    int d;
    set<int> left;
};

int main(){
    string ns;
    getline(cin,ns);
    int n = stoi(ns);
    map<string,int> shops;
    set<int> flowers;
    map<string,vector<pair<string,int>>> path;
    f(i,0,n){
        string s;
        getline(cin,s);
        s+=' ';
        int curr = 0,pos = s.find(' '), len = s.size();
        string shop = s.substr(curr,pos-curr);

        curr = ++pos;pos = s.find(' ',pos);
        int fl = stoi(s.substr(curr,pos-curr));

        curr = ++pos;
        shops[shop] = fl;
        flowers.insert(fl);
        if(pos == len) continue;
        pos = s.find(' ',pos);
        int dist = stoi(s.substr(curr,pos));

        vector<string> t;
        curr = ++pos;
        while(pos < len){
            pos = s.find(' ',pos);
            string temp = s.substr(curr,pos-curr);
            t.pb(temp);
            curr = ++pos;
        }
         
        for(auto &neighbor:t){
            path[shop].pb({neighbor,dist});
            path[neighbor].pb({shop,dist});
        }
    }

    string start,dest;
    string s;
    getline(cin,s);
    int pos = s.find(' ');
    start = s.substr(0,pos);
    dest = s.substr(pos+1);

    flowers.erase(shops[start]);
    if(flowers.find(shops[dest])!=flowers.end())
        flowers.erase(shops[dest]);
    
    auto compare = [&](info &a, info &b){
        return a.d > b.d;
    };
    priority_queue<info,vector<info>, decltype(compare) > pq(compare);
    struct info st;
    st.d = 0;st.name = start;st.left = flowers;
    pq.push(st);
    while(!pq.empty()){
        struct info s = pq.top();
        pq.pop();
        int d = s.d; string name = s.name; set<int> left = s.left;
        if(name == dest){
            cout<<d<<endl;
            break;
        }
        if(left.size() == 0){
            for(auto p:path[name]){
                if(p.first == dest){
                    struct info snew;
                    snew.d = d+p.se;snew.name = dest;snew.left = left;
                    pq.push(snew);
                }
            }
            continue;
        }
        for(auto p:path[name]){
            if(p.fi == dest) continue;
            if(left.find(shops[p.fi])!=left.end()){
                struct info snew;
                snew.d = d+p.se;
                snew.name = p.fi;
                snew.left = left;snew.left.erase(shops[p.fi]);
                pq.push(snew);
            }
        }
    }    
}