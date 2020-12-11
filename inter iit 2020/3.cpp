//MOVIE TICKET RESERVATION APPLICATION
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
const int maxn = 2e5;
class Screen{
public:
    int row,ts;
    vector<int> aisle;
    vector<vector<int>> status;
    Screen(int r, int t, vector<int> a){
        row = r;
        ts = t;
        aisle = a;
        status = vector<vector<int>>(r+1,vector<int>(t+1,0));
    }
    string reserve(int r, vector<int> &seats){
        for(auto &x:seats){
            if(status[r][x] == 1) return "failure";
            status[r][x] = 1;
        }
        return "Success";
    }
    vector<int> get_unres(int r){
        vector<int> ans;
        for(int i = 1;i<=ts;i++)
            if(status[r][i] == 0)
                ans.pb(i);
        return ans;
    }
    pair<char,vector<int>> get_suggestion(int n, int r, int pref){
        if(pref-n+1>=1){
            bool poss = true;
            for(int j = pref-n+1;j<=pref;++j)
                if(status[r][j] == 1){
                    poss = false;
                    break;
                }
            if(poss){
                vector<int> seats(n);
                int start = pref - n+1;
                for(int i = 0;i<n;i++)
                    seats[i] = start++;
                return make_pair('y',seats);
            }
        }
        if(pref+n-1<=ts){
            bool poss = true;
            for(int j = pref;j<=pref+n-1;++j)
                if(status[r][j] == 1){
                    poss = false;
                    break;
                }
            if(poss){
                vector<int> seats(n);
                int start = pref;
                for(int i = 0;i<n;i++)
                    seats[i] = start++;
                return make_pair('y',seats);
            }
        }
        return make_pair('n',vector<int>());
    }
};

int main(){
    int q;
    cin>>q;
    string s;
    vector<Screen> scr;
    map<string, int> m;
    int idx = 0;
    f(i,0,q){
        getline(cin,s);
        s = s+' ';
        int n = s.size();
        int curr = 0,pos = s.find(" ");
        string query = s.substr(curr,pos - curr);
        curr = ++pos;
        /////////////////////////////////////////
        if(query == "add-screen"){
            pos = s.find(" ",pos);
            string name = s.substr(curr,pos - curr);
            curr = ++pos;
            pos = s.find(" ",pos);
            int r = stoi(s.substr(curr,pos - curr));
            curr = ++pos;
            pos = s.find(" ",pos);
            int t = stoi(s.substr(curr,pos - curr));
            curr = ++pos;
            vector<int> aisle;
            while(curr<n){
                pos = s.find(" ",pos);
                int a = stoi(s.substr(curr,pos - curr));
                aisle.pb(a);
                curr = ++pos;
            }
            Screen si(r,t,aisle);
            scr.pb(si);
            m[name] = idx++;
            cout<<"Success"<<endl;
        }
        ////////////////////////////////////////////////
        else if(query == "reserve-seat"){
            pos = s.find(" ",pos);
            string name = s.substr(curr,pos - curr);
            curr = ++pos;
            pos = s.find(" ",pos);
            int r = stoi(s.substr(curr,pos - curr));
            curr = ++pos;
            vector<int> seats;
            while(curr<n){
                pos = s.find(" ",pos);
                int a = stoi(s.substr(curr,pos - curr));
                seats.pb(a);
                curr = ++pos;
            }
            int i = m[name];
            string response = scr[i].reserve(r,seats);
            cout<<response<<endl;
            
        }
        //////////////////////////////////////////////////
        else if(query == "get-unreserved-seats"){
            pos = s.find(" ",pos);
            string name = s.substr(curr,pos - curr);
            curr = ++pos;
            pos = s.find(" ",pos);
            int r = stoi(s.substr(curr,pos - curr));
            curr = ++pos;
            int i = m[name];
            vector<int> unreserved = scr[i].get_unres(r);
            int len = unreserved.size();
            for(int j = 0;j<len;j++){
                if(j==len-1) cout<<unreserved[j]<<endl;
                else cout<<unreserved[j]<<' ';
            }  
        }
        /////////////////////////////////////////////////////
        else if(query == "suggest-contiguous-seats"){
            pos = s.find(" ",pos);
            string name = s.substr(curr,pos - curr);
            curr = ++pos;
            pos = s.find(" ",pos);
            int num_seats = stoi(s.substr(curr,pos - curr));
            curr = ++pos;
            pos = s.find(" ",pos);
            int r = stoi(s.substr(curr,pos - curr));
            curr = ++pos;
            pos = s.find(" ",pos);
            int preference = stoi(s.substr(curr,pos - curr));
            int i = m[name];
            pair<char,vector<int>> response = scr[i].get_suggestion(num_seats,r,preference);
            if(response.first == 'n') cout<<"none"<<endl;
            else{
                int len = response.second.size();
                for(int j = 0;j<len;j++){
                    if(j==len-1) cout<<response.second[j]<<endl;
                    else cout<<response.second[j]<<' ';
                }
            }
        }
    }
}