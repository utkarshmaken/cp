#include <bits/stdc++.h>
using namespace std;

void find(string &s, vector<string> &p, int n){
    int h1 = stoi(s.substr(0,2));
    int m1 = stoi(s.substr(3,2));
    int s1 = stoi(s.substr(6,2));
    int total = h1 * 3600 + m1 * 60 + s1;

    for(int i = 0; i < n; i++){
        string t = p[i];
        int h2 = stoi(t.substr(0,2));
        int m2 = stoi(t.substr(3,2));
        int s2 = stoi(t.substr(6,2));
        int total2 = h2 * 3600 + m2 * 60 + s2;

        if(total == total2)
            cout<<"now";
        else if(total - total2 < 60){
            if(total - total2 == 1)
                cout<<1<<" second ago";
            else
                cout<<total - total2<<" seconds ago";

        }
        else if(total - total2 < 3600){
            if(total - total2 < 120)
                cout<<1<<" minute ago";
            else
                cout<<(total - total2)/60<<" minutes ago";
        }
        else{
            if(total - total2 < 7200)
                cout<<1<<" hour ago";
            else
                cout<<(total - total2)/3600<<" hours ago";            
        }
        cout<<endl;
    }
}
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> p(n);
    for(int i = 0; i < n; i++)
        cin>>p[i];
    find(s,p,n);


}