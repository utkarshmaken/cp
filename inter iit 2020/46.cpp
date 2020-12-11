//VERSION COMPARATOR
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
bool separate(char c){
    if(c == '.' || c == ',' || c == ':' || c == '-')
        return true;
    return false;
}
void calc(vector<int> &v, string s){
    string n = "";
    f(i,0,sz(s)){
        if(!separate(s[i]))
            n+=s[i];
        else{
            v.push_back(stoi(n));
            n = "";
        }
    }
}
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int l1 = s1.find(' '),l2 =s2.find(' ');
    string prefix1 = s1.substr(0,l1);
    string prefix2 = s2.substr(0,l2);
    if(prefix1!=prefix2){
        cout<<"MisMatch"<<endl;
        return 0;
    }
    s1 = s1.substr(l1+1);s1+='.';
    s2 = s2.substr(l2+1);s2+='.';
    vector<int> v1,v2;
    calc(v1,s1);
    calc(v2,s2);
    int i = 0;
    while(i<sz(v1) && i<sz(v2) && v1[i]==v2[i])
        ++i;
    if(sz(v1) == sz(v2)){
        if(i==sz(v1))
            cout<<"Same"<<endl;
        else
        {
            if(v1[i] > v2[i])
                cout<<"Higher"<<endl;
            else
                cout<<"Lower"<<endl;
        }
    }
    else{
        if(i == sz(v1))
            cout<<"Lower"<<endl;
        else if(i == sz(v2))
            cout<<"Higher"<<endl;
        else{
            if(v1[i] > v2[i])
                cout<<"Higher"<<endl;
            else
                cout<<"Lower"<<endl;
        }
    }
}