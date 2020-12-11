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
    int t;
    cin>>t;
    string fixed = "abacaba";
    while(t--){
        int n;
        cin>>n;
        string s,temp;
        cin>>s;
        temp = s;

        size_t found = s.find(fixed);
        if(found!= string::npos){
            size_t found1 = s.find(fixed,found+1);
            if(found1 == string::npos){
                cout<<"Yes"<<endl;
                replace(all(s),'?','z');
                cout<<s<<endl;
            }
            else
                cout<<"No"<<endl;
            
            continue;
        }

       bool flag = false;
        f(i,0,n-6){
            int index = 0,j = i;
            while(index<7){
                if(s[j]==fixed[index]){
                    j++;index++;
                }
                else if(s[j]=='?'){
                    s[j] = fixed[index];
                    j++;index++;
                }
                else
                    break;
            }
            cout<<i<<' '<<j<<' '<<index<<endl;
            if(index==7)
                if((s.substr(j,4)!="caba") && (s.substr(j,6)!="bacaba"))
                    if((i-4<0 || s.substr(i-4,4)!="abac") && (i-6<0 || s.substr(i-6,6)!="abacab")){
                        flag = true;
                        break;
                    }
                
            
            s = temp;
        }

        if(flag){
            cout<<"Yes"<<endl;
            replace(all(s),'?','z');
            cout<<s<<endl;
        }
        else
            cout<<"No"<<endl;
        
    }

}
/////////////////////////////////////////////////////////////
/*#include <bits/stdc++.h>
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
    int t;
    cin>>t;
    string fixed = "abacaba";
    while(t--){
        int n;
        cin>>n;
        string s,temp;
        cin>>s;temp = s;
        size_t found = s.find(fixed);

        if(found!= string::npos){
            size_t found1 = s.find(fixed,found+1);
            if(found1 == string::npos){
                cout<<"Yes"<<endl;
                replace(all(s),'?','z');
                cout<<s<<endl;
            }
            else
                cout<<"No"<<endl;
            
            continue;
        }

        int index = 0,last = -1,lindex = -1;bool flag = false;
        f(i,0,n){
            if(s[i] == fixed[index])
                index++;

            else if(s[i] == '?'){
                last = i;
                s[i] = fixed[index++];
            }
            else{
                index  = 0;
                if(last!= -1 && s[last]!='a'){
                    s[last] = 'a';
                    i = last;
                    index++;
                }
            }

            if(index==7){
                if((i+4>n || s.substr(i+1,4)!="caba") && (i+6>n || s.substr(i+1,6)!="bacaba")){
                    flag = true;
                    break;
                }
                else{
                    int f = temp.substr(i-6,4).find('?');
                    if(f == string::npos){
                        s[last] = 'z';
                        index = 0;last = -1;
                    }
                    else{
                        s[i-6+f] = 'z';
                        flag = true;
                        break;
                    }
                }
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
            replace(all(s),'?','z');
            cout<<s<<endl;
        }
        else
            cout<<"No"<<endl;
        
    }

}*/